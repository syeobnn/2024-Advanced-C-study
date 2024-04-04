#include "student.h"

/* [TODO]
   Implement function createStudents
*/

Student *createStudents(int n)
{
   Student *students = (Student *)malloc(n * sizeof(Student));

   if (students == NULL)
   {
      return NULL;
   }

   return students;
}

/* [TODO]
   Implement function newStudent
*/

Student newStudent(char *name, int id)
{
   Student nowStudent;
   nowStudent.name = strdup(name);
   nowStudent.id = id;
   return nowStudent;
};

/* [TODO]
   Implement function appendStudent
*/

void appendStudent(Student *students, int index, Student student)
{
   *(students + index) = student; // students[index] = student;
};

void printStudents(FILE *output, Student *students, int length)
{
   for (int i = 0; i < length; i++)
   {
      fprintf(output, "name: %s id: %d\n", students[i].name, students[i].id);
   }
}

/* [TODO]
   Implement function freeStudents
*/
void freeStudents(Student *students, int length)
{
   for (int i = 0; i < length; i++)
   {
      free(students[i].name);//구조체의 name에 할당해줘서 얘도 해제해줘야됨
   }
   free(students);
};