#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"
//ham quan ly du lieu
void loadUsersFromFile();
void saveUsersToFile();
// ham quan ly bo nho
void Allocation();
void ClearScreen();
//ham hien thi giao dien
void ShowMenu1();
void ShowMenu2();
void ShowMenu3();
//ham thuc hien cac chuc nang
void AddUser();
void DisplayUsers();
int CheckInput(User *user);
void FindUser();
void LockUnlockUser();
void sortByNameAZ();
void sortByNameZA();
void Login(User users[],int J, int count);
void LoginAdmin(const char *admin_username, const char *admin_password);
void changePassword(User users[], int userCount, const char *userId);
#endif

