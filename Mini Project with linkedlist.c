/*
 * Mini project with linkedlist.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Mahmoud Ebraheem Mahmoud Elsheikhe
 */

# include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id  ;
	char name [50];
	int age ;
	float gpa ;

};

struct node{

	struct student data ;
	struct node *next ;
};
struct node *head =NULL;
//function prototypes
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
struct student *ptr=NULL;
//main program
int main (void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct student d;
	float ave =0.0;
	int choice =0;
	int id =0;


	do {

        printf("\nStudent Management System\n");
        printf("1. Add a Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student by ID\n");
        printf("4. Update Student Information\n");
        printf("5. Delete a Student\n");
        printf("6. Calculate Average GPA\n");
        printf("7. Find Student with Highest GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:

             printf("Enter ID: ");
            scanf("%d", &(d.id));

            printf("Enter name: ");
            scanf("%s", &(d.name));

            printf("Enter age: ");
            scanf("%d", &(d.age));

            printf("Enter GPA: ");
            scanf("%f",&(d.gpa));



            // Do something with the received data
            //printf("Name: %s, Age: %d, ID: %d, GPA: %.2f\n", name, age, id, gpa);
            addStudent(&d);
                 break;
        case 2:
        	displayStudents();
        	break;
        case 3:
        	printf ("enter the id to search \n");
        	scanf("%d",&id);
        	searchStudentByID(id);
        	break ;
        case 4:
        	printf ("enter the id to update\n");
        	scanf ("%d",&id);
        	updateStudent(id);
        	break ;
        case 5:
        	printf ("enter the id to delete\n");
        	scanf ("%d",&id);
        	deleteStudent(id);
        	break ;
        case 6:
        	ave =calculateAverageGPA();
        	printf("average gpa =%.2f\n",ave);
        	break;
        case 7:
        	searchHighestGPA();
        	break ;
        case 8 :
        	printf ("exiting \n");
        	return 0 ;
        default :
        	 printf("Invalid choice.\n");
        }

	}    while (choice != 8);
	return 0 ;

}
//function definitions
void addStudent(const struct student *const ptr)
{
	struct node *current =head ;
	struct node *link =NULL;
	while (current!=NULL)
	{
		if (current ->data.id ==ptr ->id )
		{
			printf ("this is id Already available\n");
			return  ;
		}
		current =current ->next;
	}
	link=(struct node *)malloc (sizeof (struct node ));
	if (link ==NULL)

	{

		printf(" not available \n");
		return ;
	}
	link ->data.id=ptr->id;
	strcpy (link ->data.name,ptr->name);
	link ->data.age=ptr->age;
	link ->data.gpa=ptr->gpa;




	if (head == NULL)
	{

		link ->data =*ptr ;
		link ->next  =NULL ;
		head =link ;
		printf ("tha studen is successed\n");
		return ;
	}
	current =head ;
	while (current ->next !=NULL)
	{
		current =current ->next ;
	}
	link ->data=*ptr ;
	link ->next  =NULL ;
    current->next =link;
    printf("the student is successed\n ");
}



void displayStudents(void)
{
struct node *current =head ;
if (current ==NULL)

   {
    printf ("There is no student  \n");
return ;
   }
while (current !=NULL)
  {
    printf ("students date \n");
    printf ("id %d\t names %s\tages%d\t gpa%.2f\n",current ->data.id
                                                  ,current ->data.name
                                                  ,current ->data.age
                                                  ,current ->data.gpa);

    current=current->next;
  }
}
void searchStudentByID(int id)
{
    struct node *current =head ;
if (head == NULL)
{
    printf("There is no student \n ");
    return ;

}
while (current !=NULL)
{
    if (current ->data.id ==id )
    {
        printf ("There is a student \n");
        printf ("id %d\t names %s\tages%d\t gpa%.2f\n",current ->data.id
                                                     ,current ->data.name
                                                     ,current ->data.age
                                                     ,current ->data.gpa);
        return ;
    }
    current=current->next ;
    }

  printf ("There is no student%d ",id);

}
void updateStudent(int id)
{
      struct node *current =head ;
      if (head ==NULL)
      {
          printf ("There is no student \n ");
          return ;
      }
    while (current !=NULL)
    {
    if (current ->data.id ==id )
        {
            printf ("enter new id  ");
            scanf("enter new id %d ",&id);
            printf("enter New name \n");

            scanf("%s",gets(current->data.name));
            printf ("enter the new age\n");
            scanf ("%d",&(current->data.age));
            printf("enter new gpa\n");
            scanf("%f",&(current->data.gpa ));
            return ;

            }
            current =current->next ;
        }
        printf("There is no student%d \n",id);

    }
   float calculateAverageGPA(void)
    {
      float sum = 0;
      int count =0;
      struct node *current=head;
      if (head ==NULL)
      {
          printf("no student\n");
          return 0.0;

      }
        while (current!=NULL)
        {
            count ++;
            sum+=current->data.gpa;
            current=current->next;
        }

        return sum /count;

    }
void searchHighestGPA(void)
{
    struct node *current=head;
    struct student store;
    store.age =0;
        if (head ==NULL)
        {
            printf("There is no student\n");
            return ;
        }
        while(current!=NULL)
        {
            if (store.gpa<=current->data.gpa)
            {
                store.gpa=current->data.gpa;
                store.id=current->data.id;
                store.age=current->data.age;
                strcpy (store.name ,current->data.name);

            }
            current=current->next;
        }
printf("student with  highest gpa\n");
printf("id %d\t name %s\t age %d\t gpa%.2f\n",store.id,store.name,store.age,store.gpa);
}

void deleteStudent(int id)
{
 struct node *current=head;
 struct node *prev=NULL;
 if (head ==NULL)
 {
     printf("There is no student\n");
     return ;

 }
 if (head ->data.id==id)
 {
     current=head;
     head =head ->next;
     free (current);
     return ;
 }
current=head ->next;
prev=head;
while(current!=NULL)
{
    if (current->data.id==id)
    {
        prev->next=current->next;
        free(current);
        printf ("student with id\n",id);
        return;
    }
    current=current->next ;
    prev=prev->next;

}
printf("There is no student \n",id);

}
