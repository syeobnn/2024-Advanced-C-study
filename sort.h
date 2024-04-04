#pragma once

#include <string.h>
#include "student.h"
#include "utils.h"

int compareByName(Student a, Student b);

int compareById(Student a, Student b);

int partition(Student *students, int left, int right, int (*compare)(Student, Student));

void quickSort(Student *students, int left, int right, int (*compare)(Student, Student));
