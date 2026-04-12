#include<bits/stdc++.h>
//#include<tr1/unordered_map>
#pragma GCC optimize ("Ofast")
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forn(i, n) for(int i=0; i<int(n); i++)
#define Forn(i, n) for(int i=1; i<=int(n); i++)

using namespace std;

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;*/

int n;
ll a[200010];
ll oddsuf[200010];
ll dp[200010];
const ll inf = 1LL<<60;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin >> n;
    Forn(i, n) cin >> a[i];
    ll nowsum = 0;
    for(int i = 1; i<=n; i+=2)
    {
        nowsum += a[n+1-i];
        oddsuf[i] = nowsum;
    }
    dp[2] = max(a[n], a[n-1]);
    for(int i=3; i<=n; i++)
    {
        ll ans = -inf;
        if(i%2 == 0)
        {
            ans = max(ans, a[n-i+1] + dp[i-2]);
            ans = max(ans, a[n-i+2] + oddsuf[i-3]);
        }
        else
        {
            ans = max(ans, a[n-i+1] + dp[i-2]);
            ans = max(ans, a[n-i+2] + dp[i-3]);
            ans = max(ans, oddsuf[i-2]);
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;
}
