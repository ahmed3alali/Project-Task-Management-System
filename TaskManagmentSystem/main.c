#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_management.h"

int main() {
    
    

    printf("\n===TASK MANAGEMENT SYSTEM BY AHMAD ALALI 2221251365=============");
    printf("\n===MY TASKS DASHBOARD - WEL COME :) - HAVE A PRODUCTIVE DAY!=====");
    printf("\n========    PRESS 1 TO START THE PROGRAM    =====");
    
    
   
    printf("\n===5. EXIT ");
    printf("\n================================================================== ");

printf("\n press: ");
int choice = 0;
int code =0;
int SetterStatus=0;
int update=0;
int priortyfind=0;
int  find = 0;
char usernamey[20];
char projectAdi[20];
char task_adi[20];
  
    scanf("%d", &choice);

    
    switch (choice) {
        case 1:
            while (choice != 9) {
                printf("\n===TASK MANAGEMENT SYSTEM BY AHMAD ALALI 2221251365=====");
                printf("\n===1. New task ");
                printf("\n===2. Delete Task ");
                printf("\n===3. Find Task ");
                printf("\n===4. Update Tasks ");
                printf("\n===5. User Tasks Search ");
                printf("\n===6. TASK NO for Projects Search ");
                printf("\n===7. User FULL REPORT ");
                printf("\n===8. Tasks Priority Search ");
                printf("\n===9. SET TASK PRIORITY -FINISHED/NOT ");
                printf("\n===10. Display Program Users ");
                printf("\n===11. Delete A User");
                printf("\n===12. Delete A PROJECT");
                printf("\n===13. DISPLAY FULL REPORT ");
                printf("\n===14. EXIT...");
               
                printf("\n================================================================== ");

                scanf("%d", &choice);

                switch (choice) {

                    case 1:
                        addTaskToFile();
                        break;
                    case 2:

                    printf("\t task title to delete : ");
                    scanf("%s",&task_adi);
                      deleteTasksByTitle(task_adi);
                        break;
                    case 3:
                    printf("\ncode to find : ");
                    scanf("%d",&find);
                        findTaskByCode(find);
                        break;
                    case 4:
                         printf("\ncode to update : ");
                         scanf(" %d",&update);
                        updateTaskByCode(update);
                        break;

                        case 5:
                        printf("enter username :\n ");
                        scanf("%s",&usernamey);
                        countTasksPerUser(usernamey);
                        break;

                        case 6: 
                        printf("enter projectname :\n");
                        scanf("%s",&projectAdi);
                        countTasksPerProject(projectAdi);
                        break;
                       
                        
                        case 7: 
                       printf("\n===5. User FULL REPORT Search=== ");
                       printf("\n===5. ENTER USER :");
                       scanf("%s",&usernamey);
                       showUserStatus(usernamey);
                       break;

                       case 8:
                        printf("\n===5. ENTER value for priority :");
                        scanf("%d",&priortyfind);
                       countTasksPerPriority(priortyfind);
                       break;

                    case 9:

                    printf("===SET STATUS OF YOUR TASK====");
                    printf("enter code : ");
                    scanf("%d",&code);
                    printf("enter status (1)finished -(0)Unfinished:");
                    scanf("%d",&SetterStatus);
                    if (SetterStatus==1)
                    {
                        setTaskStatus(code,SetterStatus);
                        
                      
                    }else if(SetterStatus==0)
                    {
                        setTaskStatus(code,SetterStatus);
                       
                    } else
                    {
                        printf("\n invalid");
                    }
                    
                    break;
                    

                    case 10:
                   printf("\n ==USERS USING PROGRAM ====");
                   displayUsers();
                  
                  break;
                   case 11:
                    printf("\n ==DELETE A USER   ====");
                    printf("ATTENTION : DELETING A USER DELETES ALL TASKS/PROJECTS ASSIGNED TO HIM ");
                    printf("\n ==USER NAME :");
                    scanf("%s",&usernamey);
                    deleteUserTasks(usernamey);
                    break;
                   case 12:
                    printf("\n ==DELETE A PROJECT   ====");
                    printf("ATTENTION : DELETING A PROJECT DELETES ALL TASKS/USERS ASSIGNED TO IT ");
                    printf("enter projectName:");
                    scanf("%s",&projectAdi);
                    deleteProjectTasks(projectAdi);
                    break;


                   case 13:
                    displayProjectsAndUsers();
                    break;


                    case 14:
                       
                        printf("Exiting the program.\n");
                        return 0;
                        break;
                    default:
                        printf("Invalid choice. Please select a valid option.\n");
                        break;
                }
            }
            break;
        case 2:
          
            break;
       
        case 5:
            // Exit the program
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }

    return 0;
}
