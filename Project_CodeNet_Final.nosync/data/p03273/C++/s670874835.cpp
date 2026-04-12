#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;

int h, w;
char m[maxn][maxn];
int sumr[maxn], sumc[maxn];

void init() {
    cin >> h >> w;
    for(int i = 0 ; i < h ; i++) scanf("%s", m[i]);
    
    memset(sumr, 0, sizeof(sumr));
    memset(sumc, 0, sizeof(sumc));
    
    for(int i = 0 ; i < h ; i++) {
        int sum = 0;
        for(int j = 0 ; j < w ; j++) {
            sum += (m[i][j] == '#' ? 1 : 0);
        }
        sumr[i] = sum;
    }
    
    for(int j = 0 ; j < w ; j++) {
        int sum = 0;
        for(int i = 0 ; i < h ; i++) {
            sum += (m[i][j] == '#' ? 1 : 0);
        }
        sumc[j] = sum;
    }
}

void solve() {
    for(int i = 0 ; i < h ; i++) {
        for(int j = 0 ; j < w ; j++) {
            if(sumr[i] == 0 || sumc[j] == 0) continue;
            putchar(m[i][j]);
        }
        if(sumr[i] > 0) putchar('\n');
    }
}

int main() {
    init();
    solve();
}
