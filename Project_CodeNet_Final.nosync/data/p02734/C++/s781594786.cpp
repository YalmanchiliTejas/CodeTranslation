#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 998244353;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll dp[3001][3001];

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> vi(n);
    REP(i, n)
    cin >> vi[i];
    dp[0][0]=1;
    FOR(i,1,n+1) {
        REP(j,s+1){
            dp[i][j]=dp[i-1][j];
            if(j-vi[i-1]>0)
            dp[i][j]+=dp[i-1][j-vi[i-1]];
            if(j-vi[i-1]==0)
            dp[i][j]+=dp[i-1][j-vi[i-1]]*(i);
            dp[i][j]%=MOD;
        }
    }
    ll ans=0;
    FOR(i,1,n+1){
        ans+=(dp[i][s]-dp[i-1][s])*(n-i+1)+(ll)MOD*3002LL;
        ans%=MOD;
    }
    cout << ans << endl;
}