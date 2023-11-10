/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// NONE
//
// Name: Ying Liu
// login ID: y2862liu
/////////////////////////////////////////////////////////////////////////////
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen-count.h"

// time: O(n)
int gen_count(void *arr, int len, size_t size, bool (*match)(void *)) {
  assert(arr);
  assert(len > 0);
  assert(size > 0);
  assert(match);
  int count = 0;
  char *arr_base = arr;
  for(int i = 0; i < len; i++){
    if(match(arr_base + i * size)){
      count ++;
    }
  }
  return count;
}


static const char *string_match = "hotdog";

// time: O(1)
bool hotdog(void *string){
  assert(string);
  const char **str = string;
  return (strcmp(string_match, str[0]) == 0);
}


// time: O(n) 
int count_hotdog(char *strings[] , int len) {
  assert(len > 0);
  assert(strings);
  return gen_count(strings, len, sizeof(char*), hotdog);
}


static const int radius = 5;

// time: O(1)
bool posn_point(void *p){
  assert(p);
  const struct posn *pp= p;
  const int a = pp->x;
  const int b = pp->y;
  return (a * a + b * b) <= (radius * radius);
}

// time: O(n)
int count_circle(struct posn points[], int len) {
  assert(points);
  assert(len > 0);
  return (gen_count(points, len, sizeof(struct posn), posn_point));
}
