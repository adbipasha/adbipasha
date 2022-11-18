#include<stdio.h>
#include<conio.h>
void add();
void update();
void del();
void search();
struct student
	{
	int id;
	int roll;
	int grade;
	int contract;
	char name[20];
	char gender[20];
	char stream[20];
	char section[20];
	char address[20];
	char email[50];
	char mobile[50];
	char branch[50];
	};
	
void main()
{
	int choice;
	while(choice!=5)
	{
		printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Welcome      *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n <*<*<* Student Record Management >*>*>* \n");
		printf("\n 1. Add \n");
		printf("\n 2.delete \n");
		printf("\n 3.search \n");
		scanf("%d",& choice);
		switch (choice)
		{
			case 1:
				add();
				break;
				
				case 2:
					del();
					printf("enter any key to continue");
					getch();
					break;
					
					case 3:
					search();
					printf("enter any key to continue");
					getch();
					break;
					
					case 4:
					update();
					printf("enter any key to continue");
					break;
				
				
		}
	}
}
void add()
{
	char a;
	FILE *fp;
	struct student add;
	do
	{
		system("cls");
		fp=fopen("std.txt","a");
		printf("\nenter roll:\t");
		scanf("%d",&add.roll);
		printf("\nenter name:\t");
		scanf("%s",&add.name);
		 printf("\nEnter contract : ");
        scanf("%d",&add.contract);
        printf("\nEnter id: ");
        scanf("%d",&add.id);
        printf("\n Enter stream : ");
        scanf("%s",&add.stream);
        printf("\nEnter gender : ");
        scanf(" %s",&add.gender);
        printf("\nEnter grade : ");
        scanf("%d",&add.grade);
        printf("\nEnter section : ");
        scanf("%s",&add.section);
        printf("\nEnter address : ");
        scanf("%s",&add.address);
        printf("\nEnter email address : ");
        scanf("%s",&add.email);
        
		fwrite(&add,sizeof(struct student),1,fp);
		
		printf("Do you want more:\t");
		scanf(" %c",&a);
	}while(a=='y'|| a=='Y');
	fclose(fp);
}

void search()
{
	struct student search;
	int found=0;
	int roll;
	FILE *fp;
	fp=fopen("std.txt","r");
	printf("**\n<SEARCH STUDENT>**\n");
	printf("enter roll:\t");
	scanf("%d",&roll);
	while(fread(&search,sizeof(struct student),1,fp))
	{
		if(search.roll==roll)
		{
			found=1;
			printf("  Name\t Contract \t Roll \tId \tStream\tGender\tGrade\tSection\tAddress\tEmail");
			printf("\n%s\t%d\t%d\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t",search.name,search.contract,search.roll,search.id,search.stream,search.gender,search.grade,search.section,search.address,search.email);

		}
	}
	if(!found)
	{
		printf("................Record not found...............");
	}
}

void del()
{
	struct student del;
	FILE *fp ;
	FILE *fp1;
	fp=fopen("std.txt","r");
	fp1=fopen("temp.txt","w");
	int roll;
	int found=0;
	printf("enter roll:");
	scanf("%d",&roll);
	while(fread(&del,sizeof(struct student),1,fp))
	{
		if(del.roll==roll)
		{
			found=1;
		}
		else
		{
			fwrite(&del,sizeof(struct student),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		remove("std.txt");
		rename("temp.txt","std.txt");
		printf("<<**{~RECORD DELETE %d~}**>>",roll);
	}
	if(!found)
	{
		printf("RECORD NOT FOUND");
	}
}

void update()
{
	struct student update;
	FILE *fp ;
	FILE *fp1;
	fp=fopen("std.txt","r");
	fp1=fopen("temp.txt","w");
	int roll;
	int found=0;
	printf("enter roll:");
	scanf("%d",&roll);
	while(fread(&update,sizeof(struct student),1,fp))
	{
		if(update.roll==roll)
		{
			found=1;
			printf("enter name:");
			scanf("%s",update.name);
		}

		else
		{
			fwrite(&update,sizeof(struct student),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		remove("std.txt");
		rename("temp.txt","std.txt");
		printf("<<**{~RECORD DELETE %d~}**>>",roll);
	}
	if(!found)
	{
		printf("RECORD NOT FOUND");
	}
}

