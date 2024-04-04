#include "sort.h"

/* [TODO]
   Implement function compareByName
*/

int compareByName(Student a, Student b){
   return strcmp(a.name, b.name);
};

/* [TODO]
   Implement function compareById
*/

int compareById(Student a, Student b){
   return a.id - b.id;
};

/* [TODO]
   Implement function quickSort
*/

int partition(Student *students, int left, int right, int (*compare)(Student, Student)){
    Student pivot = students[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (compare(students[j], pivot) < 0) {
            i++;
            swap(&students[i], &students[j]);
        }
    }
    swap(&students[i + 1], &students[right]);
    return i + 1;
}

void quickSort(Student *students, int left, int right, int (*compare)(Student, Student)){//right : length
   if(left < right){
      int parti = partition(students, left, right, compare);
      quickSort(students, left, parti - 1, compare);
      quickSort(students, parti + 1, right, compare);
   }
};//여따가 ID나 NAME받아와서 정렬조지기
