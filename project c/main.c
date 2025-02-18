#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main() {
	int j;
	loadUsersFromFile();
	char userID[20];
    const char *admin_username = "phamhuynhtiendatpy@gmail.com";
    const char *admin_password = "0399857418";
	int Choice,Choice2,choice3;
	//ham hien thi menu1
	ShowMenu1:
    ShowMenu1();
    printf("\nPlease enter your selection (0->2):");
    scanf("%d",&Choice);
    switch(Choice) {
    //................................................................
	case 1:
	LoginAdmin(admin_username,admin_password);
do {
	// ham hien thi menu 2
	ShowMenu2();
    printf("\nPlease enter your selection(0->6)");
	scanf("%d",&Choice2);
	switch(Choice2) {
    case 1:
    // ham them nguoi dung
    AddUser();
    break;
    case 2:
    // ham hien thi danh sach
    Displayers();
    do{
    ShowMenu4();
    printf("\n\t Please enter your selection(0->2):");
    scanf("%d",&choice3);
    switch(choice3) {
    case 1:
    sortByNameAZ();
    	printf("\tSorted by name successfully(A-Z)\n");
    break;
    case 2:
    sortByNameZA();
    printf("\tSorted by name successfully(Z-A)\n");
    break;
    case 0:
    printf("\nNhan SPACE roi enter de quay lai menu quan ly(Admin)...");
    while (getchar() != ' ');
    break;
}
}while (choice3<0||choice3>2);

break;
    case 3:
    // ham tim kiem nguoi dung
    FindUser();
    printf("\nNhan SPACE roi enter de quay lai menu quan ly(Admin)...");
    while (getchar() != ' ');
    break;
    case 4:
    	// hamf tim kiem bang id
    	FinduserID();
    	printf("\nNhan SPACE roi enter de quay lai menu quan ly(Admin)...");
    while (getchar() != ' ');
    break;
    case 5:
    	LockUnlockUser();
    break;
    case 6:
    	goto ShowMenu1;
    	break;
    case 0:
    	return 0;
    break;
    //...............................................................................
}
}while(Choice2<6||Choice2>0);
	break;
	case 2:
	//ham hien thi menu 3
	Login(Users,j, UserCount);
    printf("\nNhan SPACE roi enter de quay lai menu quan ly(Admin)...");
    while (getchar() != ' ');
    goto ShowMenu1;
	break;
	case 3:
	printf("Please enter the user id whose password needs to be changed");
	scanf("%s",userID);
	changePassword(Users, UserCount, userID);
	printf("\nNhan SPACE roi enter de quay lai menu quan ly(Admin)...");
    while (getchar() != ' ');
    goto ShowMenu1;
	break;
	case 0:
	return 1;	
}
free(Users);
    return 0;
}
