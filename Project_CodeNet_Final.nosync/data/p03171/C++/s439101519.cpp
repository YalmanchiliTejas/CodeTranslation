//#############################################################################
#include "bits/stdc++.h"
//#############################################################################
//Macros 
#define MOD 1000000007
#define eb emplace_back
#define mp make_pair
#define fr first
#define sc second
#define vec vector
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define sum(v) accumulate(all(v),0LL)
//Type Defs
typedef long long ll;
typedef unsigned long long ull;
//#############################################################################
using namespace std;
//#############################################################################
//Helpers
void io_handler()
{
#ifdef LOCAL_TESTING
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template <typename T>
void print_matrix(vector<vector<T>> mat){
    for(auto row: mat){
        for(auto e : row){cout << e << " ";}
        cout << endl;
    }
}
template <typename T>
void print_vector(vector<T> v){
    for(auto e : v){cout<< e <<" ";}
    cout<<endl;
}
template <typename T>
map<T,T> get_count(vector<T> v){
    map<T,T> count;
    for(auto e: v){
        if(count.find(e)!=count.end()){count[e]++;}
        else{count[e] = 1;}}
    return count;
}
inline ll sub_sum(vec<ll> pre,ll left,ll right){
    return pre[right]-(left>0?pre[left-1]:0LL);
}
//#############################################################################
//Solution
void solve(){
    ll n; cin>>n;
    vec<ll> score(n);
    ll total = 0LL;
    vec<vec<ll>> dp(n,vec<ll>(n,0));
    for(ll i = 0LL; i<n; i++){
        cin>>score[i];
        total += score[i];
        dp[i][i] = score[i];
    }
    vec<ll> pre(n,0LL); pre[0] = score[0];
    for(ll i =1LL; i<n; i++){
        pre[i] = score[i]+pre[i-1];
    }
    //DP on intervals 
    /*
        dp[left][right] = Max score Taro can have with subarray [left,right]
    */
    for(ll ln = 2; ln<n+1; ln++){
        for(ll left = 0LL; left<n-ln+1; left++){
            ll right = left+ln-1;
            dp[left][right] = max(
            score[left] + (pre[right]-(left+1>0?pre[left]:0LL)-dp[left+1][right]),
            score[right] + (pre[right-1]-(left>0?pre[left-1]:0LL)-dp[left][right-1])
            );
        }
    }
    ll ans = dp[0][n-1]-(total-dp[0][n-1]);
    cout<<ans<<endl;
}
//#############################################################################
//Driver
int main()
{
    io_handler();
    int t = 1;
    //cin>>t;
    for (int i = 0; i < t; i++){
        solve();
    }
#ifdef LOCAL_TESTING
    cout << "⏰ Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
//#############################################################################
