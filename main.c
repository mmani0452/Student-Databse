#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    char *id;
    double gpa;
    int creditHours;
} Student;

typedef struct StudentNode
{
    Student *pStudent;
    struct StudentNode *pNext;
} StudentNode;

typedef struct
{
    StudentNode *pIDList;
    StudentNode *pHonorRollList;
    StudentNode *pAcademicProbationList;
    StudentNode *pFreshmanList;
    StudentNode *pSophomoreList;
    StudentNode *pJuniorList;
    StudentNode *pSeniorList;
} Database;

void setdatabase(Database *database)
{
    database->pAcademicProbationList = NULL;
    database->pFreshmanList = NULL;
    database->pHonorRollList = NULL;
    database->pIDList = NULL;
    database->pJuniorList = NULL;
    database->pSeniorList = NULL;
    database->pSophomoreList = NULL;
}

void addtoId(Database *database, Student *student)
{
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pIDList == NULL)
    {
        database->pIDList = stud;
    }
    else if (strcmp(stud->pStudent->id, database->pIDList->pStudent->id) < 0)
    {
        stud->pNext = database->pIDList;
        database->pIDList = stud;
    }
    else
    {
        StudentNode *curr = database->pIDList;
        while (curr->pNext != NULL && strcmp(stud->pStudent->id, curr->pNext->pStudent->id) > 0)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtoprobation(Database *database, Student *student)
{
    if (student->gpa >= 2.00)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pAcademicProbationList == NULL)
    {
        database->pAcademicProbationList = stud;
    }
    else if (stud->pStudent->gpa <= database->pAcademicProbationList->pStudent->gpa)
    {
        stud->pNext = database->pAcademicProbationList;
        database->pAcademicProbationList = stud;
    }
    else
    {
        StudentNode *curr = database->pAcademicProbationList;
        while (curr->pNext != NULL && curr->pNext->pStudent->gpa < stud->pStudent->gpa)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtofreshman(Database *database, Student *student)
{
    if (student->creditHours > 29)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pFreshmanList == NULL)
    {
        database->pFreshmanList = stud;
    }
    else if (strcmp(stud->pStudent->name, database->pFreshmanList->pStudent->name) < 0)
    {
        stud->pNext = database->pFreshmanList;
        database->pFreshmanList = stud;
    }
    else
    {
        StudentNode *curr = database->pFreshmanList;
        while (curr->pNext != NULL && strcmp(stud->pStudent->name, curr->pNext->pStudent->name) > 0)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtosoph(Database *database, Student *student)
{
    if (student->creditHours < 30 || student->creditHours > 59)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pSophomoreList == NULL)
    {
        database->pSophomoreList = stud;
    }
    else if (strcmp(stud->pStudent->name, database->pSophomoreList->pStudent->name) < 0)
    {
        stud->pNext = database->pSophomoreList;
        database->pSophomoreList = stud;
    }
    else
    {
        StudentNode *curr = database->pSophomoreList;
        while (curr->pNext != NULL && strcmp(stud->pStudent->name, curr->pNext->pStudent->name) > 0)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtoJun(Database *database, Student *student)
{
    if (student->creditHours < 60 || student->creditHours > 89)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pJuniorList == NULL)
    {
        database->pJuniorList = stud;
    }
    else if (strcmp(stud->pStudent->name, database->pJuniorList->pStudent->name) < 0)
    {
        stud->pNext = database->pJuniorList;
        database->pJuniorList = stud;
    }
    else
    {
        StudentNode *curr = database->pJuniorList;
        while (curr->pNext != NULL && strcmp(stud->pStudent->name, curr->pNext->pStudent->name) > 0)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtoSen(Database *database, Student *student)
{
    if (student->creditHours < 90)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pSeniorList == NULL)
    {
        database->pSeniorList = stud;
    }
    else if (strcmp(stud->pStudent->name, database->pSeniorList->pStudent->name) < 0)
    {
        stud->pNext = database->pSeniorList;
        database->pSeniorList = stud;
    }
    else
    {
        StudentNode *curr = database->pSeniorList;
        while (curr->pNext != NULL && strcmp(stud->pStudent->name, curr->pNext->pStudent->name) > 0)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void addtoHon(Database *database, Student *student)
{
    if (student->gpa < 3.50)
    {
        return;
    }
    StudentNode *stud = (StudentNode *)malloc(sizeof(StudentNode));
    stud->pStudent = student;
    stud->pNext = NULL; // Initialize the next pointer to NULL

    if (database->pHonorRollList == NULL)
    {
        database->pHonorRollList = stud;
    }
    else if (stud->pStudent->gpa <= database->pHonorRollList->pStudent->gpa)
    {
        stud->pNext = database->pHonorRollList;
        database->pHonorRollList = stud;
        return;
    }
    else
    {
        StudentNode *curr = database->pHonorRollList;
        while (curr->pNext != NULL && curr->pNext->pStudent->gpa < stud->pStudent->gpa)
        {
            curr = curr->pNext;
        }
        stud->pNext = curr->pNext;
        curr->pNext = stud;
    }
}

void displayId(Database *database)
{
    if (database->pIDList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    int i = 0;
    StudentNode *curr = database->pIDList;
    while (curr != NULL && i < 10)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
        i++;
    }
}

void displayprobation(Database *database)
{
    if (database->pAcademicProbationList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pAcademicProbationList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void displayHonorRoll(Database *database)
{
    if (database->pHonorRollList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pHonorRollList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void displayFresh(Database *database)
{
    if (database->pFreshmanList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pFreshmanList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void displaySoph(Database *database)
{
    if (database->pSophomoreList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pSophomoreList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void displayJun(Database *database)
{
    if (database->pJuniorList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pJuniorList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void displaySen(Database *database)
{
    if (database->pSeniorList == NULL)
    {
        printf("There are no students matching that criteria.\n");
        return;
    }
    StudentNode *curr = database->pSeniorList;
    while (curr != NULL)
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
        curr = curr->pNext;
    }
}

void findstudent(Database *database, char *id)
{
    StudentNode *curr = database->pIDList;
    while (curr != NULL && strcmp(curr->pStudent->id, id) != 0)
    {
        if (curr->pStudent->id == id)
        {
            break;
        }
        else
        {
            curr = curr->pNext;
        }
    }
    if (curr == NULL)
    {
        printf("Sorry, there is no student in the database with the id %s.\n", id);
        return;
    }
    else
    {
        printf("%s:\n", curr->pStudent->name);
        printf("\t\tID - %s\n", curr->pStudent->id);
        printf("\t\tGPA - %.2f\n", curr->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", curr->pStudent->creditHours);
    }
}

int intfindstudent(Database *database, char *id)
{
    StudentNode *curr = database->pIDList;
    while (curr != NULL && strcmp(curr->pStudent->id, id) != 0)
    {
        if (curr->pStudent->id == id)
        {
            break;
        }
        else
        {
            curr = curr->pNext;
        }
    }
    if (curr == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void deleteStudentFromList(StudentNode **head, char *string)
{
    StudentNode *prev = NULL, *curr = *head;
    while (curr != NULL)
    {
        if (strcmp(curr->pStudent->id, string) == 0)
        {
            if (prev == NULL)
            {
                *head = curr->pNext;
            }
            else
            {
                prev->pNext = curr->pNext;
            }
            curr->pNext = NULL;
            curr->pStudent = NULL;
            free(curr->pStudent);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->pNext;
    }
}

void deleteStudentFromIdList(StudentNode **head, char *string)
{
    StudentNode *prev = NULL, *curr = *head;
    while (curr != NULL)
    {
        if (strcmp(curr->pStudent->id, string) == 0)
        {
            if (prev == NULL)
            {
                *head = curr->pNext;
            }
            else
            {
                prev->pNext = curr->pNext;
            }
            curr->pNext = NULL;
            Student *student = curr->pStudent;
            free(curr->pStudent->id);
            free(curr->pStudent->name);
            free(student);
            curr->pStudent = NULL;
            free(curr->pNext);
            free(curr->pStudent);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->pNext;
    }
}

void deletestudent(Database *database, char *string)
{
    deleteStudentFromList(&database->pHonorRollList, string);
    deleteStudentFromList(&database->pAcademicProbationList, string);
    deleteStudentFromList(&database->pFreshmanList, string);
    deleteStudentFromList(&database->pSophomoreList, string);
    deleteStudentFromList(&database->pJuniorList, string);
    deleteStudentFromList(&database->pSeniorList, string);
    deleteStudentFromIdList(&database->pIDList, string);
}

void deleteList(StudentNode **head)
{
    StudentNode *current = *head;
    StudentNode *temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->pNext;
        temp->pNext = NULL;
        temp->pStudent = NULL;
        free(temp);
    }
    *head = NULL;
    free(*head);
}

void deleteIdList(StudentNode **head)
{
    StudentNode *current = *head;
    StudentNode *temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->pNext;
        free(temp->pStudent->id);
        free(temp->pStudent->name);
        free(temp->pStudent);
        free(temp);
    }
    *head = NULL;
}

void deleteDatabase(Database *database)
{
    // Delete all lists
    deleteList(&database->pHonorRollList);
    deleteList(&database->pAcademicProbationList);
    deleteList(&database->pFreshmanList);
    deleteList(&database->pSophomoreList);
    deleteList(&database->pJuniorList);
    deleteList(&database->pSeniorList);
    deleteIdList(&database->pIDList);
}

void beggining()
{
    printf("CS 211, Spring 2023\n");
    printf("Program 4: Database of Students\n\n");
}

void menuR(Database *database)
{
    printf("Select one of the following: \n");
    printf("\t1) Display the head (first 10 rows) of the database\n");
    printf("\t2) Display students on the honor roll, in order of their GPA\n");
    printf("\t3) Display students on academic probation, in order of their GPA\n");
    printf("\t4) Display freshmen students, in order of their name\n");
    printf("\t5) Display sophomore students, in order of their name\n");
    printf("\t6) Display junior students, in order of their name\n");
    printf("\t7) Display senior students, in order of their name\n");
    printf("\t8) Display the information of a particular student\n");
    printf("Your choice --> ");
    char optionarr[81];
    char option;
    int valid = 0;
    while (valid != 1)
    {
        scanf(" %s", optionarr);
        if (strlen(optionarr) > 1)
        {
            printf("Sorry, that input was invalid. Please try again.\n");
            printf("Your choice --> ");
            optionarr[0] = '\0';
            continue;
        }
        option = optionarr[0];
        if (option == '1')
        {
            displayId(database);
            valid = 1;
            break;
        }
        else if (option == '2')
        {
            displayHonorRoll(database);
            valid = 1;
            break;
        }
        else if (option == '3')
        {
            displayprobation(database);
            valid = 1;
            break;
        }
        else if (option == '4')
        {
            displayFresh(database);
            valid = 1;
            break;
        }
        else if (option == '5')
        {
            displaySoph(database);
            valid = 1;
            break;
        }
        else if (option == '6')
        {
            displayJun(database);
            valid = 1;
            break;
        }
        else if (option == '7')
        {
            displaySen(database);
            valid = 1;
            break;
        }
        else if (option == '8')
        {
            char *id = (char *)malloc(sizeof(char) * 12);
            printf("Enter the id of the student to find: ");
            scanf(" %s", id);
            findstudent(database, id);
            free(id);
            printf("\n");

            valid = 1;
            break;
        }
        else
        {
            printf("Sorry, that input was invalid. Please try again.\n");
            printf("Your choice --> ");
        }
    }
}

void menuC(Database *database)
{
    char id[81];
    char name[81];
    double gpa;
    int credithours;
    printf("Enter the name of the new student: ");
    fgets(name, 81, stdin);
    if (name[0] == '\n')
    {
        fgets(name, 81, stdin);
    }
    if (name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }
    char *actualname = (char *)malloc(strlen(name) + 1);
    strcpy(actualname, name);
    printf("Enter the ID of the new student: ");
    scanf("%s", id);
    char *actualid = (char *)malloc(strlen(id) + 1);
    strcpy(actualid, id);
    printf("Enter the gpa of the new student: ");
    scanf("%lf", &gpa);
    printf("Enter the credit hours of the new student: ");
    scanf("%d", &credithours);
    Student *student = (Student *)malloc(sizeof(Student));
    student->creditHours = credithours;
    student->gpa = gpa;
    student->id = actualid;
    student->name = actualname;
    addtoId(database, student);
    addtoHon(database, student);
    addtoprobation(database, student);
    addtofreshman(database, student);
    addtosoph(database, student);
    addtoJun(database, student);
    addtoSen(database, student);
    printf("Successfully added the following student to the database!\n");
    findstudent(database, student->id);
}

void menuD(Database *database)
{
    char toget[81];
    printf("Enter the id of the student to be removed: ");
    scanf("%s", toget);
    char *id = (char *)malloc(strlen(toget) + 1);
    strcpy(id, toget);
    if (intfindstudent(database, id) == 0)
    {
        printf("Sorry, there is no student in the database with the id %s.\n", id);
    }
    else
    {
        deletestudent(database, id);
    }
    free(id);
    printf("\n");
}

void menuX(Database *database)
{
}

void menus(Database *database)
{
    char option;
    char optionarr[81];
    int valid = 0;
    while (valid != 1)
    {
        printf("\nEnter: \tC to create a new student and add them to the database,\n");
        printf("\t\tR to read from the database,\n");
        printf("\t\tD to delete a student from the database, or\n");
        printf("\t\tX to exit the program.\n");
        printf("Your choice --> ");
        scanf(" %s", optionarr);
        if (strlen(optionarr) > 1)
        {
            printf("Invalid option. Try again.\n\n");
            optionarr[0] = '\0';
            continue;
        }
        option = optionarr[0];
        if (option == 'R')
        {
            menuR(database);
            printf("\n\n");
        }
        else if (option == 'C')
        {
            menuC(database);
        }
        else if (option == 'D')
        {
            menuD(database);
        }
        else if (option == 'X')
        {
            deleteDatabase(database);
            free(database);
            return;
        }
        else
        {
            printf("Invalid option. Try again.\n\n");
            continue;
        }
    }
}

void choiceF()
{
    Database *database = (Database *)malloc(sizeof(Database));
    setdatabase(database);
    printf("Enter the name of the file you would like to use: ");
    char str[81];
    scanf(" %[^\n]", str);
    FILE *fp;
    char *line = NULL;
    size_t line_buf_size = 0;
    char *left, *middle, *right, *righter;
    int first_line = 1;
    fp = fopen(str, "r");
    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    while (getline(&line, &line_buf_size, fp) != -1)
    {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // If this is the first line, skip it
        if (first_line)
        {
            first_line = 0;
            continue;
        }
        Student *student = (Student *)malloc(sizeof(Student));
        // Parse the line into its three words separated by commas
        left = strtok(line, ",");
        middle = strtok(NULL, ",");
        right = strtok(NULL, ",");
        righter = strtok(NULL, ",");

        student->name = (char *)malloc(strlen(left) + 1);
        strcpy(student->name, left);
        student->id = (char *)malloc(strlen(middle) + 1);
        strcpy(student->id, middle);
        char *endptr; // pointer to store the end of the string
        double gpa = strtod(right, &endptr);
        endptr[0] = '\0';
        righter[strlen(righter)] = '\0';
        int value = strtol(righter, &endptr, 10);

        student->gpa = gpa;
        student->creditHours = value;
        addtoId(database, student);
        addtoprobation(database, student);
        addtofreshman(database, student);
        addtoHon(database, student);
        addtoJun(database, student);
        addtoSen(database, student);
        addtosoph(database, student);
    }
    free(line);
    fclose(fp);
    menus(database);
}

int main()
{
    beggining();
    char optionarr[81];
    char option;
    printf("Enter E to start with an empty database, \n");
    printf("or F to start with a database that has information on students from a file.\n");
    printf("Your choice --> ");
    int valid = 0;
    while (valid != 1)
    {
        scanf("%s", optionarr);
        if (strlen(optionarr) > 1)
        {
            printf("Sorry, that input was invalid. Please try again.\n");
            printf("Your choice --> ");
            optionarr[0] = '\0';
            continue;
        }
        option = optionarr[0];
        if (option == 'E')
        {
            valid = 1;
            break;
        }
        else if (option == 'F')
        {
            valid = 1;
            break;
        }
        else
        {
            printf("Sorry, that input was invalid. Please try again.\n");
            printf("Your choice --> ");
            valid = 0;
            continue;
        }
    }
    if (option == 'E')
    {
        Database *database = (Database *)malloc(sizeof(Database));
        setdatabase(database);
        menus(database);
    }
    if (option == 'F')
    {
        choiceF();
    }

    printf("\nThanks for playing!\n");
    printf("Exiting...\n");

    return 0;
}
