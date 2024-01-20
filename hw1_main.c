#include "hw1.h"

#include <stdio.h>

int g_leonardo_array[ARRAY_SIZE] = {0};

/*
 * This function is used to run the functions implemented in hw1.c.
 * User input is used to determine which function to run what input
 * is passed to it. Upon completion, the function returns zero.
 */

int main() {
  int count = 0;
  int choice = 0;
  int init_1 = 0;
  int init_2 = 0;
  int ret = 0;

  while (choice != 3) {
    printf(
      "Select a function to test:\n"
      "    1) compute_leonardo_seqeuence()\n"
      "    2) check_leonardo_sequence()\n"
      "    3) exit\n"
      "Enter your choice: "
    );

    fscanf(stdin, "%d", &choice);

    int limit = 0;
    int value = 0;
    switch (choice) {
      case 1:
        printf("\nEnter the first initial value: ");
        fscanf(stdin, "%d", &init_1);
        printf("Enter the second initial value: ");
        fscanf(stdin, "%d", &init_2);
        printf("Enter a limit: ");
        fscanf(stdin, "%d", &limit);
        if (limit > ARRAY_SIZE) {
          printf(
            "You should choose a limit less than %d!\n",
            ARRAY_SIZE + 1
          );
        }
        else {
          ret = compute_leonardo_sequence(init_1, init_2, limit);
          if (ret == LEONARDO_ERROR) {
            printf(
              "compute_leonardo_sequence()"
              " returned LEONARDO_ERROR\n\n"
            );
          }
          else {
            printf("The resulting sequence looks like:\n");
            for (count = 0; count < limit; count++) {
              printf("%d\t", g_leonardo_array[count]);
              if (count % 10 == 9) {
                printf("\n");
              }
            }
            if (limit % 10 != 0) {
              printf("\n");
            } 
          }
        }
        printf("\n");
        break;

      case 2:
        printf("\nEnter a Limit: ");
        fscanf(stdin, "%d", &limit);
        printf("Enter %d numbers to put into the array.\n", limit);
        for (count = 0; count < limit; count++) {
          printf("Element %2d: ", count);
          fscanf(stdin, "%d", &value);
          g_leonardo_array[count] = value;
        }

        ret = check_leonardo_sequence(limit);
        if (ret == LEONARDO_ERROR) {
          printf(
            "check_leonardo_sequence() returned"
            " LEONARDO_ERROR!\n\n"
          );
        }
        else if (ret == LEONARDO_CORRECT) {
          printf(
            "check_leonardo_sequence() returned"
            " LEONARDO_CORRECT!\n\n"
          );
        }
        else {
          printf(
            "The Leonardo sequence contains an error at"
            " index %d!\n\n", ret
          );
        }
        break;

      case 3:
        printf("\nGoodbye!\n\n");
        break;

      default:
        printf("\nSelect one of the given options...!\n\n");
        break;
    }
  }

  return 0;
} /* main() */