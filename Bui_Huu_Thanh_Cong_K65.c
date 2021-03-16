#include<stdio.h>
#include<string.h>

typedef struct
{
    int StudentID;
    char StudentName[20];
    int dd;
    int mm;
    int yyyy;
    char ClassName[15];
    char CourseName[20];
} ST;

void enter(ST list[], int N)
{
    int i;
    FILE *input = fopen("Student.dat", "a");

    for (i=0; i<N; i++)
        {
            printf("ID: ");
            scanf("%d", &list[i].StudentID);

            printf("Name: ");
            scanf("%s", list[i].StudentName);

            printf("D.O.B: ");
            scanf("%d/%d/%d", &list[i].dd, &list[i].mm, &list[i].yyyy);

            printf("Class: ");
            scanf("%s", list[i].ClassName);

            printf("Course: ");
            scanf("%s", list[i].CourseName);
        }
    fclose(input);
}

void display(ST list[], int N)
{
    FILE *input = fopen("Student.dat", "r");
    int i;
    for(i=0; i<N; i++)
    {
    while(fscanf(input, "%d\n%s\n%d/%d/%d\n%s\n%s\n\n", &list[i].StudentID, list[i].StudentName, &list[i].dd, &list[i].mm, &list[i].yyyy, list[i].ClassName, list[i].CourseName) != EOF)
    {
        printf("No  StudentID  StudentName      Birthdate ClassName      CourseName");
        printf("%d  %d  %s\n       %d/%d/%d\n  %s\n      %s\n\n", i+1, list[i].StudentID, list[i].StudentName, list[i].dd, list[i].mm, list[i].yyyy, list[i].ClassName, list[i].CourseName);
    }
    }
    fclose(input);
}


void add(ST enroll, ST list[],int N)
{
    int i;
    FILE *input = fopen("Student.dat", "a+");
    printf("Enter new ID:");
    scanf("%d", &enroll.StudentID);
    for (i=0; i<N; i++)
    {
        while(fscanf(input, "%d\n%s\n%d/%d/%d\n%s\n%s\n\n", &list[i].StudentID, list[i].StudentName, &list[i].dd, &list[i].mm, &list[i].yyyy, list[i].ClassName, list[i].CourseName) != EOF)
        {

        if(enroll.StudentID == list[i].StudentID)
            printf("Student ID already existed!");
        else
        {
            N++;
            printf("Name: ");
            scanf("%s",enroll.StudentName);
            printf("D.O.B: ");
            scanf("%d/%d/%d", &enroll.dd, &enroll.mm, &enroll.yyyy);

            printf("Class: ");
            scanf("%s",enroll.ClassName);

            printf("Course: ");
            scanf("%s",enroll.CourseName);
        }
    }
}
}

void ID_search(ST list[], int N)
{
    int i,ID;
    FILE *input = fopen("Student.dat", "r");
    printf("Enter ID:");
    scanf("%d", &ID);
    for (i=0; i<N; i++)
    {
        while(fscanf(input, "%d\n%s\n%d/%d/%d\n%s\n%s\n\n", &list[i].StudentID, list[i].StudentName, &list[i].dd, &list[i].mm, &list[i].yyyy, list[i].ClassName, list[i].CourseName) != EOF)
        {
            if(ID == list[i].StudentID)
            { printf("%d, %s, %d/%d/%d, %s, %s", list[i].StudentID, list[i].StudentName, list[i].dd, list[i].mm, list[i].yyyy, list[i].ClassName, list[i].CourseName); }
            else printf("No student is found!");
       }
}

int main()
{
    int option;

    printf("=============================================================\n");
    printf("1. Enter information the students of HUST");
    printf("2. Display the information of the entered students");
    printf("3. Sort ascending information the students by student ID");
    printf("4. Add a new student of HUST");
    printf("5. Search for students by ID");
    printf("6. Exit\n");
    printf("=============================================================\n\n");

    printf("Choose your action: ");
    scanf("%d", &option);

    while (option != 6)
    {
        if (option == 1)
            enter(list[],N);
        else if (option == 2)
            display(list[],N);
        else if (option == 4)
            add(enroll,list[],N);
        else if (option == 5)
            ID_search(list[],N);
    }
    return 0;
}




