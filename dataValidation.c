#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* David Vasquez
   Data Validation Program
   June 26th 2018
   This program validates and test the data the user provides against pre-assigned criteria
*/
int main()
{
    int choice;  /*user menu choice */
    int d = 0;  /*day var*/
    int m = 0;  /*month var */
    int yy = 0;  /*year var */
    char userPass[50]; /*password empty array */
    int numUpper = 0;  /*upper case char counter */
    int numLower = 0;   /*lower case char counter */
    int numOther = 0;   /*non alpha counter*/
    int i;              /*int i counter */


    while(choice != 0){
        printf("\nData Validation Program:\n");
        printf("=========================\n");
        printf("1- check date\n2- check a password\n0- Quit\n");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter date (mm/dd/yy separated by spaces): \n");
            scanf("%d %d %d",&m,&d,&yy);
            printf("You entered %d/%d/%d\n", m, d, yy);
            printf("\n");
            if (yy > 2018 || yy < 1900){
                printf("please enter year between 1900-2018\n");
            }
            if (m < 1 || m > 12){
                printf("please enter valid month\n");
            }
            if(m == 4||m == 6||m == 9||m == 11){
                if(d < 1 || d > 30){
                    printf("this month only has 30 days, enter valid day");
                }
            }
            if (m == 1||m == 3||m == 5||m == 7||m == 8||m == 10||m == 12){
                if(d < 1 || d > 31){
                    printf("this month only has 31 days, enter valid day");
                }
            }
            if (m == 2){
                if(d < 1 || d > 28){
                  printf("this month only has 31 days, enter valid day");
                }
            }
        }
        else if(choice ==2){
            printf("Password must have\n 8 characters\n1 uppercase letter\n1 lowercase letter\n1 non-alphabetical character\n");
            printf("Enter password: ");
            scanf("%s", userPass, 50);
            printf("You entered: %s", userPass);
            printf("\n");
            if(strlen(userPass) < 8){
                printf("password is too short");
            }
            for(i=0; i < strlen(userPass); i++){
                if(isupper(userPass[i])){
                    numUpper++;
                }
                if(islower(userPass[i])){
                    numLower++;
                }
                if(isalpha(userPass[i]) != 0){
                    numOther++;
                }
            }
            if(numUpper == 0){
                printf("needs uppercase letter");
            }
            if(numLower == 0){
                printf("needs lowercase letter");
            }
            if(numOther == 0){
                printf("needs non alphabet character");
            }

        }
        else if (choice != 0){
            printf("Invalid menu option");
            }

        }

        printf("Goodbye");
        printf("\n");












    return 0;
}
