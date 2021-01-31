#include <stdio.h>
#include <string.h>
#include "student.h"

void option1()
{
    student enrolled;

    FILE *input = fopen("SV2021.dat", "r+b");
    
	while (fscanf(input, "%[^\t]\t%lf\n", enrolled.name, &enrolled.score) != EOF)
    {
        printf("- %s\t%.2f\n", enrolled.name, enrolled.score);
    }
    fclose(input);
}

void option2()
{
    student added;

    FILE *input = fopen("SV2021.dat", "a+b");

    printf("Enter name: ");
    getchar();
    gets(added.name);
    printf("Enter score: ");
    scanf("%f", &added.score);
    fprintf(input, "%*s\t %.2f\n", 160, added.name, added.score);
    
	fclose(input);
}

void option3(void)
{
    student SV2021;
    char search[160];
    int count = 0;

    FILE *input = fopen("SV2021.dat", "r+b");

    printf("Enter name: ");
    getchar();
    gets(search);

    while (fscanf(input, "%[^\t]\t%lf\n",SV2021.name, &SV2021.score) != EOF)
    {
        if (strstr(SV2021.name, search) != NULL)
        {
            printf("%*s\t %.2lf\n", 160,SV2021.name, SV2021.score);
            count++;
        }
    }
    if (count == 0)
        printf("No result!\n");

    fclose(input);
}

int main(void)
{
    int option;

	while (option != 4)
    {
        printf("\n");
        printf("1. Xem danh sach sinh vien\n");
        printf("2. Nhap them sinh vien\n");
        printf("3. Tim sinh vien theo ten\n");
        printf("4. Thoat\n");

        printf("Lua chon hanh dong can thuc thi: ");
    	scanf("%d", &option);
		if (option == 1)
        	option1();
        else if (option == 2)
        	option2();
        else if (option == 3)
			option3();
		else if (option == 4)
			break;
        printf("\n");
    }

}


