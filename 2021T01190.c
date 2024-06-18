//Devolped by R.L.S.J.Abeygunawardhana ( 2021t01190 )
// student information management database  system.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//create structures
struct no_courses {
	char course_name[20];
    char grade[10];
	char course_id[20];
};

struct student {
	char index_n[20];
	char fullname[100];
	char department[20];
	int n;
    struct no_courses c [10]; //nested struct

};

struct course{

    char course_id[20];
    char course_name[20];
    float credit_value;
};

//menu selection
void main ()
{
	int yourchoice;
	while (yourchoice!=6)

	{
		printf("\n\t\t\t    +++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n\t\t\t    +  STUDENT INFORMATIONS MANAGEMENT DATABASE SYSTEM    +");
        printf("\n\t\t\t    +++++++++++++++++++++++++++++++++++++++++++++++++++++++");

		printf("\n\n\n\t  1.Add course Details\n");
		printf("\t  2.Add student Details\n");
		printf("\t  3.View all Students Details \n");
		printf("\t  4.View Course Details\n");
		printf("\t  5.Update Student Details\n");
		printf("\t  6.Exit\n");
		printf("\t--------------------------------------------------------------------\n\n");
		printf("Enter your choice [1 , 2 , 3 , 4 , 5 , 6 ] : ");
		scanf("%d",&yourchoice);

		switch (yourchoice)
		{
		  case 1:
            addcoursedetails(); //Add Course Details
            break;

		case 2:
			addstudent(); //Add Student Details
			break;

		case 3:
		   v_studentandcourse(); //View all Students Details
		   printf("\t\t\tPress any key to Exit...\n");
		   getch();
		   break;

        case 4:
            viwecdetails(); //View Course Details
            break;

        case 5:
            update();  //Update Student Details &
            break;

      case 6:

          printf("\n\t\t\t ....Exit....\n");  //Exit
          exit(0);
          break;
		}
	}

}


void addstudent(){
    system ("cls");
	FILE *fp;
	struct student infor;
	int n_of_courses;
	char another;


	do{

		printf("\t\t\t=== ADD YOUR STUDENT DETAILS ===\n\n\n");

		fp=fopen("student_details.txt","a");

		printf("\n\t\t\t1.Enter your Index Number          : ");
		scanf("%s",&infor.index_n);
		printf("\n\t\t\t2.Enter your Full Name             : ");
		scanf("%s",infor.fullname);
		printf("\n\t\t\t3.Enter your Department            : ");
		scanf("%s",&infor.department);
		printf("\n\t\t\t4.How many courses do you followed : ");
		scanf("%d",&n_of_courses);
		infor.n = n_of_courses;
        printf("\n");

for(int y=0;y<n_of_courses;y++){
            printf("\t\t\t\t1.Enter NO %d Course ID     : ",y+1);
            scanf(" %s",infor.c[y].course_id);
			printf("\t\t\t\t2.Enter NO %d Course name   : ",y+1);
            scanf(" %s",infor.c[y].course_name);
            printf("\t\t\t\t3.Enter your grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB') : ");
            scanf("%s",infor.c[y].grade);
            printf("\n");
        }



		if(fp==NULL){
			fprintf(stderr,"\t\t\tCan't open this file\n");

		}
		else{
			printf("\t\t\tSaved your details SUCCESSFULY.....\n\n");

		}
		fwrite(&infor,sizeof(struct student),1,fp);

		fclose(fp);

		printf("\t\t\tDo you want to add another student details ? (y/n) :\n\n");
        scanf("%s",&another);



	}while (another=='y' || another=='Y');

}
void addcoursedetails(){

FILE *cfp;
struct course st;


printf("\n\n\t\t\t\t=== ADD COURSE DETAILS ===\n\n\n");


printf("\t\t\tEnter course ID    :");
scanf("%s",&st.course_id);
printf("\t\t\tEnter course Name  :");
scanf("%s",&st.course_name);
printf("\t\t\tEnter credit value :");
scanf("%f",&st.credit_value);




       cfp=fopen("c_details.txt","a");
       fwrite(&st,sizeof(struct course),1,cfp);
       fclose(cfp);
       printf("\t\t\tSaved your details SUCCESSFULY.....\n\n");

       printf("\t\t\tDo you want to add another student details ? (y/n) :\n\n");


      char another;
      printf("\nDo you want to Add a new Course Y/N : ");
    scanf("%s",&another);

    if(another == 'Y'){
        addcoursedetails();
    }else if(another == 'y'){
        addcoursedetails();
    }else{}
}

