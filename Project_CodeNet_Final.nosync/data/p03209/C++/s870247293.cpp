/**
 * File              : d.cpp
 * Author            : recurze
 * Date              : 21:35 18.01.2019
 * Last Modified Date: 21:45 18.01.2019
 */
#include <stdio.h>

void readInput();
void solve(int n, long long x);
void printAns();

int main() {
    int t = 1;
    //scanf("%d", &t);

    for (int tc = 1; tc <= t; ++tc) {
        readInput();
        printAns();
    }
}

const int N = 1010101;

int n = 0;
long long x = 0;
void readInput() {
    scanf("%d%lld", &n, &x);
    solve(n, x);
}

long long lengthOf(int n) {
    return (1LL << (n + 2)) - 3;
}

long long n_patty(int n) {
    return (1LL << (n + 1)) - 1;
}

long long ans = 0;
void solve(int n, long long x) {
    if (n == 0) {
        ans += (!!x);
        return;
    } if (x == 0) {
        return;
    }
    --x;

    long long y = lengthOf(n - 1);
    if (x <= y) {
        return solve(n - 1, x);
    }

    x -= y + 1;
    ans += n_patty(n - 1) + 1;
    solve(n - 1, x);
}

void printAns() {
    printf("%lld\n", ans);
}
