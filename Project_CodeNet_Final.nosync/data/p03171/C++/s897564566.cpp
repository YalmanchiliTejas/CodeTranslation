#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define stdi(in) freopen(in, "r", stdin)
#define stdo(out) freopen(out, "w", stdout)
#define stdio(in, out) stdi(in); stdo(out)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MAX 100007
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>

//const ll modd = 998244353;
const ll inf = 1e18;

int n;
ll arr[3002];
ll dp[3002][3002][2];

double solve(int l, int r, int ch){
    if(l>r) return 0;
    //if(l==r) return arr[l];

    if(dp[l][r][ch]!=-1) return dp[l][r][ch];

    if(ch == 0){
        ll ans = arr[l]+solve(l+1, r, ch^1);
        ll ans1 = arr[r]+solve(l, r-1, ch^1);
        return dp[l][r][ch] = max(ans, ans1);

    }

    ll ans = solve(l+1, r, ch^1)-arr[l];
    ll ans1 = solve(l, r-1, ch^1)-arr[r];
    return dp[l][r][ch] = min(ans, ans1);

}

int main(){
	/*#ifndef ONLINE_JUDGE
        stdio("in", "out");
    #endif*/
    fast;
    cin>>n;

    for(int i=0;i<3002;i++){
        for(int j=0;j<3002;j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }

    ll ans = solve(0,n-1,0);

    cout<<ans<<'\n';

	return 0;
}

