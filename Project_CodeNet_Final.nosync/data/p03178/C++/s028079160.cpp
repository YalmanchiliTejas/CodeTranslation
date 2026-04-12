#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10005
#define MOD 1000000007
using namespace std;
using LL = long long;
char in[M];
int dp[M][102][2], d, n;
int cnt_digits(int x) {
    vector<int> dp2[2];
    dp2[0] = vector<int> (102);
    dp2[1] = vector<int> (102);
    dp2[0][0] = 1;
    int fr=0, cur=1;

    REP(i,0,x-1) {
        fill(dp2[cur].begin(), dp2[cur].end(), 0);

        REP(j,0,d-1) REP(k,0,9) {
            dp2[cur][(j+k)%d] += dp2[fr][j];
            dp2[cur][(j+k)%d] %= MOD;
        }
        swap(cur, fr);
    }
    return (dp2[fr][0] + MOD - 1) % MOD;
}
int main()
{
    scanf("%s %d", in+1, &d);
    n = strlen(in+1);

    REP(i,1,in[1]-'0'-1) dp[1][i%d][0] += 1;
    dp[1][(in[1]-'0')%d][1] += 1;

    REP(i,1,n-1) REP(j,0,d-1) REP(k,0,1) if (dp[i][j][k]) {

        int cd = in[i+1] - '0';
        REP(nd,0,9) {
            if (k==1 && nd>cd) continue;

            int i2 = i+1;
            int j2 = (j + nd) % d;
            int k2 = k==1 && nd==cd;
            dp[i2][j2][k2] += dp[i][j][k];
            dp[i2][j2][k2] %= MOD;
        }
    }

    int ans = cnt_digits(n-1);
    ans = (ans + dp[n][0][0]) % MOD;
    ans = (ans + dp[n][0][1]) % MOD;
    printf("%d\n", ans);
    return 0;
}
