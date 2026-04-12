#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, i, j;
unsigned long long X;

unsigned long long layer[51]; //layer[i]:レベルiバーガーの厚さ
unsigned long long p[51];
unsigned long long b[51];
unsigned long long dp[51][51]; //dp[N][X]:レベルNバーガーの下からX層に含まれるパティの総数

unsigned long long solve (int N, unsigned long long X) {
    if (X == layer[N]) {
        return p[N];
    } else if (X > layer[N-1] + 2) {
        return solve(N-1, X - layer[N-1] - 2) + p[N-1] + 1;
    } else if (X == layer[N-1] + 2) {
        return p[N-1] + 1;
    } else if (X >= 2 && X < layer[N-1] + 2) {
        return solve(N-1, X-1);
    } else {
        return 0;
    }
}

int main(void) {
    cin >> N >> X;
    
    layer[0] = 1;
    p[0] = 1;
    b[0] = 0;
    //レベルNまでのバーガーの厚さを調べる
    for (i=1; i<=N; i++) {
        p[i] = p[i-1] * 2 + 1;
        b[i] = b[i-1] * 2 + 2;
        layer[i] = p[i] + b[i];
    }
    
    unsigned long long ans = solve(N, X);
    cout << ans << endl;
    
    return 0;
}
