#ifndef TASK_MANAGEMENT_H
#define TASK_MANAGEMENT_H
#endif
#include <stdio.h>
#include <string.h>


#define PRINT_MESSAGE(msg) printf("%s\n", msg)

enum Priority {
    URGENT=1,
    HIGH=2,
    LOW=3
};

enum Category {
    WORK=1,
    SPORT=2,
    STUDY=3,
    OTHER=4
};

enum Days {
    MONDAY=1,
    TUESDAY=2,
    WEDNESDAY=3,
    THURSDAY=4,
    FRIDAY=5,
    SATURDAY=6,
    SUNDAY=7
};



struct task {
    char *task_title;
  

    
    char *task_time;
enum Priority task_priority;
    enum Category task_catg;
    enum Days task_day;
    int code;

    char *username;     
    char *projectname; 

};


struct Project {
    char *project_name;
    int num_tasks;
     struct User *assigned_users;
     struct task *assigned_task;
     int num_users;
   
};




struct User {
    char *username;
    int num_projects;
    int user_id;
    void (*displayUserInfoTRIAL)( struct User *user);
    
};






void myDashboard();
void findUserProjects();
void addTaskToFile();
void findTaskByCode();
void updateTaskByCode();


void countTasksPerUser();
void showUserStatus();
void countTasksPerPriority();
void setTaskStatus();
void deleteUserTasks();
void deleteProjectTasks();
int **countTasksPerProject(const char *project_name);
void displayProjectsAndUsers();
void displayUsers();
int takeInputFromUserForMenu();
void deleteTasksByTitle();