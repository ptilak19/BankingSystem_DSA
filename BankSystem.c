#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNum;
    char name[100];
    float balance;
    int aadharNum;
    char pan[20];
    struct Account* next;
};

struct Account* head = NULL;
int accountCount = 0;

void createAccount();
void viewBalance();
void depositAmount();
void withdrawAmount();

int main() {
    int choice;
    printf("Welcome to SDN Bank!!\n\n");
    
    while (1) {
        printf("How may I help you?\n");
        printf(" 1. Create Account\n 2. View Balance\n 3. Deposit Amount\n 4. Withdraw Amount\n 5. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewBalance(); break;
            case 3: depositAmount(); break;
            case 4: withdrawAmount(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}

void createAccount() {
    struct Account* newacc = (struct Account*)malloc(sizeof(struct Account));
    if (newacc == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    newacc->accountNum = ++accountCount;
    printf("Enter Account Holder Name: ");
    scanf("%s", newacc->name);
    
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &newacc->balance);
    
    printf("Enter Aadhar Card Number: ");
    scanf("%d", &newacc->aadharNum);
    
    printf("Enter Pan Card Number: ");
    scanf("%s", newacc->pan);
    
    newacc->next = head;
    head = newacc;
    
    printf("Account Creation Successful! Your Account Number: %d\n\n", newacc->accountNum);
}

void viewBalance() {
    int accountNumber;
    struct Account* temp = head;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    while (temp != NULL) {
        if (temp->accountNum == accountNumber) {
            printf("Account holder: %s\n", temp->name);
            printf("Current balance: %.2f\n\n", temp->balance);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n\n");
}

void depositAmount() {
    int accountNumber;
    float depAmount;
    struct Account* temp = head;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    while (temp != NULL) {
        if (temp->accountNum == accountNumber) {
            printf("Enter deposit amount: ");
            scanf("%f", &depAmount);
            temp->balance += depAmount;
            printf("Deposit successful! Current balance: %.2f\n\n", temp->balance);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n\n");
}

void withdrawAmount() {
    int accountNumber;
    float withAmount;
    struct Account* temp = head;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    while (temp != NULL) {
        if (temp->accountNum == accountNumber) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &withAmount);
            if (temp->balance < withAmount) {
                printf("Insufficient balance!\n\n");
            } else {
                temp->balance -= withAmount;
                printf("Withdrawal successful! Current balance: %.2f\n\n", temp->balance);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n\n");
}
