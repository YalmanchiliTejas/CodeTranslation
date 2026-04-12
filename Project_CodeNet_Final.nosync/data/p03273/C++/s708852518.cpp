#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
bool A[N][N], mr[N], mc[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        char c; scanf(" %c", &c);
        A[i][j] = c == '#';
    }
    for(int i = 1; i <= n; ++i) {
        bool st = true;
        for(int j = 1; j <= m; ++j) st &= !A[i][j];
        if(st) mr[i] = true;
    }
    for(int i = 1; i <= m; ++i) {
        bool st = true;
        for(int j = 1; j <= n; ++j) st &= !A[j][i];
        if(st) mc[i] = true;
    }
    for(int i = 1; i <= n; ++i) if(!mr[i]) {
        for(int j = 1; j <= m; ++j) if(!mc[j]) printf("%c", A[i][j] ? '#' : '.');
        puts("");
    }
}
