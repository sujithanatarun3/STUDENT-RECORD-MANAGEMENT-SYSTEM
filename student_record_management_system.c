#include<stdio.h>
   #include<stdlib.h>
   #include<string.h>
   #include<unistd.h>
   typedef struct student
   {
   int rollno;
   char name[20];
   float percentage;
  struct student *next;
  }SLL;
  
  void add_student(SLL**);
  void delete_node(SLL**);
  void print_node(SLL*);
  void modify_node(SLL**);
  void save_file(SLL*);
  void load_file(SLL**);
  void sort_data(SLL*);
  int count_node(SLL*);
  void delete_all(SLL**);
  void reverse_links(SLL**);
  ************************************************
 
   int main()
   {
          SLL *headptr=0;
          int c;
          char ch;
          load_file(&headptr);
          while(1)
          {
                  printf("-------------------\n");
                  printf("STUDENT RECORD MENU\n");
                  printf("-------------------\n");
                  printf("a/A:Add new record \n");
                  printf("d/D:Delete a record \n");
                  printf("s/S:Show the list \n");
                  printf("m/M:Modify a record \n");
                  printf("v/V:save records \n");
                  printf("e/E:Exit \n");
                  printf("t/T:Sort the list \n");
                  printf("l/L:Delete all the records \n");
                  printf("r/R:Reverse the list\n");
                  printf("Enter your choice\n");
                  scanf("%c",&ch);
                  switch(ch)
                  {
                          case 'a':
                          case 'A':
                                  add_student(&headptr);
                                  break;
                          case 'd':
                          case 'D':
                                  delete_node(&headptr);
                                  break;
                          case 's':
                          case 'S':
                                  print_node(headptr);
                                  break;
                          case 'm':
                          case 'M':
                                  modify_node(&headptr);
                                  break;
                          case 'v':
                          case 'V':
                                  save_file(headptr);
                                  break;
                          case 'e':
                          case 'E':
                                  return 0;
                          case 't':
                          case 'T':
                                  sort_data(headptr);
                                  break;
                          case 'l':
                          case 'L':
                                  delete_all(&headptr);
                                  break;
                          case 'r':
                          case 'R':
                                  reverse_links(&headptr);
                                  break;
                          default:
                                  printf("Invalid choice\n");
                  }
          }
          return 0;
  }
  *******************definitions**************************************************
   void add_student(SLL**ptr)
   {
           SLL*new;
           int roll=1;
           SLL*temp;
           new=malloc(sizeof(SLL));
           temp=*ptr;
           while(temp!=0)
          {
                  if(temp->rollno==roll)
                  {
                          roll++;
                          temp=*ptr;
                  }
                  else
                  {
                          temp=temp->next;
                  }
          }
          new->rollno=roll;
          printf("Enter name:");
          scanf("%s",new->name);
          printf("Enter percentage:");
          scanf("%f",&new->percentage);
          new->next=*ptr;
          *ptr=new;
  }
  ///////////////////////////////////////////////////////////////////
  void print_node(SLL*ptr)
  {
          if(ptr==0)
          {
                  printf("No student record available\n");
                  return;
          }
          printf("-----------------------------\n");
          printf("Roll no: Name:   Percentage: \n");
          printf("-----------------------------\n");
          while(ptr)
          {
                  printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                  ptr=ptr->next;
          }
  }
  ////////////////////////////////////////////////////////////////////////////
  void delete_node(SLL**ptr)
  {
          if(*ptr==0)
          {
                  printf("No records found\n");
                  return;
          }
          char ch;
          printf("r/R:Enter roll number to delete\n");
          printf("n/N:Enter name to delete\n");
          scanf(" %c",&ch);
          if(ch=='r'||ch=='R')
          {
                  int roll;
                  printf("Enter roll number to delete\n");
                  scanf("%d",&roll);
                  SLL*del=*ptr,*prev=0;
                  while(del)
                  {
                          if(del->rollno==roll)
                          {
                                   if(del==*ptr)
                                          *ptr=del->next;
                                  else
                                          prev->next=del->next;
                                  free(del);
                                  printf("Record deleted successfully\n");
                                  return;
                          }
                          prev=del;
                          del=del->next;
                  }
                  printf("roll number not found\n");
          }
          else if(ch=='n'||ch=='N')
          {
                  char name[50];
                  printf("Enter name to delete\n");
                  scanf("%s",name);
                  SLL*del=*ptr,*prev=0;
                  while(del)
                  {
                          if(strcmp(name,del->name)==0)
                          {
                                  printf("Roll no: %d name: %s\n",del->rollno,del->name);
                                  //check same name exist or not//
                                  SLL*temp=del->next;
                                  int count=1;
                                  while(temp)
                                  {
                                          if(strcmp(name,temp->name)==0)
                                          {
                                                  printf("Roll no: %d name: %s\n",temp->rollno,temp->name);
                                                  count++;
                                          }
                                          temp=temp->next;
                                  }
                                  // if exists search by roll number and delete record//
                                  if(count>1)
                                  {
                                         int roll;
                                         printf("Enter roll number to delete\n");
                                         scanf("%d",&roll);
                                         del=*ptr;
                                         prev=0;
                                         while(del)
                                         {
                                                 if(del->rollno==roll)
                                                 {
                                                         if(del==*ptr)
                                                                 *ptr=del->next;
                                                         else
                                                                 prev->next=del->next;
                                                         free(del);
                                                         printf("Record deleted successfully\n");
                                                         return;
                                                 }
                                                 prev=del;
                                                 del=del->next;
                                         }
                                         printf("roll number notfound\n");
                                         return;
                                 }
                                 //if the name present only one time//
                                 if(del==*ptr)
                                         *ptr=del->next;
                                 else
                                         prev->next=del->next;
                            free(del);
                                 printf("Record deleted successfully\n");
                                 return;
                         }
                         prev=del;
                         del=del->next;
                 }
                 printf("name not found\n");
         }
         else
         {
                 printf("Invalid choice\n");
         }
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
 int count_node(SLL*ptr)
 {
         int c=0;
         while(ptr)
         {
                 c++;
                 ptr=ptr->next;
         }
         return c;
 }
 ///////////////////////////////////////////////////////////////////////////////////////////
 void modify_node(SLL**ptr)
 {
         SLL*temp;
         char ch;
         int roll;
         char name[50];
         float percentage;
         if(*ptr==0)
         {
                 printf("No student records found\n");
                 return;
         }
         printf("Enter the record to search for modification\n");
         printf("r/R:Search by roll number\n");
         printf("n/N:Search by name\n");
         printf("p/P:Search by percentage\n");
         printf("Enter your choice\n");
         scanf(" %c",&ch);
         //search based on roll number//
         if(ch=='r'||ch=='R')
         {
                 printf("Enter roll number\n");
                 scanf("%d",&roll);
                 temp=*ptr;
                 while(temp!=0)
                 {
                         if(temp->rollno==roll)
                         {
                                 printf("Present details:\n");
                                 printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
                                 printf("Enter new name:");
                                 scanf("%s",temp->name);
                                 printf("Enter new percentage:");
                                 scanf("%f",&temp->percentage);
                                 printf("Record modified successfully\n");
                                 return;
                         }
                         temp=temp->next;
                 }
                 printf("Roll number not found\n");
         }
 //search based on name//
         else if(ch=='n'||ch=='N')
         {
                 printf("Enter name:");
                 scanf("%s",name);
                 temp=*ptr;
                 int count=0;
                 while(temp!=0)
                 {
                         if(strcmp(temp->name,name)==0)
                         {
                                 printf("Roll no: %d Name: %s Percentage: %f\n",temp->rollno,temp->name,temp->percentage);
                                 count++;
                         }
                         temp=temp->next;
                 }
                 if(count==0)
                 {
                         printf("Name not found\n");
                         return;
                 }
                 //if name came more than one time search based on roll number and modify the record//
                 if(count>1)
                 {
                         printf("Enter roll numberto modiy\n");
                         scanf("%d",&roll);
                         temp=*ptr;
                         while(temp!=0)
                         {
                                 if(temp->rollno==roll && strcmp(temp->name,name)==0)
                                 {
                                         printf("Enter new name:");
                                         scanf("%s",temp->name);
                                         printf("Enter new percentage:");
                                         scanf("%f",&temp->percentage);
                                         printf("Record modified successfully\n");
                                         return;
                                 }
                                 temp=temp->next;
                         }
                         printf("Record not found\n");
                 }
                 else
                 {
                         temp=*ptr;
                         while(temp!=0)
                         {
                                 if(strcmp(temp->name,name)==0)
                                 {
                                         printf("Enter new name:");
                                         scanf("%s",temp->name);
                                         printf("Enter new percentage:");
                                         scanf("%f",&temp->percentage);
                                         printf("Record modified successfully\n");
                                         return;
                                 }
                                 temp=temp->next;
                         }
                 }
         }
         //search based on percentage//
         else if(ch=='p'||ch=='P')
         {
                 printf("Enter percentage:");
                 scanf("%f",&percentage);
                 temp=*ptr;
                 int count=0;
                    while(temp!=0)
                 {
                         if(temp->percentage==percentage)
                         {
                                 printf("Roll no: %d Name: %s Percentage: %2f\n",temp->rollno,temp->name,temp->percentage);
                                 count++;
                         }
                         temp=temp->next;
                 }
                 if(count==0)
                 {
                         printf("Percentage not found\n");
                         return;
                 }
                 if(count>1)
                 {
                         printf("Enter roll numberto modiy\n");
                         scanf("%d",&roll);
                         temp=*ptr;
                         while(temp!=0)
                         {
                                 if(temp->rollno==roll && temp->percentage==percentage)
                                 {
                                         printf("Enter new name:");
                                         scanf("%s",temp->name);
                                         printf("Enter new percentage:");
                                         scanf("%f",&temp->percentage);
                                         printf("Record modified successfully\n");
                                         return;
                                 }
                                 temp=temp->next;
                         }
                         printf("Record not found\n");
                 }
                 else
                 {
                         temp=*ptr;
                         while(temp!=0)
                         {
                                 if(temp->percentage==percentage)
                                 {
                                         printf("Enter new name:");
                                         scanf("%s",temp->name);
                                         printf("Enter new percentage:");
                                         scanf("%f",&temp->percentage);
                                         printf("Record modified successfully\n");
                                         return;
                                 }
                                 temp=temp->next;
                         }
                 }
         }
         else
         {
                 printf("Invalid choice\n");
         }
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////
 void save_file(SLL*ptr)
 {
         if(ptr==0)
         {
                 printf("No records found\n");
                 return;
         }
         FILE *fp=fopen("student.dat","w");
         while(ptr)
         {
                 fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                 ptr=ptr->next;
         }
         printf("Data saved in student.dat file\n");
         fclose(fp);
 }
 //////////////////////////////////////////////////////////////////////////////////////////////
 void load_file(SLL**ptr)
 {
         SLL*new,*temp;
         FILE*fp=fopen("student.dat","r");
         if(fp==0)
                 return;
         while(1)
         {
                 new=malloc(sizeof(SLL));
                if(fscanf(fp, "%d %s %f",&new->rollno,new->name,&new->percentage)!=3)
                 {
                         free(new);
                         break;
                 }
                 new->next=0;
                 if(*ptr==0)
                 {
                         *ptr=new;
                 }
                 else
                 {
                         temp=*ptr;
                         while(temp->next!=0)
                                 temp=temp->next;
                         temp->next=new;
                 }
         }
         fclose(fp);
 }
 //////////////////////////////////////////////////////////////////////////////////////////
 void delete_all(SLL**ptr)
 {
         if(*ptr==0)
         {
                 printf("No records found\n");
                 return;
         }
         int c=1;
         SLL*del=*ptr;
         while(del)
         {
                 *ptr=del->next;
                 printf("Node deleted:%d\n",c++);
                 sleep(1);
                 free(del);
                 del=*ptr;
         }
         printf("All nodes deleted\n");
 }
 /////////////////////////////////////////////////////////////////////////////////////
 void sort_data(SLL*ptr)
 {
         SLL*p1=ptr,*p2,*t;
         int i,j,c=count_node(ptr);
         char ch;
         if(ptr==0)
         {
                 printf("No records found\n");
                 return;
         }
         printf("r/R:Roll no\n");
         printf("n/N:Name\n");
         printf("p/P:Percentage\n");
         printf("Enter your choice:\n");
         scanf(" %c",&ch);
         t=malloc(sizeof(SLL));
         for(i=0;i<c-1;i++)
         {
                 p2=p1->next;
                 for(j=0;j<c-1-i;j++)
                 {
                         if((ch=='r'||ch=='R')&&p1->rollno>p2->rollno)
                         {
                                 t->rollno=p1->rollno;
                                 strcpy(t->name,p1->name);
                                 t->percentage=p1->percentage;
 
                                 p1->rollno=p2->rollno;
                                 strcpy(p1->name,p2->name);
                                 p1->percentage=p2->percentage;
 
                                 p2->rollno=t->rollno;
                                 strcpy(p2->name,t->name);
                                 p2->percentage=t->percentage;
                         }
 
                         else if((ch=='n'||ch=='N')&&strcmp(p1->name,p2->name)>0)
                         {
                                 t->rollno=p1->rollno;
                                 strcpy(t->name,p1->name);
                                 t->percentage=p1->percentage;
 
                                 p1->rollno=p2->rollno;
                                 strcpy(p1->name,p2->name);
                                 p1->percentage=p2->percentage;
 
                                 p2->rollno=t->rollno;
                                 strcpy(p2->name,t->name);
                                 p2->percentage=t->percentage;
                         }
 
                         else if((ch=='p'||ch=='P')&&p1->percentage>p2->percentage)
                         {
                                 t->rollno=p1->rollno;
                                 strcpy(t->name,p1->name);
                                 t->percentage=p1->percentage;
 
                                 p1->rollno=p2->rollno;
                                 strcpy(p1->name,p2->name);
                                 p1->percentage=p2->percentage;
 
                                 p2->rollno=t->rollno;
                                 strcpy(p2->name,t->name);
                                 p2->percentage=t->percentage;
                         }
                         p2=p2->next;
                 }
                 p1=p1->next;
         }
         free(t);
         printf("Data sorted successfully\n");
 }
 ///////////////////////////////////////////////////////////////////////////////////////////
 void reverse_links(SLL**ptr)
 {
         int c=count_node(*ptr);
         SLL **a,*t=*ptr;
         int i;
         if(*ptr==0)
         {
                 printf("No records found\n");
                 return;
         }
         if(c>1)
         {
                 a=malloc(sizeof(SLL*)*c);
                 for(i=0;i<c;i++)
                 {
                         a[i]=t;
                         t=t->next;
                 }
                 for(i=c-1;i>0;i--)
                 {
                         a[i]->next=a[i-1];
                 }
                 a[0]->next=0;
                *ptr=a[c-1];
                 free(a);
         }
 }
