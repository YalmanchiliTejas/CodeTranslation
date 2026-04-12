#include <stdio.h>

int main() {
        char buf[255];
        scanf("%s", &buf);

        bool find_a = false;
        bool find_b = false;
        for (int i = 0 ; i < 3 ; i++) {
                if (buf[i] == 'A') {
                        find_a = true;
                } else {
                        find_b = true;
                }
        }

        if (find_a && find_b) {
                printf("Yes");
        } else {
                printf("No");
        }
}