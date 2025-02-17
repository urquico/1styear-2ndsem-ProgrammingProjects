#include <stdio.h>
#include <conio.h>
#include <mem.h>
#include <stdlib.h>

struct record {
	char StudNum[13];
	char Name [25];
	char CourseYear [11];
	float GWA;
	struct record *next;
};
	
	int stacks = 0;
	struct record *pushnode = NULL;
	struct record *top;
	struct record *popnode = NULL;
	struct record *temptop = NULL;
	
int main () {
	system ("CLS");
	int CaseNum;
	
	do {
		printf("\n Please choose an action: \n\n");
		printf("\t1 - Create Stack of Student Records\n");
		printf("\t2 - Display created stack of Student Records \n");
		printf("\t3 - Add another record to stack of Student Records\n");
		printf("\t4 - Delete latest record in stack of Student Records \n");
		printf("\t5 - EXIT \n\n");
		printf("  Enter the number of operation to be performed => ");
		scanf("%d",&CaseNum);	
		printf("\n\n To continue, just press any key...");
		getch();	
	} while (CaseNum>5);
	
	char Temp;
	char Resp;
	char Ans;
	int ctr = 1;
	
	switch (CaseNum) {
		case 1:					
			pushnode = (struct record*)malloc(sizeof(struct record));
			pushnode->next = NULL;
			top = pushnode;
		
			system("CLS");
	
			if((stacks == 1) && (top != NULL)) {
				printf("An existing record is available. Do you want to create new stack of record? [Y/N] ");
				scanf("%c", &Ans);
		
				if(toupper(Ans) == 'N') {
					printf("Returning to Main Menu...");
					getch();
					main();
				}
			}
	
			printf("\n------Creation of Nodes for the Stack of Student Records------\n");	
	
			do {
				printf("\nStudent Record No. %d \n", ctr);
				printf("\n\tEnter Student No. : ");
				scanf("%s",&pushnode->StudNum);
				scanf("%c", &Temp);
				printf("\tEnter Student Name: ");
				gets(pushnode->Name);
				printf("\tEnter Course and Year: ");
				gets(pushnode->CourseYear);
				printf("\tEnter GWA: ");
				scanf("%f", &pushnode->GWA);
				scanf("%c", &Temp);
				printf("\n Add another student record? [Y/N]: ");
				scanf("%c", &Resp);		
				ctr++;
		
				if(toupper(Resp) == 'Y') {
					pushnode = (struct record*)malloc(sizeof(struct record));
					pushnode->next = top;
					top = pushnode;
				}		
			}while (toupper(Resp) == 'Y');
	
			pushnode = NULL;
			stacks = 1;
			main();
			break;
			
			
		case 2:
			system("CLS");
			printf("\n------Displaying the Stack of Student Records------\n");
	
			ctr = 1;
			popnode = top;
	
			if (popnode == NULL)
				printf("\nSorry, no records are available.");
			else {
				do {
					printf("\nStudent Record No. %d\n", ctr);
					printf("\tStudent No. : %s", top->StudNum);
					printf("\n\tStudent Name : %s", top->Name);
					printf("\n\tCourse and Year : %s", top->CourseYear);
					printf("\n\tGWA : %0.2f\n", top->GWA);			
					top = top->next;
					popnode->next = NULL;			
			
					popnode->next = temptop;
					temptop = popnode;
					popnode = NULL;
			
					popnode = top;	
					ctr++;		
				}while (top != NULL);
		
				struct record *tempptr = NULL;
				tempptr = temptop;
				do {
					strcpy(tempptr->StudNum, temptop->StudNum);
					strcpy(tempptr->Name, temptop->Name);
					strcpy(tempptr->CourseYear, temptop->CourseYear);
					tempptr->GWA = temptop->GWA;
					temptop = temptop->next;
					tempptr->next = NULL; 
					tempptr->next = top;
					top = tempptr;
					tempptr = temptop;
				}while (temptop != NULL);	
			
				temptop = NULL;				
			}
			getch();
			main();
			break;
			
			
		case 3:
			pushnode = (struct record*)malloc(sizeof(struct record));
	
			system("CLS");
	
			printf("------Add NEW Student Record below.------\n");
			printf("\n\tEnter Student No. : ");
			scanf("%s",&pushnode->StudNum);
			scanf("%c", &Temp);
			printf("\tEnter Student Name: ");
			gets(pushnode->Name);
			printf("\tEnter Course and Year: ");
			gets(pushnode->CourseYear);
			printf("\tEnter GWA: ");
			scanf("%f", &pushnode->GWA);
			scanf("%c", &Temp);
	
			pushnode->next = NULL;
			if(top == NULL) {
				top = pushnode;
				stacks = 1;
			}
			else {
				pushnode->next = top;
				top = pushnode;
			}	
			
			pushnode = NULL;
			printf("\nStudent record added...");
			getch();
			main();
			break;
			
			
		case 4:
			popnode = top;
	
			system("CLS");
	
			if(popnode == NULL)
				printf("No records available...");
			else {
				top = top->next;
				popnode->next = NULL;
				printf("Record has been deleted successfully...");
			}
	
			free(popnode);
			popnode = NULL;
			getch();
			main();
			break;
			
			
		case 5:
			printf("Thank you for using the program...");
			exit(0);
			break;	
	}
	
	return 0;	
}
