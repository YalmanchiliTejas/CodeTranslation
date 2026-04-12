#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a ; i <= b ; i++)
#define REPI(i,a,b) for (int i = a ; i >= b ; i--)
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll OO = 1e18+7;
const int MOD = 1e9+7;
const int N = 3e3+7;
int n;
ll dp[N][N][2];
ll a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);

    cin >> n;
    REP(i,0,n-1) cin >> a[i];

    // dp[l][r][p] = min/max value of X-Y of range [l,r] if p start
    // p == 0 : max
    // p == 1 : min

    REP(i,0,n-1) dp[i][i][1] = -a[i],dp[i][i][0] = a[i];

    REP(len,1,n-1)
    {
        REP(l,0,n-1)
        {
            int r = l+len;
            if (r > n-1) break;

            dp[l][r][0] = max(dp[l+1][r][1]+a[l],dp[l][r-1][1]+a[r]);
            dp[l][r][1] = min(dp[l+1][r][0]-a[l],dp[l][r-1][0]-a[r]);
        }
    }
    cout << dp[0][n-1][0] << endl;
    return 0;
}
