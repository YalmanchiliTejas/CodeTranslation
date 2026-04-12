#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define PII pair<int,int>
#define s second
#define f first
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x)%MOD;
        }
        p = p >> 1;
        x = (x*x)%MOD;
    }
    return res;
}
vector<int> arr;
int n;
ll dp[3005][3005];
ll prefix[3005];
ll getRangeSum(int l, int r){
    return prefix[r] - ((l-1 >= 0) ? prefix[l-1] : 0);
}
ll solve(int l, int r){
    if(l > r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    ll ans = arr[l] + solve(l+1, r);
    ans = max(ans, arr[r] + solve(l, r-1));
    return dp[l][r] = getRangeSum(l, r) - ans;
}
int main() {
    IO;
    cin >> n;
    arr.resize(n);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = arr[i] + prefix[i-1];
    }
    ll y = solve(0, n-1);
    ll x = getRangeSum(0, n-1) - y;
    cout << x - y;


    return 0;
}
