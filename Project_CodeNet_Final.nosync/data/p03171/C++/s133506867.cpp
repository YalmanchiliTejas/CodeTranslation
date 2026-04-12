#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;
const int cmod = 998244353;
const int N = 4e5 + 5;
const int inf = 1e16 + 2;

int a[3001] , cache[3001][3001][2] , n , vis[3001][3001][2];
int dp(int l , int r , int cur) {
    if(l > r) return 0;
    int &ans = cache[l][r][cur];
    if(vis[l][r][cur]) return ans;
    vis[l][r][cur] = 1;
    if(cur) {
        ans = min(-a[l] + dp(l + 1 , r , cur^1 ) , -a[r] + dp(l , r - 1 , cur^1));
    }
    else {
         ans = max(a[l] + dp(l + 1 , r , cur^1 ) , a[r] + dp(l , r - 1 , cur^1 ));
    }
    return ans;
}
void solve(int Case) {
    cin >> n ;
    for(int i = 0 ; i < n ; i ++) cin >> a[i] ;
    cout << dp(0 , n - 1 , 0) << '\n';
    
}
/*
 */

int32_t main()
{
    fastio
    int testcase = 1;
    //cin >> testcase;
    int Case = 1;
    while(testcase --) {
        solve(Case ++);
    }
    return 0;
}
 

