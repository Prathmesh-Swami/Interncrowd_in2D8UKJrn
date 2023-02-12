#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRIENDS 50
#define NAME_LEN 20
#define Mail_Len 30

struct Date {
    int day;
    int month;
    int year;
};

struct Friend {
    char name[NAME_LEN];
    struct Date birthday;
    char email[Mail_Len];
};

struct Friend friends[MAX_FRIENDS];
struct Friend mail[Mail_Len];
int numFriends = 0;
int i = 0;

void addFriend() {
    if (numFriends == MAX_FRIENDS) {
        printf("Error: too many friends in the list.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", friends[numFriends].name);
    printf("Enter birthday (dd mm yyyy): ");
    scanf("%d %d %d", &friends[numFriends].birthday.day, &friends[numFriends].birthday.month, &friends[numFriends].birthday.year);
    printf("Enter Email: ");
    scanf("%s",mail[i].email);

    numFriends++;
    i++;
}

void editFriend() {
    char name[NAME_LEN];
    printf("Enter name: ");
    scanf("%s", name);

    int index = -1,j=-1;
    for (int i = 0; i < numFriends; i++) {
        if (strcmp(friends[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: friend not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", friends[index].name);

    printf("Enter new birthday (dd mm yyyy): ");
    scanf("%d %d %d", &friends[index].birthday.day, &friends[index].birthday.month, &friends[index].birthday.year);
    
    printf("Enter new Email: ");
    scanf("%s",mail[j].email);
}

void displayFriends() {
    for (int i = 0; i < numFriends; i++) {
        printf("\n===================================\n%s\n%02d/%02d/%04d\n%s\n===================================\n", friends[i].name, friends[i].birthday.day, friends[i].birthday.month, friends[i].birthday.year,mail[i].email);
    }
}

void displayMonthlyBirthdays() {
    int month;
    printf("Enter month: ");
    scanf("%d", &month);

    printf("Birthdays in month %d:\n\n", month);
    for (int i = 0; i < numFriends; i++) {
        if (friends[i].birthday.month == month) {
            printf("===================================\n%s\n%02d/%02d/%04d\n%s\n===================================\n", friends[i].name, friends[i].birthday.day, friends[i].birthday.month, friends[i].birthday.year,mail[i].email);
        }
    }
}

void searchFriend() {
    char name[NAME_LEN];
    printf("Enter name: ");
    scanf("%s", name);

    int index = -1,j=-1;
    for (int i = 0; i < numFriends; i++) {
        if (strcmp(friends[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: friend not found.\n");
        return;
    }

    printf("\n===================================\n%s\n%02d/%02d/%04d\n%s\n===================================\n", friends[index].name, friends[index].birthday.day, friends[index].birthday.month, friends[index].birthday.year,mail[j].email);
}

int main() {
    while (true) {
        printf("\n1. Add friend\n");
        printf("2. Edit friend\n");
        printf("3. Display friends\n");
        printf("4. Display monthly birthdays\n");
        printf("5. Search friend\n");
        printf("6. Exit\n");

        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFriend();
                break;
            case 2:
                editFriend();
                break;
            case 3:
                displayFriends();
                break;
            case 4:
                displayMonthlyBirthdays();
                break;
            case 5:
                searchFriend();
                break;
            case 6:
		printf("\nBye!!!\n");
                return 0;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    }

    return 0;
}

