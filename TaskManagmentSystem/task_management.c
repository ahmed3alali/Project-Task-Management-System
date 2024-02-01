#include "task_management.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




// PRIORITY

void findTaskByPriority(enum Priority prty)
{
    FILE *fp;
    struct task currentTask;

    fp = fopen("task_info.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile not found or unable to open.");
        return;
    }

    printf("\n === MATCHING TASKS ===");

    while (fread(&currentTask, sizeof(struct task), 1, fp) == 1)
    {
        if (currentTask.task_priority == prty)
        {
            printf("\n Title : %s", currentTask.task_title);
            printf("\n Category : %s", currentTask.task_catg);
            printf("\n Priority: %s", currentTask.task_priority);
            printf("\n Day : %d", currentTask.task_day);
        }
    }

    fclose(fp);
}

// CATEGORY



int CodeIDchecker(int givenId) {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("\nFile not found or unable to open.");
        return 0; 
    }   

    int found = 0;
    char title[100];
    char time[50];
    char username[50];
    char projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {
        if (code == givenId) {
            found = 1;
            break; 
        }
    }

    fclose(file);
    return found; 
}


void findTaskByCategory(enum Category catg)
{
    FILE *fp;
    struct task currentTask;

    fp = fopen("task_info.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile not found or unable to open.");
        return;
    }

    printf("\n === MATCHING TASKS ===");

    while (fread(&currentTask, sizeof(struct task), 1, fp) == 1)
    {
        if (currentTask.task_catg == catg)
        {
            printf("\n Title : %s", currentTask.task_title);
            printf("\n Category : %s", currentTask.task_catg);
            printf("\n Priority: %s", currentTask.task_priority);
            printf("\n Day : %d", currentTask.task_day);
        }
    }

    fclose(fp);
}

void findTaskByTitle(const char title[20])
{
    FILE *fp;
    struct task currentTask;

    fp = fopen("task_info.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile not found or unable to open.");
        return;
    }

    printf("\n === MATCHING TASKS ===");

    while (fscanf(fp, "%s %s %s %s %d\n", currentTask.task_title,
                  currentTask.task_priority, currentTask.task_catg,
                  currentTask.task_day, &currentTask.code) == 5)
    {
        if (strcmp(currentTask.task_title, title) == 0)
        {
            printf("\n Title : %s", currentTask.task_title);
            printf("\n Category : %s", currentTask.task_catg);
            printf("\n Priority: %s", currentTask.task_priority);
            printf("\n Day : %s", currentTask.task_priority/
            printf("if I am going to have a bew d")
            
            printf("\n Code : %d", currentTask.code);
        }
    }

    fclose(fp);
}





void findUserProjects(const char *username) {
    FILE *fp;
    struct task currentTask;
    int found = 0;

    fp = fopen("task_info.txt", "r");
    if (fp == NULL) {
PRINT_MESSAGE("File not found or unable to open.");
       
        return;
    }

    printf("\n === PROJECTS FOR USER '%s' ===", username);

    while (fread(&currentTask, sizeof(struct task), 1, fp) == 1) {
        
        if (strcmp(currentTask.username, username) == 0) {
            printf("\n Project : %s", currentTask.projectname);
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nNo projects found for user '%s'.", username);
    }
}




void addTaskToFile() {
    
    int trialCode=0;
    int resultCheck = 0;
    struct task newTask;
    FILE *file = fopen("task_info.txt", "a");

    if (file == NULL) {
PRINT_MESSAGE("error : cannot open file");
        
        return;
    }

    // Allocating memory for string fields
    newTask.task_title = (char *)malloc(100 * sizeof(char)); 
    newTask.task_time = (char *)malloc(50 * sizeof(char));    
    newTask.username = (char *)malloc(50 * sizeof(char));    
    newTask.projectname = (char *)malloc(50 * sizeof(char));  

    if (!newTask.task_title || !newTask.task_time || !newTask.username || !newTask.projectname) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter task title: ");
    scanf("%s", newTask.task_title);

    printf("Enter task time: ");
    scanf("%s", newTask.task_time);

    printf("Enter username: ");
    scanf("%s", newTask.username);

    printf("Enter project name: ");
    scanf("%s", newTask.projectname);

    printf("Enter task priority (1: URGENT, 2: HIGH, 3: LOW): ");
    scanf("%d", &newTask.task_priority);

    printf("Enter task category (1: WORK, 2: SPORT, 3: STUDY, 4: OTHER): ");
    scanf("%d", &newTask.task_catg);

    printf("Enter task day (1-7): ");
    scanf("%d", &newTask.task_day);

 printf("Enter task code: ");
scanf("%d", &trialCode);

resultCheck = CodeIDchecker(trialCode);

while (resultCheck == 1) {
    printf("\nCode already taken, enter a new code: ");
    scanf("%d", &trialCode);
    resultCheck = CodeIDchecker(trialCode);
}

newTask.code = trialCode;

    


    // Write task details to the file
    fprintf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
            newTask.task_title, newTask.task_time, newTask.username, newTask.projectname,
            newTask.task_priority, newTask.task_catg, newTask.task_day, newTask.code);

    fclose(file);
    free(newTask.task_title);
    free(newTask.task_time);
    free(newTask.username);
    free(newTask.projectname);

    printf("Task added successfully.\n");
}


