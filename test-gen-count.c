// This is a simple test client for the gen_count function

// You should modify this test client or create your own

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "gen-count.h"

// even(pint) determines if *pint is an even integer
// requires: pint is a pointer to an int [not asserted]
//           pint is not NULL
bool even(void *pint) {
  assert(pint);
  const int *p = pint;
  return *p % 2 == 0; 
}

int main(void) {
  const int arr_len = 5;
  int arr[5] = {1, 2, 3, 4, 5};
  //printf("%d", gen_count(arr, arr_len, sizeof(int), even));
  assert(gen_count(arr, arr_len, sizeof(int), even) == 2);
  char *strings[5] = {"hotdog", "h", "hotdog", "true", "false"};
  //printf("%d", count_hotdog(strings, 5));
  assert(count_hotdog(strings, 5) == 2);
  struct posn p;
  p.x = 2;
  p.y = 2;
  struct posn pp;
  pp.x = 3;
  pp.y = 4;
  struct posn ppp;
  ppp.x = 4;
  ppp.y = 4;
  struct posn pppp[3] = {p, pp, ppp};
  assert(count_circle(pppp, 3) == 2);
}
