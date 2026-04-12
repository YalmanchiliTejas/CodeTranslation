#include <stdio.h>
#include <iostream>

using namespace std;

char a[110][110];

int main()
{
    int H, W;
    scanf("%d %d\n", &H, &W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        bool flag = false;
        for (int j = 0; j < W; j++) {

            if (a[i][j] == '#') {
                flag = true;
                printf("%c", a[i][j]);

            } else {
                bool flag1 = false;
                for (size_t k = 0; k < H; k++) {
                    if (a[k][j] == '#') {
                        flag1 = true;
                        break;
                    }
                }

                bool flag2 = false;
                for (size_t k = 0; k < W; k++) {
                    if (a[i][k] == '#') {
                        flag2 = true;
                        break;
                    }
                }

                if (flag1 && flag2) {
                    flag = true;
                    printf(".");
                }

            }


        }

        if (flag) {
            printf("\n");
        }

    }

    return 0;
}
