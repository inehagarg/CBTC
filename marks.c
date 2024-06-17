#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

typedef struct {
    char name[50];
    float scores[MAX_SUBJECTS];
    float average;
    float highest;
    float lowest;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;
int subjectCount = 0;

void inputStudentData() {
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);
    printf("Enter the number of subjects: ");
    scanf("%d", &subjectCount);

    for (int i = 0; i < studentCount; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter scores for %s:\n", students[i].name);
        for (int j = 0; j < subjectCount; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
        }
    }
}

void calculateStatistics() {
    for (int i = 0; i < studentCount; i++) {
        float sum = 0.0;
        float highest = students[i].scores[0];
        float lowest = students[i].scores[0];

        for (int j = 0; j < subjectCount; j++) {
            sum += students[i].scores[j];
            if (students[i].scores[j] > highest) {
                highest = students[i].scores[j];
            }
            if (students[i].scores[j] < lowest) {
                lowest = students[i].scores[j];
            }
        }

        students[i].average = sum / subjectCount;
        students[i].highest = highest;
        students[i].lowest = lowest;
    }
}

void displaySummary() {
    for (int i = 0; i < studentCount; i++) {
        printf("\nSummary for %s:\n", students[i].name);
        printf("  Average Score: %.2f\n", students[i].average);
        printf("  Highest Score: %.2f\n", students[i].highest);
        printf("  Lowest Score: %.2f\n", students[i].lowest);
    }
}

int main() {
    inputStudentData();
    calculateStatistics();
    displaySummary();

    return 0;
}