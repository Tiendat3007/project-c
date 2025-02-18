#ifndef DATATYPE_H
#define DATATYPE_H

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 50
#define MAX_PASSWORD_LEN 20
#define MAX_STATUS_LEN 10
#define STATUS_OPEN "open"
#define STATUS_LOCKED "locked"
#define MIN_NAME_LEN 2
#define MIN_PHONE_LEN 10
#define MIN_EMAIL_LEN 5

typedef struct {
    char id[20];
    char name[100];
    char phone[20];
    char email[100];
    char birthDate[20];
    char address[200];
    float balance;
    char password[50];
    char status[10];
} User;

extern User *Users;
extern int UserCount;
extern int UserCapacity;

#endif