int getValidChoice() {
    int choice;
    while (1) {
        printf("Enter your choice (1 for yes, 0 for no): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // Clear input buffer
        } else if (choice != 0 && choice != 1) {
            printf("Invalid choice. Please enter either 0 or 1.\n");
        } else {
            break;
        }
    }
    return choice;
}





void findTaskByCode(int searchCode) {
    FILE *file = fopen("task_info.txt", "r");

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    int found = 0;
    char title[100];
    char time[50];
    char username[50];
    char projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {
        if (code == searchCode) {
           
            printf("Title: %s\n", title);
            printf("Priority: %s\n", priority == URGENT ? "URGENT" : (priority == HIGH ? "HIGH" : "LOW"));
            printf("Category: %s\n", catg == WORK ? "WORK" : (catg == SPORT ? "SPORT" : (catg == STUDY ? "STUDY" : "OTHER")));
            printf("Day: %s\n", day == MONDAY ? "MONDAY" : (day == TUESDAY ? "TUESDAY" : (day == WEDNESDAY ? "WEDNESDAY" : 
                (day == THURSDAY ? "THURSDAY" : (day == FRIDAY ? "FRIDAY" : (day == SATURDAY ? "SATURDAY" : "SUNDAY"))))));
            printf("Time: %s\n", time);
            printf("Username: %s\n", username);
            printf("Project Name: %s\n", projectname);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Task with code %d not found.\n", searchCode);
    }
}



void updateTaskByCode(int searchCode) {
   FILE *file = fopen("task_info.txt", "r");
    FILE *tempFile = fopen("temp_task_info.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }



    int found = 0;
    char title[100];
    char time[50];
    char username[50];
    char projectname[50];
    int priority;
    int catg;
    int day;
    int code;


struct task currentTask;



    while (fscanf(file, "%[^\n]\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {
        
        if (code == searchCode) {
            found = 1;

 printf("Task found! Do you want to update the task title? ");
            int updateChoice = getValidChoice();



if (updateChoice == 1) {
                printf("Enter new task title: ");
                scanf("%s", &title);
            }





 printf("Do you want to update the task time? ");
            updateChoice = getValidChoice();

            if (updateChoice == 1) {
                printf("Enter new task time: ");
                scanf("%s", &time);
            }


 printf("Do you want to update the task priority? ");
            updateChoice = getValidChoice();

            if (updateChoice == 1) {
                printf("Enter new task priority: ");
                scanf("%d", &priority);
            }
 

      printf("Do you want to update the task category? ");
            updateChoice = getValidChoice();

            if (updateChoice == 1) {
                printf("Enter new task category: ");
                scanf("%d",&catg );
            }


  printf("Do you want to update the task assigned user? ");
            updateChoice = getValidChoice();

            if (updateChoice == 1) {
                printf("Enter new task user: ");
                scanf("%s",&username );
            }
      

 printf("Do you want to update the task day? ");
            updateChoice = getValidChoice();

            if (updateChoice == 1) {
                printf("Enter new task day: ");
                scanf("%d",&day );
            }



fprintf(tempFile, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
            title, time, username, projectname,
            priority, catg, day, code);

        
        } else
        {
            

fprintf(tempFile, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
            title, time, username, projectname,
            priority, catg, day, code);



        }
        
    }

    fclose(file);
fclose(tempFile);

   remove("task_info.txt");
    rename("temp_task_info.txt", "task_info.txt");

    if (!found) {
        printf("Task with code %d not found.\n", searchCode);
    } else
    {
           printf("Task with code %d updated succesfully!.\n", searchCode);
    }
    
}



// Function to count tasks assigned to each project using double pointers
int** countTasksPerProject(const char *project_name) {
    FILE *file = fopen("task_info.txt", "r");
    int **projects = NULL;
    int numTasks = 0;

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return NULL;
    }

    char title[100], time[50], username[50], projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {

        if (strcmp(projectname, project_name) == 0) {
            int **temp = realloc(projects, (numTasks + 1) * sizeof(int *));
            if (temp == NULL) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return projects;
            }
            projects = temp;

            projects[numTasks] = malloc(sizeof(int));
            if (projects[numTasks] != NULL) {
                projects[numTasks][0] = code;
                numTasks++;
            } else {
                printf("Memory allocation failed.\n");
                fclose(file);
                return projects; 
            }
        }
    }

    fclose(file);
    printf("Number of tasks for project '%s': %d\n", project_name, numTasks);

    return projects;
}



void countTasksPerUser(const char *username) {
    FILE *file = fopen("task_info.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char title[100], time[50], user[50], project[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, user, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(user, username) == 0) {
            count++;
        }
    }

    fclose(file);
    printf("Number of tasks for user %s: %d\n", username, count);
}