void v_studentandcourse(){
   system("cls");
   printf("\n\n\t\t\t\t=== VIEW  STUDENTS DETAILS ===\n\n\n");


   FILE *fp;
   FILE *cfp;



   struct student infor;
   struct course st;


fp = fopen("student_details.txt","r");

    if(fp==NULL){
        printf("\n\n\t\tCan't open fp file (contains student details) !!!");
    }



while(fread(&infor,sizeof(struct student),1,fp)){

             int totalcredit=0;
             float creditGrade=0.0;
             float totalGPA=0.0;

    printf("\t\t\tFull Name : %s\n\n",infor.fullname);
    printf("\t\t\tIndex NO  : %s\n\n",infor.index_n);
    printf("\t\t\tDepartment: %s\n\n",infor.department);
    printf("\t\t\tCourses , Grades  and your final GPA : \n");
    printf("\t\t\t---------------------------------------\n");

cfp=fopen("C_details.txt","r");

      if(cfp==NULL){
                    printf("\n\n\t\tCan't open cfp file (contain Course details) !!!");
                }

    for(int t=0;t<infor.n;t++){

    while(fread(&st,sizeof(struct course),1,cfp)){

    for(int t=0;t<infor.n;t++){

 if(strcmp(infor.c[t].course_id,st.course_id)== 0){
            totalcredit+=st.credit_value;

           if(strcmp("A",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*4.0;

                        else if(strcmp("B",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*3.0;

                        else if(strcmp("C",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*2.5;

                        else if(strcmp("D",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*1.5;

                        else if(strcmp("E",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*0.0;

                        else if(strcmp("AB",infor.c[t].grade)==0)
                            creditGrade+=st.credit_value*0.0;

           }
         }
      break;
      }

               printf("\t\t\t\t* %s  :\t",infor.c[t].course_name);
               printf("%s\n",infor.c[t].grade);

        }
                fclose(cfp);
                totalGPA= creditGrade / totalcredit;
                printf("\t\t\t\t* Your GPA : %.2f\n",totalGPA);
                printf("\n\n");



        }

    fclose(fp);


}



void viwecdetails(){


printf("\n\n\t\t\t\t=== VIEW COURSE DETAILS ===\n\n\n");

FILE*cfp;
struct course st;
cfp=fopen("c_details.txt","r");


while(fread(&st,sizeof(struct course),1,cfp)){
        printf("\nCourse ID     : %s\n",st.course_id);
        printf("Course Name   : %s\n",st.course_name);
        printf("Credit Value  : %f\n",st.credit_value);
        printf("-----------------------------\n");
        printf("\n");
    }

char another;
printf("\nDo you want to Exit Y/N : ");

    scanf("%s",&another);
    if(another == 'Y'){

    }else if(another == 'y'){

    }else{
       viwecdetails ();
    }

fclose(cfp);
main();
}

void update(){
system("cls");
   printf("\n\n\t\t\t\t=== UPDATE STUDENT DETAILS ===\n\n\n");



   FILE *fp;
   FILE *new;


   char index[20];
   char another;
   int n_of_courses;

   struct student infor;

   printf("\n\n\t\t\tEnter Index Number to Update : ");
   scanf("%s",index);

   fp=fopen("Student_details.txt","r");
   new =fopen("temp.txt","w");
    int c=0;
   if(fp==NULL)
        {
            printf("\n\n\t\tCan't fp file(include student details )!!!");
            exit(1);
        }

   while(fread(&infor,sizeof(struct student),1,fp)){

         if(strcmp(infor.index_n,index)!=0)
            {
                fwrite(&infor,sizeof(struct student),1,new);
            }
        else{

            c++;
            printf("\n\t\t\t1.Enter your New Index Number          : ");
            scanf("%s",&infor.index_n);
            printf("\n\t\t\t2.Enter your New  Full Name            : ");
            scanf("%s",infor.fullname);
            printf("\n\t\t\t3.Enter your New Department            : ");
            scanf("%s",&infor.department);
            printf("\n\t\t\t4.How many courses do you followed : ");
            scanf("%d",&n_of_courses);
            infor.n = n_of_courses;
            printf("\n");

            for(int y=0;y<n_of_courses;y++){
                printf("\t\t\t\t1.Enter NO %d Course ID     : ",y+1);
                scanf(" %s",infor.c[y].course_id);
                printf("\t\t\t\t2.Enter NO %d Course name   : ",y+1);
                scanf(" %s",infor.c[y].course_name);
                printf("\t\t\t\t3.Enter your grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB') : ");
                scanf("%s",infor.c[y].grade);
                printf("\n");
            }

        fwrite(&infor,sizeof(struct student),1,new);
        }
   }
   if(c==0){
        printf("\n Invalid index");
   }
fclose(fp);
fclose(new);
remove("Student_details.txt");
rename("temp.txt","Student_details.txt");
main();

}

