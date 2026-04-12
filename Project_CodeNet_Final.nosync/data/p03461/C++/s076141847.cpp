#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<vector<int>> d(a, vector<int> (b));
        for (int i = 0; i < a; i ++) { 
                for (int j = 0; j < b; j ++) {
                        scanf("%d", &d[i][j]);
                }
        }
        vector<vector<int>> f(110, vector<int> (110));
        for (int i = 0; i < 110; i ++) {
                for (int j = 0; j < 110; j ++) {
                        for (int k = 0; k < a; k ++) {
                                for (int l = 0; l < b; l ++) {
                                        f[i][j] = max(f[i][j], d[k][l] - (k + 1) * i - (l + 1) * j);
                                }
                        }
                }
        }
        for (int i = 0; i < a; i ++) {
                for (int j = 0; j < b; j ++) {
                        int f2 = 1 << 30;
                        for (int k = 0; k < 110; k ++) {
                                for (int l = 0; l < 110; l ++) {
                                        f2 = min(f2, f[k][l] + k * (i + 1) + l * (j + 1));
                                }
                        }
                        if (f2 != d[i][j]) {
                                puts("Impossible");
                                return 0;
                        }
                }
        }
        puts("Possible");
        printf("%d %d\n", 220, 109 + 109 + 110 * 110);
        for (int i = 0; i < 109; i ++) {
                printf("%d %d X\n", i + 1, i + 2);
        }
        for (int i = 0; i < 109; i ++) {
                printf("%d %d Y\n", i + 111, i + 112);
        }
        for (int i = 0; i < 110; i ++) {
                for (int j = 0; j < 110; j ++) {
                        printf("%d %d %d\n", i + 1, 220 - j, f[i][j]);
                }
        }
        printf("%d %d\n", 1, 220);
        return 0;
}

