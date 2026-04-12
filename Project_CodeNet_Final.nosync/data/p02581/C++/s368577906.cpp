#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; ++i)
const int N = 2000 + 5;
const int M = 20000 + 5;
const int inf = 1000000000;
struct Modify{
    int x, y;
}up[M];
int n, m, ans, Max, a[N * 3], b[N], f[N], S[N], L[N][N], dp[N][N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int chkmax(int &a, int b){
    return a = max(a, b);
}
int main(){
    n = read();
    rep(i, 1, n * 3) a[i] = read();
    rep(i, 1, n - 1){
        int Fi = 2 + (i - 1) * 3;
        if((a[Fi + 1] == a[Fi + 2]) && (a[Fi + 2] == a[Fi + 3])) ++ans, f[i] = 1;
    }
    rep(i, 1, n) rep(j, 1, n) dp[i][j] = L[i][j] = S[i] = -inf;
    L[a[1]][a[2]] = L[a[2]][a[1]] = dp[a[1]][a[2]] = dp[a[2]][a[1]] = S[a[1]] = S[a[2]] = 0;
    rep(i, 1, n - 1){
        if(f[i]) continue;
        int Fi = 2 + (i - 1) * 3; m = 0;
        dp[a[Fi + 2]][a[Fi + 1]] = chkmax(dp[a[Fi + 1]][a[Fi + 2]], max(Max, L[a[Fi + 3]][a[Fi + 3]] + 1));
        dp[a[Fi + 3]][a[Fi + 1]] = chkmax(dp[a[Fi + 1]][a[Fi + 3]], max(Max, L[a[Fi + 2]][a[Fi + 2]] + 1));
        dp[a[Fi + 3]][a[Fi + 2]] = chkmax(dp[a[Fi + 2]][a[Fi + 3]], max(Max, L[a[Fi + 1]][a[Fi + 1]] + 1));
        up[++m].x = a[Fi + 1], up[m].y = a[Fi + 2];
        up[++m].x = a[Fi + 1], up[m].y = a[Fi + 3];
        up[++m].x = a[Fi + 2], up[m].y = a[Fi + 3];
        int A, B, C; b[1] = a[Fi + 1], b[2] = a[Fi + 2], b[3] = a[Fi + 3];
        sort(b + 1, b + 3 + 1), A = b[1], B = b[2], C = b[3];
        if(B == C) swap(A, C);
        rep(j, 1, n) if(S[j] >= 0){
            up[++m].x = j, up[m].y = A, up[++m].x = j, up[m].y = B, up[++m].x = j, up[m].y = C;
            dp[A][j] = chkmax(dp[j][A], S[j]);
            dp[B][j] = chkmax(dp[j][B], S[j]);
            dp[C][j] = chkmax(dp[j][C], S[j]);
        }
        if(A == B){
            rep(j, 1, n) if(L[j][A] >= 0){
                up[++m].x = j, up[m].y = C;
                dp[j][C] = chkmax(dp[C][j], L[j][A] + 1);
            }
        }
        rep(j, 1, m){
            int x = up[j].x, y = up[j].y;
            L[x][y] = L[y][x] = dp[x][y];
            Max = max(Max, dp[x][y]), S[x] = max(S[x], dp[x][y]), S[y] = max(S[y], dp[x][y]);
        }
    }
    printf("%d", max(Max, dp[a[n * 3]][a[n * 3]] + 1) + ans);
    return 0;
}