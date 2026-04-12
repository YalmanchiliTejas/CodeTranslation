#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define a_macro(args...) sum(args)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef long long ll;
const ll mod = 1e9+7;

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }
template<class T> bool uin(T &a,T b) {return a > b ? (a == b, true) : false; }
template<class T> bool uax(T &a,T b) {return a < b ? (a == b, true) : false; }
ll dp[3005][3005][2];
ll a[3005];
ll solve(int i,int j,int t){
	if(i>j)
		return 0;
	if(dp[i][j][t] != -1)
		return dp[i][j][t];
	if(t == 0)
		return	dp[i][j][0] = max(a[i] + solve(i+1,j,1),a[j] + solve(i,j-1,1));
	else
		return	dp[i][j][1] = min(solve(i+1,j,0),solve(i,j-1,0));
   
}
int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    ll n,i,j;
    cin>>n;
    ll sum=0;
    for(i=1;i<=n;++i){
    	cin>>a[i];
    	sum += a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<2*solve(1,n,0) - sum<<"\n";
    
#ifndef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1e1 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}