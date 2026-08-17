#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry{
    int serial;
    char title[200];
    char content[5000];
};

struct users{
    char name[100];
    char user[30];
    char pass[20];
    char copass[20];
};

struct entry addentry[10000];
struct users numberofUsers[10000];

int count = 0;
int userCount = 0;


void loadUsers(){
    FILE *fp = fopen("users.dat", "rb");
    if (fp == NULL) return;
    userCount = fread(numberofUsers, sizeof(struct users), 10000, fp);
    fclose(fp);
}

void saveUsers(){
    FILE *fp = fopen("users.dat", "wb");
    if (fp == NULL) return;
    fwrite(numberofUsers, sizeof(struct users), userCount, fp);
    fclose(fp);
}

void loadEntries(){
    FILE *fp = fopen("entries.dat", "rb");
    if (fp == NULL) return;
    count = fread(addentry, sizeof(struct entry), 10000, fp);
    fclose(fp);
}

void saveEntries(){
    FILE *fp = fopen("entries.dat", "wb");
    if (fp == NULL) return;
    fwrite(addentry, sizeof(struct entry), count, fp);
    fclose(fp);
}


void trimNewline(char *str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void diaryMenu();
void logIn();
void regist();

void logIn(){
    char user[30];
    char pass[20];
    int authenticated = 0;

    system("cls");
    printf("=============================\n");
    printf("           LOGIN\n");
    printf("=============================\n\n\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    for (int i = 0; i < userCount; i++){
        if (strcmp(user, numberofUsers[i].user) == 0 && strcmp(pass, numberofUsers[i].pass) == 0) {
            authenticated = 1;
            break;
        }
    }

    system("cls");
    if (authenticated) {
        printf("=========================================\n");
        printf("             LOGIN SUCCESSFUL\n");
        printf("=========================================\n");

        printf("\n\nPress Enter to Continue...\n\n");
        getchar();
        getchar();
        diaryMenu();
    } else {
        printf("Invalid Username or Password.");
        printf("\n\nPress Enter to Continue...\n\n");
        getchar();
        getchar();
    }
}

void diaryMenu(){
    int choice = 0;

    while(choice!=6){
        system("cls");

        printf("=========================================\n");
        printf("    PERSONAL DIARY MANAGEMENT SYSTEM\n");
        printf("=========================================\n\n\n");

        printf("1. Add Entry\n");
        printf("2. View My Entries\n");
        printf("3. Search My Entry by Serial\n");
        printf("4. Edit An Entry\n");
        printf("5. Delete Entry\n");
        printf("6. Log out\n");

        printf("\nEnter Your Choice(1-6): ");
        scanf("%d", &choice);

        if(choice==1){
            system("cls");

            printf("=========================================\n");
            printf("               ADD NEW ENTRY\n");
            printf("=========================================\n\n\n");

            printf("Enter Entry No: ");
            scanf("%d", &addentry[count].serial);
            getchar();

            int duplicateFound = 0;
            for (int i = 0; i < count; i++) {
                if (addentry[i].serial == addentry[count].serial) {
                    duplicateFound = 1;
                    break;
                }
            }

            if (duplicateFound) {
                printf("\nError: Entry with Serial No. %d already exists!", addentry[count].serial);
                printf("\n\nPress Enter to Continue...");
                getchar();
                continue;
            }

            printf("Enter Title: ");
            fgets(addentry[count].title, 200, stdin);
            trimNewline(addentry[count].title);

            printf("Enter Content: ");
            fgets(addentry[count].content, 5000, stdin);
            trimNewline(addentry[count].content);

            count++;
            saveEntries();

            printf("\n\nEntry successfully added and saved to file!");
            printf("\n\nPress Enter to Continue...");
            getchar();
        }

        else if(choice==2){
            system("cls");

            printf("=========================================\n");
            printf("              MY DIARY ENTRIES\n");
            printf("=========================================\n\n\n");

            if(count==0){
                printf("You Don't Have Any Entries Till Now.");
            }
            else{
                for(int i=0; i<count; i++){
                    printf("Entry No. %d\n", addentry[i].serial);
                    printf("Title: %s\n", addentry[i].title);
                    printf("Content: %s\n", addentry[i].content);
                    printf("\n---------------------------\n");
                }
            }
            printf("\n\nPress Enter to Continue...");
            getchar();
            getchar();
        }
        else if(choice==3){
            system("cls");

            printf("=========================================\n");
            printf("               SEARCH ENTRY\n");
            printf("=========================================\n\n\n");


            int findEntry, found = 0;

            printf("Enter Serial No. to Search Entry: ");
            scanf("%d", &findEntry);

            for(int i=0; i<count; i++){
                if (findEntry == addentry[i].serial){
                    printf("\nEntry No. %d", addentry[i].serial);
                    printf("\nTitle: %s", addentry[i].title);
                    printf("\nContent: %s\n", addentry[i].content);
                    found = 1;
                    break;
                }
            }

            if(found==0){
                printf("\nEntry not found.\n");
            }

            printf("\n\nPress Enter to Continue...");
            getchar();
            getchar();
        }
        else if(choice==4){
            system("cls");

            printf("=========================================\n");
            printf("                EDIT ENTRY\n");
            printf("=========================================\n\n\n");

            int editEntry, found = 0;

            printf("Enter Serial No. to Edit: ");
            scanf("%d", &editEntry);

            for(int i=0; i<count; i++){
                if(editEntry == addentry[i].serial) {
                    getchar();

                    printf("Enter New Title: ");
                    fgets(addentry[i].title, 200, stdin);
                    trimNewline(addentry[i].title);

                    printf("Enter New Content: ");
                    fgets(addentry[i].content, 5000, stdin);
                    trimNewline(addentry[i].content);

                    found = 1;
                    saveEntries();
                    printf("\nEntry successfully edited and updated in file.");
                    break;
                }
            }

            if(found==0){
                printf("\nEntry Not Found.");
            }

            printf("\n\nPress Enter to Continue...");
            getchar();
            getchar();
        }
        else if(choice==5){
            system("cls");

            printf("=========================================\n");
            printf("               DELETE ENTRY\n");
            printf("=========================================\n\n\n");

            int deleteEntry, found = 0;

            printf("Enter Serial No. to Delete An Entry: ");
            scanf("%d", &deleteEntry);

            for(int i = 0; i < count; i++){
                if(deleteEntry == addentry[i].serial){
                    for(int j = i; j < count - 1; j++){
                        addentry[j] = addentry[j + 1];
                    }
                    count--;
                    found = 1;
                    saveEntries();
                    printf("\nEntry successfully deleted.");
                    break;
                }
            }

            if(found==0){
                printf("\nEntry Not Found.");
            }

            printf("\n\nPress Enter to Continue...");
            getchar();
            getchar();
        }
        else if(choice==6){
            system("cls");
            printf("Logging out...");
            getchar();
            getchar();
        }
    }
}

void regist(){
    system("cls");

    printf("=========================================\n");
    printf("             USER REGISTRATION\n");
    printf("=========================================\n\n\n");

    getchar();

    printf("Name: ");
    fgets(numberofUsers[userCount].name, 100, stdin);
    trimNewline(numberofUsers[userCount].name);

    printf("Username: ");
    scanf("%29s", numberofUsers[userCount].user);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(numberofUsers[userCount].user, numberofUsers[i].user) == 0) {
            system("cls");
            printf("Username already exists!\nPlease try registering with a different username.");
            printf("\n\nPress Enter to Continue...\n\n");
            getchar();
            getchar();
            return;
        }
    }

    printf("Password: ");
    scanf("%s", numberofUsers[userCount].pass);

    printf("Confirm Password: ");
    scanf("%s", numberofUsers[userCount].copass);

    if(strcmp(numberofUsers[userCount].copass, numberofUsers[userCount].pass) == 0){
        userCount++;
        saveUsers();

        system("cls");
        printf("=========================================\n");
        printf("       REGISTRATION SUCCESSFUL\n");
        printf("=========================================\n");
        printf("\n\nPress Enter to Continue...\n\n");
        getchar();
        getchar();
    }
    else{
        system("cls");
        printf("Password Doesn't Match!");
        printf("\nPlease Try Again...");
        getchar();
        getchar();
    }
}

int main(){

    loadUsers();
    loadEntries();

    int choice = 0;

    while(choice!=3){
        system("cls");
        printf("=========================================\n");
        printf("       WELCOME TO PERSONAL DIARY\n");
        printf("=========================================\n");
        printf("\n\n1. Log in");
        printf("\n2. Register");
        printf("\n3. Exit Program");
        printf("\n\nEnter Your Choice(1-3): ");

        scanf("%d", &choice);

        if(choice==1){
            logIn();
        }
        else if(choice==2){
            regist();
        }
        else if(choice==3){
            system("cls");
            printf("Exiting Program. Goodbye!\n\n");
        }
        else{
            system("cls");
            printf("Please Type A Valid Number");
            printf("\n\nPress Enter to Continue...\n\n");
            getchar();
            getchar();
        }
    }

    return 0;
}
