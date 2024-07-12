#include "leonardo.h"

int g_leonardo_array[ARRAY_SIZE] = {0};

int compute_leonardo_sequence(int init_1, int init_2, int limit) {
    if ((limit < 2) || (limit > ARRAY_SIZE) || (init_1 <= 0) || (init_2 <= 0)) {
        return LEONARDO_ERROR;
    }

    g_leonardo_array[0] = (init_1 < init_2) ? init_1 : init_2;
    g_leonardo_array[1] = (init_1 < init_2) ? init_2 : init_1;

    for (int i = 2; i < limit; i++) {
        int next_element = g_leonardo_array[i - 1] + g_leonardo_array[i - 2] + 1;
        if (next_element <= 0) {
            return LEONARDO_ERROR;
        }

        g_leonardo_array[i] = next_element;
    }
    return 0;
}

int check_leonardo_sequence(int limit) {
    if ((limit < 2) || (limit > ARRAY_SIZE)) {
        return LEONARDO_ERROR;
    }

    if ((g_leonardo_array[0] <= 0) || (g_leonardo_array[1] <= 0) || (g_leonardo_array[1] < g_leonardo_array[0])) {
        return LEONARDO_ERROR;
    }

    for (int i = 2; i < limit; i++) {
        if (g_leonardo_array[i] != (g_leonardo_array[i - 1] + g_leonardo_array[i - 2] + 1)) {
            return i;
        }
    }
    return LEONARDO_CORRECT;
}
