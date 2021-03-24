#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 10

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus]);
void printGrades(int assigns, int stus, int grades[assigns][stus]);
void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH]);
void printStudents(int stus, char students[stus][NAME_LENGTH]);
void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[]);
void printFinalLetterGrades(int stus, double final_grades[]);
void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[]);

int main(int argc, char *argv[])
{
  FILE *ifp = NULL;
  int numStudents; 
  int numAssignments; 
 

    if(argc != 2)
    {
      printf("Syntax Error: ./<exec> <inFile>\n"); 
      exit(1); 
    }

  ifp = fopen(argv[1], "r"); 

    if(ifp == NULL)
    {
      printf("File \"%s\" failed to open for reading\n", argv[1]); 
      exit(1); 
    }

    fscanf(ifp, "%d", &numAssignments); 
    fscanf(ifp, "%d", &numStudents); 


  char studentNames[numStudents][NAME_LENGTH]; 
  int grades[numAssignments][numStudents]; 
  double finalGrades[numStudents];    

    
    
    getStudents(ifp, numStudents, studentNames);
    printStudents(numStudents, studentNames);      
    getGrades(ifp, numAssignments, numStudents, grades);    
    printGrades(numAssignments, numStudents, grades); 
    calcGrades(numAssignments, numStudents,  grades, finalGrades);
    printFinalLetterGrades(numStudents, finalGrades); 
    printf("\n\n\n"); 
    printPercentageGrades(numStudents, studentNames, finalGrades); 

      
          


    fclose(ifp); 
  
	return 0;
}

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus])
{
  
   for(int i = 0; i < assigns; i++)
    {
      
      for(int j = 0; j < stus; j++)
      {
        fscanf(ifp, "%d",  &grades[i][j]);  
      }

    }  
    
}

void printGrades(int assigns, int stus, int grades[assigns][stus])
{
    for(int i = 0; i < assigns; i++)
    {
      for(int j = 0; j < stus; j++)
      {
        printf("%10d ", grades[i][j]); 
      }
      printf("\n"); 
    }
}

void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH])
{
   for(int i = 0; i < stus; i++)
    {
      fscanf(ifp, "%s", students[i]); 
    }
}

void printStudents(int stus, char students[stus][NAME_LENGTH])
{
    for(int i = 0; i < stus; i++)
    {
      printf("%10s ", students[i]); 
    }
    printf("\n"); 
}

void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[])
{
  
  double sum;
  double avg;  
  for(int i = 0; i < stus; i++)
  {
    sum = 0; 

    for(int j = 0; j < assigns; j++)
    {
      sum = grades[j][i] + sum; 
    }

    avg = sum/assigns;
    final_grades[i] = avg; 

  }
    
}

void printFinalLetterGrades(int stus, double final_grades[])
{
  char letter; 
  for(int i = 0; i < stus; i++)
  {
    if(final_grades[i] >= 90.00)
    {
      letter = 'A'; 
    }
    else if(final_grades[i] >= 80.00)
    {
      letter = 'B'; 
    }
    else if(final_grades[i] >= 70.00)
    {
      letter = 'C'; 
    }
    else if(final_grades[i] >= 60.00)
    {
      letter = 'D'; 
    }
    else
    {
      letter = 'F'; 
    }

    printf("%10c ", letter); 
  }
  printf("\n"); 
}

void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[])
{
  for(int i = 0; i < stus; i++)
  {
    printf("%-10s : %6.2f %\n", students[i], final_grades[i]);
  }
}
