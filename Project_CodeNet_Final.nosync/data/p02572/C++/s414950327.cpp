#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
// #define INT_MAX 1000000000 this is wrong as INT_MAX is already included in header<climits> and  2147483647  
// #define INT_MIN -1000000000
#define INF 1000000000
#define LL_MAX 1000000000000000000
#define LL_MIN -1000000000000000000
#define mod1 1000000007
#define ll long long 
#define ld long double
#define vi vector <int>
#define vvi vector <vector<int>>
#define vll vector<long long>
#define vvl vector <vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pair<int,int>>
#define pld pair<ld,ld>
#define vpll vector<pair<ll,ll>>
#define vpld vector<pair<ld,ld>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define sz(a) (int)a.size()
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

template<class T>
T binpow(T a, T b, T m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
	int n;
    cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    b[n-1]=0;
    for(int i=n-2;i>=0;i--)b[i]=(b[i+1]+a[i+1])%mod1;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=(a[i]*b[i])%mod1;
        sum%=mod1;
    }
    cout<<sum<<endl;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/

