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
const int N = 1e4+7;
const int D = 1e2+7;

string k;
int d;
ll dp[N][D][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);
    cin >> k >> d;
    int n = k.size();
    // dp[i][j] = number of ways for first i digits to sum j

    REP(c,0,9)
    {
        if (c < k[0]-'0') dp[0][c%d][0] += 1;
        if (c == k[0]-'0') dp[0][c%d][1] += 1;
    }

    REP(i,1,n-1)
    {
        REP(j,0,d-1)
        {
            REP(c,0,9)
            {
                dp[i][j][0] = (dp[i][j][0]+dp[i-1][(j-c+d*10)%d][0])%MOD;
                if (c < k[i]-'0')
                {
                    dp[i][j][0] = (dp[i][j][0]+dp[i-1][(j-c+d*10)%d][1])%MOD;
                }
                if (c == k[i]-'0')
                {
                    dp[i][j][1] = dp[i-1][(j-c+d*10)%d][1];
                }
            }
            //cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
        }
    }
    cout << (dp[n-1][0][0]+dp[n-1][0][1]-1+MOD)%MOD << endl;
    return 0;
}
