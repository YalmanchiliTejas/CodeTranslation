/**
 * File              : a.cpp
 * Author            : recurze
 * Date              : 21:53 18.01.2019
 * Last Modified Date: 21:53 18.01.2019
 */
#include <stdio.h>

void readInput();
void solve();
void printAns();

int main() {
    int t = 1;
    //scanf("%d", &t);

    for (int tc = 1; tc <= t; ++tc) {
        readInput();
        solve();
        printAns();
    }
}

const int N = 1010101;

int n = 0;
void readInput() {
    scanf("%d", &n);
}

bool ans = 0;
void solve() {
    ans = (n == 5 || n == 3 || n == 7);
}

void printAns() {
    if (ans) puts("YES");
    else puts("NO");
}
