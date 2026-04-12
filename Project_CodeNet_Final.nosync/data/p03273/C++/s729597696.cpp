#include <cstdio>
using namespace std;


int main()
{
    int h, w;

    scanf("%d %d", &h, &w);

    char mass[h][w];
    char dummy;

    scanf("%c", &dummy);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%c", &mass[i][j]);
        }
        scanf("%c", &dummy);
    }

    int idx_h[h] = {0}, idx_w[w] = {0};
    bool flag = false;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mass[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            idx_h[i] = i;
            continue;
        }

        idx_h[i] = -1;
    }

    flag = false;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (mass[j][i] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            idx_w[i] = i;
            continue;
        }

        idx_w[i] = -1;
    }

    int count_h = 0;
    for (int i = 0; i < h; i++) {
        if (idx_h[i] != -1) count_h++;
    }

    int count_w = 0;
    for (int i = 0; i < w; i++) {
        if (idx_w[i] != -1) count_w++;
    }

    char ans[count_h][count_w];
    int c_h = 0, c_w = 0;

    flag = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (idx_h[i] != -1 && idx_w[j] != -1) {
                ans[c_h][c_w] = mass[idx_h[i]][idx_w[j]];
                c_w++;
                flag = true;
            }
        }
        if (flag) {
            c_h++;
            flag = false;
        }

        c_w = 0;
    }

    for (int i = 0; i < count_h; i++) {
        for (int j = 0; j < count_w; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}