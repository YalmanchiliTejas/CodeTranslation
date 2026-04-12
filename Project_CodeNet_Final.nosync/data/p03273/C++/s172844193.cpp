#include "bits/stdc++.h"
using namespace std;

const int N = 105;
char s[N][N];
bool row[N], col[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        bool allw = true;
        for (int j = 0; j < m; ++j) if (s[i][j] == '#') allw = false;
        if (allw) row[i] = true;
    }

    for (int j = 0; j < m; ++j) {
        bool allw = true;
        for (int i = 0; i < n; ++i) if (s[i][j] == '#') allw = false;
        if (allw) col[j] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (row[i]) continue;
        for (int j = 0; j < m; ++j) {
            if (col[j]) continue;
            printf("%c", s[i][j]);
        }
        puts("");
    }
}