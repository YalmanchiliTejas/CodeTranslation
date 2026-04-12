#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int CN = 5e3+3;

int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}

int qp(int a,int b,int R) {int r = 1; while(b) {if(b & 1) r = 1ll * r * a % R; a = 1ll * a * a % R; b >>= 1;} return r;}

int n, P;

int C[CN][CN], S[CN][CN];

int main()
{
    // freopen("_in.in", "r", stdin);
    n = read(), P = read();

    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i = 2;i <= n + 10;i++){
        C[i][0] = 1;
        for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    S[0][0] = S[1][1] = 1;
    for(int i = 2;i <= n + 10;i++) 
        for(int j = 1;j <= i;j++) 
            S[i][j] = (1ll * j * S[i - 1][j] % P + S[i - 1][j - 1]) % P;

    int ans = 0;
    for(int i = 0;i <= n;i++){
        int prd = 1ll * C[n][i] * qp(2, qp(2, n - i, P - 1), P) % P, si = 0;
        for(int k = 0;k <= i;k++) si = (si + 1ll * S[i + 1][k + 1] * qp(qp(2, n - i, P), k, P) % P) % P;
        prd = 1ll * prd * si % P;
        prd = i & 1 ? P - prd : prd, ans = (ans + prd) % P;
    }

    printf("%d", ans);
}