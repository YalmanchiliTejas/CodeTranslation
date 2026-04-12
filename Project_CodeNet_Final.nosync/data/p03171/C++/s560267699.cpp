#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pii pair<int, int>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define jai_shree_ram  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i, a, b, d) for (int i = a; i <= b; i += d)
#define brep(i, a, b, d) for (int i = a; i >= b; i -= d)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int MAX = 1e5 + 5;
int MOD = 1e9 + 7;
////////////////////////////////

int n;
int a[3005];
int dp[3005][3005];

int best(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    
    if(l == r) return dp[l][r] = a[l];

    dp[l][r] = max(a[l] - best(l+1, r), a[r] - best(l, r-1));
    return dp[l][r];
}

int32_t main(){
    jai_shree_ram

    rep(i,0,3001,1) rep(j,0,3001,1) dp[i][j] = -1;
    
    cin >> n;
    rep(i,1,n,1) cin >> a[i];
    int sum = 0;
    rep(i,1,n,1) sum += a[i];

    int x = best(1, n);
    cout << x  << endl;
    return 0; 
}