#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//test comment

struct user {
    char userName[50];
    char password[50];
    char phone[50];
    char topSecret[50];
};

struct verification {
    char _phone[50];
    char _password[50];
    char _topSecret[50];
} ver1;

int main() {
    struct user usr;
    FILE *fp;
    char fileName[50];
    int opt;
    int _opt;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice: ");
    scanf("%d", &opt);

    if (opt == 1) {
        system("cls");
        printf("Enter your User Name: ");
        scanf("%s", usr.userName);

        printf("Enter a password: ");
        scanf("%s", usr.password);

        printf("Enter a Phone Number: ");
        scanf("%s", usr.phone);

        printf("Enter your top secret info: ");
        scanf("%s", usr.topSecret);

        strcpy(fileName, usr.phone);
        fp = fopen(strcat(fileName, ".elf"), "w");

        if (fp != NULL) {
            fwrite(&usr, sizeof(struct user), 1, fp);
            printf("\n\nAccount Successfully Registered");
        } else {
            printf("\n\nSomething went wrong!");
        }

        fclose(fp);
    } else if (opt == 2) {
        system("cls");
        printf("Enter your Phone number: ");
        scanf("%s", ver1._phone);

        strcat(ver1._phone, ".elf");
        fp = fopen(ver1._phone, "r");

        if (fp == NULL) {
            printf("User Not found. Please register\n");
            exit(EXIT_FAILURE);
        } else {
            fread(&usr, sizeof(struct user), 1, fp);

        printf("Enter your password: ");
        scanf("%s", ver1._password);

        if (strcmp(ver1._password, usr.password) == 0) {
            printf("\nLogin successful!");
            printf("\nWelcome Back %s\n", usr.userName);
            printf("Your Top Secret: %s\n", usr.topSecret);

            printf("\n\nEnter 1 to edit your top secret OR enter 0 to exit");
            scanf("%d", &_opt);

            if (_opt == 1) {
                printf("Enter your new top Secret: ");
                scanf("%s", ver1._topSecret);

                strcpy(usr.topSecret, ver1._topSecret);
                fp = fopen(ver1._phone, "w");

                if (fp != NULL) {
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    printf("\nTop Secret edited Successfully!");
                } else {
                    printf("\nSomething went wrong while editing Top Secret!");
                }

                fclose(fp);
            } else if (_opt == 0) {
                exit(EXIT_SUCCESS);
            }
        }
         else {
            printf("\nIncorrect password. Login failed.\n");
        }

        fclose(fp);
}
} else {
        printf("\nInvalid choice.\n");
    }

    return 0;
}