void countTasksPerPriority(enum Priority priority) {
    FILE *file = fopen("task_info.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char title[100], time[50], username[50], projectname[50];
    int priority_val, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority_val, &catg, &day, &code) == 8) {

        if (priority_val == priority) {
            count++;
        }
    }



    fclose(file);
if (priority==1)
{

   printf("Number of tasks with priority %s: %d\n", "URGENT", count); 
    
} else if (priority==2)
{

   printf("Number of tasks with priority %s: %d\n", "HIGH", count);  
  
} else if (priority==3)
{

       printf("Number of tasks with priority %s: %d\n", "LOW", count); 
 
}




}



void countProjectsPerUser(const char *username) {
    FILE *file = fopen("task_info.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char title[100], time[50], user[50], project[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, user, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(user, username) == 0) {
            count++;
        }
    }

    fclose(file);
    printf("Number of projects for user %s: %d\n", username, count);
}

void setTaskStatus(int task_code, int is_finished) {
    FILE *file = fopen("task_info.txt", "r+");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char title[100], time[50], username[50], projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {

        if (code == task_code) {
            fseek(file, -1, SEEK_CUR);
            fprintf(file, "%d", is_finished);
            break;
        }
    }

    fclose(file);
    printf("Task status updated successfully.\n");
}


void showUserStatus(const char *username) {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char title[100], time[50], user[50], project[50];
    int priority, catg, day, code, is_finished;
    int project_count = 0, task_count = 0, finished_count = 0, unfinished_count = 0;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, user, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(user, username) == 0) {
            project_count++;
            task_count++;

            fscanf(file, "%d", &is_finished);
            if (is_finished == 1) {
                finished_count++;
            } else {
                unfinished_count++;
            }

           
            printf("Task: %s, Project: %s\n", title, project);
        }
    }

    fclose(file);
    printf("User: %s\nProjects: %d\nTasks: %d\nFinished Tasks: %d\nUnfinished Tasks: %d\n",
           username, project_count, task_count, finished_count, unfinished_count);
}



const char* priorityToString(enum Priority p) {
    switch(p) {
        case URGENT: return "URGENT";
        case HIGH: return "HIGH";
        case LOW: return "LOW";
        default: return "Invalid Priority";
    }
}

const char* categoryToString(enum Category c) {
    switch(c) {
        case WORK: return "WORK";
        case SPORT: return "SPORT";
        case STUDY: return "STUDY";
        case OTHER: return "OTHER";
        default: return "Invalid Category";
    }
}

const char* dayToString(enum Days d) {
    switch(d) {
        case MONDAY: return "MONDAY";
        case TUESDAY: return "TUESDAY";
        case WEDNESDAY: return "WEDNESDAY";
        case THURSDAY: return "THURSDAY";
        case FRIDAY: return "FRIDAY";
        case SATURDAY: return "SATURDAY";
        case SUNDAY: return "SUNDAY";
        default: return "Invalid Day";
    }
}







void displayUserInfoTRIAL(struct User *user) {
    printf("User ID: %d\n", user->user_id);
    printf("Username: %s\n", user->username);
    printf("Number of projects: %d\n", user->num_projects);
    // Add more details as needed
    printf("\n");
}



