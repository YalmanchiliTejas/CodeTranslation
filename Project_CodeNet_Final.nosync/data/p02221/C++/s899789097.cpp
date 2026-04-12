#include <cstdio>
#include <vector>
#include <functional>
#include <cassert>
#include <iostream>
using namespace std;

string s;

int win(int i, int j) {
    if (i == j) return i;
    if (i > j) swap(i, j);
    return s[j - i - 1] == '0' ? i : j;
}

int n;
vector<int> W[19];
int p[1<<19];

int solve(int i, int j, int k) {
    assert(i >= j);
    assert(i < 1<<n);
    assert(j >= 0);
    if (j == i + (1<<k)) return W[k][i];
    if (j == 0 && i + (1<<k) == 1<<n) return W[k][i];
    if (k == 0) return W[0][i];
    int w1, w2;
    const int h = 1 << (k-1);
    if (i + h <= 1 << n) w1 = W[k-1][i];
    else w1 = solve(i, j - h, k-1);
    if (j - h >= 0) w2 = W[k-1][j - h];
    else w2 = solve(i + h, j, k-1);
    return win(w1, w2);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < 1<<n; i++) scanf(" %d", &p[i]);
    for (int i = 0; i < 1<<n; i++) p[i+(1<<n)] = p[i];
    for (int k = 0; k <= n; k++) W[k].resize(1<<(n+1));
    for (int i = 0; i < 1<<(n+1); i++) W[0][i] = p[i];
    for (int k = 1; k <= n; k++)
        for (int i = 0; i + (1<<k) < 1<<(n+1); i++)
            W[k][i] = win(W[k-1][i], W[k-1][i + (1<<(k-1))]);

    for (int j = 0; j < 1<<n; j++) printf("%d\n", solve(j, j, n));
}

