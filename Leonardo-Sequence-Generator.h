#ifndef Leonardo-Sequence-Generator_H
#define Leonardo-Sequence-Generator_H

#define ARRAY_SIZE 40
extern int g_leonardo_array[ARRAY_SIZE];

#define LEONARDO_ERROR (-1)
#define LEONARDO_CORRECT (0)

int compute_leonardo_sequence(int, int, int);
int check_leonardo_sequence(int);

#endif