#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

const int N = 200;

enum {
    NONE = 0,
    START = -1,
    GOAL  = -2,
};

struct Item {
    int number;
    int row;
    int col;
    int minCost;
};

int calc(int goal, vector<Item>& v) {

    for (int i = 1; i <= goal; i++) {

        For(j, v.size()) {
            if (v[j].number == i) {

                int minCost = v[j].minCost;
                For(k, v.size()) {
                    if (v[k].number == i-1) {
                        minCost = min(minCost,
                                      v[k].minCost + abs(v[j].row - v[k].row) + abs(v[j].col - v[k].col));
                    }
                }

                v[j].minCost = minCost;
            }
        }
    }

    For(i, v.size())
        if (v[i].number == goal)
            return v[i].minCost;

}

int main() {
    int cols, rows;
    while (2 == scanf("%d %d", &cols, &rows) && cols+rows > 0) {
        int g[N][N];

        vector<Item> v;
        For(i, rows) For(j, cols) {
            char s[10];
            scanf("%s", s);
            if (strcmp(s, "S") == 0) {
                v.push_back((Item){ 0, i, j, 0 });
            }
            else if (strcmp(s, "G") == 0) {
                v.push_back((Item){ -1, i, j, INT_MAX });
            }
            else if (isdigit(s[0])) {
                v.push_back((Item){ atoi(s), i, j, INT_MAX });
            }
        }

        int goal = -1;
        For(i, v.size()) {
            goal = max(goal, v[i].number + 1);
        }

        For(i, v.size()) {
            if (v[i].number == -1) {
                v[i].number = goal;
                break;
            }
        }

        printf("%d\n", calc(goal, v));
    }
}