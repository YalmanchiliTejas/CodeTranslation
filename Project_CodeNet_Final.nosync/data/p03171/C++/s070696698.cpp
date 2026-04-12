#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAXN 3001
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define FAIL {printf("-1\n"); return 0;}

int N;
int A[MAXN];
LL dp[MAXN][MAXN][2];
int B[MAXN][MAXN][2];

LL f(int i, int j, int p) {
    if (B[i][j][p]) return dp[i][j][p];
    B[i][j][p] = 1;

    LL &ret = dp[i][j][p];
    if (i == j) 
        ret = (p == 0) ? A[i] : -A[i];
    else if (p == 0) 
        ret = max(A[i] + f(i+1,j,1-p), A[j] + f(i,j-1,1-p));
    else 
        ret = min(f(i+1,j,1-p) - A[i], f(i,j-1,1-p) - A[j]);

    return ret;
}

int main(int argc, char **argv)
{
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    printf("%lld\n", f(0,N-1,0));
    return 0;
}