void displayUsers() {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
    }


    struct User users[100]; // Assuming a maximum of 100 users, adjust as needed
    int userCount = 0;

    char title[100], time[50], username[50], projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {

        int userFound = 0;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0) {
                userFound = 1;
                break;
            }
        }

        if (!userFound) {
            users[userCount].username = strdup(username);
            users[userCount].num_projects = 1; 
            users[userCount].user_id = userCount + 1; 
            users[userCount].displayUserInfoTRIAL = &displayUserInfoTRIAL;
            userCount++;
        }
    }

    fclose(file);

    printf("Users and their information:\n");
    for (int i = 0; i < userCount; i++) {
        users[i].displayUserInfoTRIAL(&users[i]);
        free(users[i].username); // Free allocated memory for usernames
    }
}







void deleteUserTasks(const char *username) {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_task_info.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Cannot create temporary file.\n");
        fclose(file);
        return;
    }

    char title[100], time[50], user[50], project[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, user, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(user, username) != 0) {
            fprintf(tempFile, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                    title, time, user, project, priority, catg, day, code);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("task_info.txt");
    rename("temp_task_info.txt", "task_info.txt");

    printf("User '%s' tasks deleted successfully.\n", username);
}


void deleteProjectTasks(const char *project_name) {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_task_info.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Cannot create temporary file.\n");
        fclose(file);
        return;
    }

    char title[100], time[50], username[50], project[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(project, project_name) != 0) {
            fprintf(tempFile, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                    title, time, username, project, priority, catg, day, code);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("task_info.txt");
    rename("temp_task_info.txt", "task_info.txt");

    printf("Project '%s' tasks deleted successfully.\n", project_name);
}




void deleteTasksByTitle(const char *task_title) {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_task_info.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Cannot create temporary file.\n");
        fclose(file);
        return;
    }

    char title[100], time[50], username[50], project[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, project, &priority, &catg, &day, &code) == 8) {

        if (strcmp(title, task_title) != 0) {
            fprintf(tempFile, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                    title, time, username, project, priority, catg, day, code);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("task_info.txt");
    rename("temp_task_info.txt", "task_info.txt");

    printf("TASK '%s'  deleted successfully.\n", task_title);
}


void displayProjectsAndUsers() {
    FILE *file = fopen("task_info.txt", "r");
    if (file == NULL) {
        PRINT_MESSAGE("Error: Cannot open file");
        return;
    }

    struct Project projects[100]; // Assuming a maximum of 100 projects, adjust as needed
    int projectCount = 0;

    char title[100], time[50], username[50], projectname[50];
    int priority, catg, day, code;

    while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
                  title, time, username, projectname, &priority, &catg, &day, &code) == 8) {

        int projectFound = 0;
        for (int i = 0; i < projectCount; i++) {
            if (strcmp(projects[i].project_name, projectname) == 0) {
                projectFound = 1;

                int userFound = 0;
                for (int j = 0; j < projects[i].num_users; j++) {
                    if (strcmp(projects[i].assigned_users[j].username, username) == 0) {
                        userFound = 1;
                        break;
                    }
                }

                if (!userFound) {
                    projects[i].assigned_users = realloc(projects[i].assigned_users,
                                                         (projects[i].num_users + 1) * sizeof(struct User));
                    projects[i].assigned_users[projects[i].num_users].username = strdup(username);
                    projects[i].num_users++;
                }

                break;
            }
        }

        if (!projectFound) {
            projects[projectCount].project_name = strdup(projectname);
            projects[projectCount].assigned_users = malloc(sizeof(struct User));
            projects[projectCount].assigned_users[0].username = strdup(username);
            projects[projectCount].num_users = 1;
            projectCount++;
        }
    }

    fclose(file);

    printf("Projects and their assigned users:\n");
    for (int i = 0; i < projectCount; i++) {
        printf("Project: %s\n", projects[i].project_name);
        printf("Assigned Users:\n");
        for (int j = 0; j < projects[i].num_users; j++) {
            printf("- %s\n", projects[i].assigned_users[j].username);
            free(projects[i].assigned_users[j].username);
        }
        free(projects[i].assigned_users);
        free(projects[i].project_name);
        printf("\n");
    }
}







int takeInputFromUserForMenu(int menuRange) {
    int tempInput;
    do {
        printf("Enter your choice (1 to %d): ", menuRange);
        scanf("%d", &tempInput);
    } while (!(tempInput >= 1 && tempInput <= menuRange));

    return tempInput;
}


//PROJECT FINISHED ..
