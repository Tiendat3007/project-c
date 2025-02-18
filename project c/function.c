#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "function.h"
User *Users = NULL;
int UserCount = 0;
int TransactionCount = 0;       
int UserCapacity = 0;
int transactionCapacity = 0; 
//ham file
void loadUsersFromFile() {
    FILE *file = fopen("file.bin", "rb");
    if (!file) {
        printf("File not found.\n");
        return;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    UserCount = fileSize / sizeof(User);
    UserCapacity = UserCount > 0 ? UserCount * 2 : 10;
    Users = (User *)malloc(UserCapacity * sizeof(User));

    if (!Users) {
        printf("Memory allocation error\n");
        fclose(file);
        exit(1);
    }

    fread(Users, sizeof(User), UserCount, file);

    fclose(file);

    printf("Loaded %d users from file.bin\n", UserCount);
}


void saveUsersToFile() {
	int i;
    FILE *file = fopen("file.bin", "wb");
    if (!file) {
        printf("error opening file.bin!\n");
        return;
    }

        fwrite(Users, sizeof(User), UserCount, file);


    fclose(file); 
}
// ham cap phat
void Allocation() {
    if (UserCount >= UserCapacity) {
        UserCapacity = (UserCapacity == 0) ? 10 : UserCapacity * 2;
        Users = (User *) realloc(Users, UserCapacity * sizeof(User));
        if (!Users) {
            printf("error allocating more memory.\n");
            exit(1);
        }
    }
    if (Users == NULL) {
    UserCapacity = 10;
    Users = (User *)malloc(UserCapacity * sizeof(User));
}

}
// ham xoa man hinh
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #endif
}
// ham hien thi menu trang chu moi vào 
void ShowMenu1() {
	ClearScreen();
    printf("   *****Bank Management System Using C*****\n");
    printf("\n\tPlease enter your selection(0->2)\n");
    printf("   |========================================|\n");
    printf("\t(1) Admin\n");
    printf("\t(2) user\n");
    printf("\t(3) change user password\n");
    printf("\t(0) exit\n");
    printf("   |========================================|");
}
// ham hien thi menu nguoi quan ly ngan hang
void ShowMenu2(){
	 printf("   *****Bank Management System Using C*****\n");
    printf("\n\tPlease enter your selection(0->5)\n");
    printf("   |========================================|\n");
    printf("\t(1) add new users\n");
    printf("\t(2) displays the list of users\n");
    printf("\t(3) Search by username\n");
    printf("\t(4) search by user id\n");
    printf("\t(5) lock/unlock by id\n");
    printf("\t(6) return to main menu\n");
    printf("\t(0) exit\n");
    printf("   |========================================|");
}
void Login(User users[],int j, int user_count) {
    char username[MAX_EMAIL_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("enter account(email): ");
        scanf("%s", username);
        printf("enter password(The default is the phone number when creating): ");
        int i = 0;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            } else {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        int found = 0;
        for (j = 0; j < user_count; j++) {
            if (strcmp(username, users[j].email) == 0) {
                found = 1;
                if (strcmp(password, users[j].phone) == 0) {
                    if (strcmp(users[j].status, "active") == 0) {
                        printf("\nLog in successfully!\n");
                        return;
                    } else {
                        printf("\nYour account has been locked.\n");
                        return;
                    }
                } else {
                    printf("\nWrong login information, please re-enter.\n");
                }
                break;
            }
        }
        if (!found) {
            printf("\naccount does not exist.\n");
        }
    }
}
void LoginAdmin(const char *admin_username, const char *admin_password) {
    char email[MAX_EMAIL_LEN];
    char password[MAX_PASSWORD_LEN];
    
    while (1) {
        printf("Enter the manager account: ");
        scanf("%s", email);
                printf("Enter the administrator password: ");
        int i = 0;
        char ch;
        while ((ch = getch()) != '\r') { 
            if (ch == '\b') {
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            } else {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        //kiem tra dang nhap
        if (strcmp(email, admin_username) == 0 && strcmp(password, admin_password) == 0) {
            printf("\nLog in successfully!\n");
            break;
        } else {
            printf("\nIncorrect management information, please re-enter.\n");
        }
    }
}

//me nu4
void ShowMenu4(){
	 printf("   *****Bank Management System Using C*****\n");
    printf("\n\tPlease enter your selection(0->2)\n");
    printf("   |========================================|\n");
    printf("\t(1) sort by name(a-z)\n");
    printf("\t(2) sort by name(z-a)\n");
    printf("\t(0) come back menu\n");
    printf("   |========================================|");}
// ham de them nguoi dung moi vao 
void AddUser () {
    ClearScreen();
    printf("***** ADD NEW USER *****\n");
    Allocation();
    User newUser ;

int isIDExists(const char *id) {
    	int i;
        for (i = 0; i < UserCount; i++) {
            if (strcmp(Users[i].id, id) == 0) {
                return 1;
            }
        }
        return 0;
    }
    int PhoneExists(const char *phone) {
    	int i;
        for (i = 0; i < UserCount; i++) {
            if (strcmp(Users[i].phone, phone) == 0) {
                return 1;
            }
        }
        return 0;
    }
    int EmailExists(const char *email) {
    	int i;
        for (i = 0; i < UserCount; i++) {
            if (strcmp(Users[i].email, email) == 0) {
                return 1;
            }
        }
        return 0;
    }
//nhap id neu sai thi nhap lai
    while (1) {
        printf("enter user id: ");
        scanf("%s", newUser .id);
        if (isIDExists(newUser .id)) {
            printf("id already exists, please enter another id.\n");
        } else {
            break;
        }
    }
    printf("enter username: ");
    scanf(" %[^\n]", newUser .name);
   while (1) {
    printf("Enter phone number: ");
    scanf("%s", newUser.phone);
    if (strlen(newUser.phone) != 10) {
        printf("? Error: Phone number must be exactly 10 digits! Please enter again.\n");
    } else {
    	if (PhoneExists(newUser.phone)) {
        printf("? Error: phone number exists.\n");
    } else {
        break;
    }
    }
    
}

   while (1) {
        printf("Enter email: ");
        scanf("%s", newUser.email);

        if (strchr(newUser.email, '@') == NULL) {
            printf("? Error: Email must contain '@'. Please enter again.\n");
        } else {
         if (EmailExists(newUser.email)) {
        printf("? Error: email exists.\n");
    } else {
        break;
    }
        }
        
    }
    printf("enter birthday (YYYY-MM-DD): ");
    scanf("%s", newUser .birthDate);
    printf("enter address: ");
    scanf(" %[^\n]", newUser .address);
    printf("enter balance: ");
    scanf("%f", &newUser .balance);
    strcpy(newUser .password, newUser .phone);
    strcpy(newUser .status, "Open");
    if (CheckInput(&newUser ) == 0) {
        Users[UserCount++] = newUser ; //them nguoi dung va tang so luong nguoi dung
        printf("The user has been added successfully!\n");
    } else {
        printf("add user failed.\n");
    }

    saveUsersToFile();
}
// ham de hien thi tat ca nguoi dung ngân hàng
  void Displayers() {
    ClearScreen();
    printf("\n******LIST OF USERS******:\n");
    if (UserCount == 0) {
        printf("There are no users!\n");
        return;
    }
    printf("| %-10s | %-15s | %-20s | %-30s | %-10s |\n", 
           "ID", "Name", "Phone", "Email", "Status");
    printf("|---------------------------------------------------------------------------------------------------|\n");
    int i;
    for (i = 0; i < UserCount; i++) {
        printf("| %-10s | %-15s | %-20s | %-30s | %-10s |\n",
               Users[i].id,
               Users[i].name,
               Users[i].phone,
               Users[i].email,
               Users[i].status);
    }
    printf("|---------------------------------------------------------------------------------------------------|\n");
}
// ham kiem tra thong tin co phu hop khong
int CheckInput(User *user) {
    if (strlen(user->name) < MIN_NAME_LEN || strlen(user->name) > MAX_NAME_LEN) {
        printf("? error: Ten phai co tu %d - %d ky tu!\n", MIN_NAME_LEN, MAX_NAME_LEN);
        return -1;
    }
    if (strlen(user->phone) < MIN_PHONE_LEN || strlen(user->phone) > MAX_PHONE_LEN) {
        printf("? error: So dien thoai phai co tu %d - %d ky tu!\n", MIN_PHONE_LEN, MAX_PHONE_LEN);
        return -1;
    }
    if (strlen(user->email) < MIN_EMAIL_LEN || strlen(user->email) > MAX_EMAIL_LEN) {
        printf("? error: Email phai co tu %d - %d ky tu!\n", MIN_EMAIL_LEN, MAX_EMAIL_LEN);
        return -1;
    }
    int i;
    for (i = 0; i < UserCount; i++) {
        if (Users[i].id == user->id) {
            printf("? error: ID da ton tai!\n");
            return -1;
        }
        if (strcmp(Users[i].phone, user->phone) == 0) {
            printf("? error: So dien thoai da ton tai!\n");
            return -1;
        }
        if (strcmp(Users[i].email, user->email) == 0) {
            printf("? error: Email da ton tai!\n");
            return -1;
        }
    }
    return 0;
}

    

//ham tim hiem nguoi dung bang ten nguoi dung
void FindUser() {
	    ClearScreen();
    printf("*****SEARCH FOR USERS*****\n");
    char KeyWord[50];
    printf("Enter the username to search for: ");
    fflush(stdin);
    scanf(" %[^\n]", KeyWord);
    int i, Check = 0;
    printf("| %-10s | %-15s | %-25s | %-20s | %-15s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("|---------------------------------------------------------------------------------------------------|\n");

    for (i = 0; i < UserCount; i++) {
    if (strstr(Users[i].name, KeyWord) != NULL){
            printf("| %-10s | %-15s | %-25s | %-20s | %-15s |\n",
                   Users[i].id,
                   Users[i].name,
                   Users[i].phone,
                   Users[i].email,
                   Users[i].status);
            Check = 1;
        }
    }
    printf("|---------------------------------------------------------------------------------------------------|\n");
    if (Check == 0) { 
        printf("User not found!\n");
    }
}
void FinduserID() {
	ClearScreen();
    char id[11];
    int i;
    printf("Enter the user id to search: ");
    scanf("%s", id);

    for (i = 0; i < UserCount; i++) {
        if (strcmp(Users[i].id, id) == 0) {
            printf("user found:\n");
            printf("ID: %s\n", Users[i].id);
            printf("name: %s\n", Users[i].name);
            printf("phone number: %s\n", Users[i].phone);
            printf("Email: %s\n", Users[i].email);
            printf("birthday: %s\n", Users[i].birthDate);
            printf("Address: %s\n", Users[i].address);
            printf("balance: %.2f\n", Users[i].balance);
            printf("status: %s\n", Users[i].status);
            return;
        }
    }
    printf("user with id not found: %s\n", id);
}
// khoa/mo khoa
void LockUnlockUser() {
	char id[11];
    int i,found = 0;
    printf("Enter the user id you want to lock/unlock: ");
    scanf("%s", &id);

    for (i = 0; i < UserCount; i++) {
        if (strcmp(Users[i].id, id) == 0) {
            found = 1;
            if (strcmp(Users[i].status, "Locked") == 0) {
                printf("User is locked, confirm unlock? (y/n): ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    strcpy(Users[i].status, "Open");
                    printf("unlocked successfully!\n");
                } else {
                    printf("cancel unlock!\n");
                }
            } else {
                printf("The user is opening the lock confirmation? (y/n): ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    strcpy(Users[i].status, "Locked");
                    printf("lock successfully!\n");
                } else {
                    printf("cancel lock!\n");
                }
            }
            saveUsersToFile();
            break;
        }
    }

    if (!found) {
        printf("user with id not found %s!\n", id);
    }
}
//sap xep theo ten
void sortByNameAZ() {
		ClearScreen();
    if (UserCount == 0) return;
    int i,j;
    for (i = 0; i < UserCount - 1; i++) {
        for (j = i + 1; j < UserCount; j++) {
            if (strcmp(Users[i].name, Users[j].name) > 0) {
                User temp = Users[i];
                Users[i] = Users[j];
                Users[j] = temp;
            }
        }
    }
}
// sap xep theo id
void sortByNameZA() {
    ClearScreen();
    if (UserCount == 0) return;
    int i, j;
    for (i = 0; i < UserCount - 1; i++) {
        for (j = i + 1; j < UserCount; j++) {
            if (strcmp(Users[i].name, Users[j].name) < 0) {
                User temp = Users[i];
                Users[i] = Users[j];
                Users[j] = temp;
            }
        }
    }
}
void changePassword(User users[], int userCount, const char *userId) {
    char oldPassword[MAX_PASSWORD_LEN], newPassword[MAX_PASSWORD_LEN], confirmPassword[MAX_PASSWORD_LEN];
    int i,found = 0;

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, userId) == 0) {
            found = 1;

            // Nh?p m?t kh?u cu
            while (1) {
                printf("Enter old password: ");
                scanf("%s", oldPassword);

                if (strcmp(oldPassword, users[i].phone) == 0) {
                    break;
                } else {
                    printf("Mat khau khong dung. Vui long thu lai!\n");
                }
            }

            // Nh?p m?t kh?u m?i
            while (1) {
                printf("enter new password: ");
                scanf("%s", newPassword);
                printf("Re-enter new password: ");
                scanf("%s", confirmPassword);

                if (strcmp(newPassword, confirmPassword) == 0) {
                    strcpy(users[i].password, newPassword);
                    printf("Password has been changed successfully!\n");
                    return;
                } else {
                    printf("Invalid password, please try again!\n");
                }
            }
        }
    }

    if (!found) {
        printf("User not found!\n");
    }
}




