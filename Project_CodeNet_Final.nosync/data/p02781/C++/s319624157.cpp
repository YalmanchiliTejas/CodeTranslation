#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(int i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    int dp[n+1][k+1][2];
    memset(dp , 0 , sizeof(dp));
    dp[0][0][0] = 1;
    dp[0][1][0] = s[0] - '0' - 1;
    dp[0][1][1] = 1;

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j <= k ; j++)
        {
                if(j > 0)
                dp[i][j][0] += dp[i-1][j-1][0] * 9;
                dp[i][j][0] += dp[i-1][j][0];
                if(s[i] > '0'){
                    if(j > 0)
                    dp[i][j][0] += dp[i-1][j-1][1] * (s[i] - '0' - 1);
                    dp[i][j][0] += dp[i-1][j][1];
                }

                if(s[i] == '0')dp[i][j][1] = dp[i-1][j][1];
                else if(j > 0)dp[i][j][1] = dp[i-1][j-1][1];
                // debug(i);
                // debug(j);
                // debug(dp[i][j][0]);
                // debug(dp[i][j][1]);
        }
    }

    cout << dp[n-1][k][0] + dp[n-1][k][1] << endl;
    return 0;
}