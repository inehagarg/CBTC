#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char date[11];  // format: YYYY-MM-DD
    char category[MAX_CATEGORY_LENGTH];
    double amount;
    char description[100];
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }

    Expense e;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%lf", &e.amount);
    printf("Enter description: ");
    scanf(" %[^\n]s", e.description);

    expenses[expense_count++] = e;
    printf("Expense added successfully!\n");
}

void display_expenses() {
    printf("\nRecorded Expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Date: %s, Category: %s, Amount: %.2f, Description: %s\n",
               expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].description);
    }
}

void generate_report() {
    double category_totals[MAX_EXPENSES] = {0};
    char categories[MAX_EXPENSES][MAX_CATEGORY_LENGTH];
    int category_count = 0;

    for (int i = 0; i < expense_count; i++) {
        int found = 0;
        for (int j = 0; j < category_count; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                category_totals[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[category_count], expenses[i].category);
            category_totals[category_count] = expenses[i].amount;
            category_count++;
        }
    }

    printf("\nExpense Report by Category:\n");
    for (int i = 0; i < category_count; i++) {
        printf("Category: %s, Total Amount: %.2f\n", categories[i], category_totals[i]);
    }
}

void show_summary() {
    double total_amount = 0;
    double highest_amount = 0;
    double lowest_amount = expenses[0].amount;
    char highest_category[MAX_CATEGORY_LENGTH], lowest_category[MAX_CATEGORY_LENGTH];

    for (int i = 0; i < expense_count; i++) {
        total_amount += expenses[i].amount;
        if (expenses[i].amount > highest_amount) {
            highest_amount = expenses[i].amount;
            strcpy(highest_category, expenses[i].category);
        }
        if (expenses[i].amount < lowest_amount) {
            lowest_amount = expenses[i].amount;
            strcpy(lowest_category, expenses[i].category);
        }
    }

    double average_amount = total_amount / expense_count;
    printf("\nSummary:\n");
    printf("Total Expenses: %.2f\n", total_amount);
    printf("Average Expense: %.2f\n", average_amount);
    printf("Highest Expense: %.2f (Category: %s)\n", highest_amount, highest_category);
    printf("Lowest Expense: %.2f (Category: %s)\n", lowest_amount, lowest_category);
}

int main() {
    int choice;
    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Generate Report\n");
        printf("4. Show Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                generate_report();
                break;
            case 4:
                show_summary();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
