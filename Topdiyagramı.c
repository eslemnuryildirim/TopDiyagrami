#include <stdio.h>

int draw_diag_step(int height, int feet_height, char the_peak_point, char the_path_point) {
    int i, j = 0;
    for (i = 0; i < height; i++) {
        printf("%c", the_path_point);
        j++;
    }
    printf("%c\n", the_peak_point);
    j++;
    for (i = height + feet_height; i < 20; i++) {
        printf(" ");
        j++;
    }
    printf("|\n");
    j++;
    return j;
}

int finish_diag(int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
    return length;
}

int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point, char the_path_point) {
    int total_chars = 0;
    int height = first_height;
    while (height >= feet_height) {
        total_chars += draw_diag_step(height, feet_height, the_peak_point, the_path_point);
        height -= feet_height;
    }
    total_chars += finish_diag(total_chars);
    return total_chars;
}

int main() {
    int result = draw_ver_diag_of_bb(20, 5, '*', '-');
    printf("Total characters: %d\n", result);
    return 0;
}

