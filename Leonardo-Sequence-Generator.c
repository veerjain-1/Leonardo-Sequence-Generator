/* Veer Jain, Leonardo-Sequence-Generator.c, Spring 2024
* Last updated Jan 20, 2024
*/

/* Add any includes here */
#include "Leonardo-Sequence-Generator.h"

//int g_leonardo_array[ARRAY_SIZE] = {};

/*
 * Function to compute Leonardo sequence
 */

int compute_leonardo_sequence(int init_1, int init_2, int limits){
  if ((limits < 2) || (limits > ARRAY_SIZE) || (init_1 <= 0) || (init_2 <= 0)) {
    return -1;
  }

  g_leonardo_array[0] = (init_1 < init_2) ? init_1 : init_2;
  g_leonardo_array[1] = (init_1 < init_2) ? init_2 : init_1;

  for (int i = 2; i < limits; i++) {
    int next_element = g_leonardo_array[i - 1] + g_leonardo_array[i - 2] + 1;
    if (next_element <= 0) {
      return -1; 
    }

    g_leonardo_array[i] = next_element;
  }
  return 0;

} /* compute_leonardo_sequence() */

/*
 * Function to check Leonardo sequence
 */

int check_leonardo_sequence(int limit) {
  if ((limit < 2) || (limit > ARRAY_SIZE)) {
    return -1; 
  }

  if ((g_leonardo_array[0] <= 0) || (g_leonardo_array[1] <= 0) || (g_leonardo_array[1] < g_leonardo_array[0])) {
    return -1; 
  }

  for (int i = 2; i < limit; i++) {
    if (g_leonardo_array[i] != (g_leonardo_array[i - 1] + g_leonardo_array[i - 2] + 1)) {
      return i; 
    }
  }
  return 0;
} /* check_leonardo_sequence() */