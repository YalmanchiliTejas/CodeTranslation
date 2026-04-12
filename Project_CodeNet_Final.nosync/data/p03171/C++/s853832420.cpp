#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pdd, int> ptemp;
typedef pair<ll, ll> pll;
typedef pair<int, vector<int>> pivi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<int , vi> mivi;
#define rep(i,a,b) for(i=a;i<=b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define all(x)  x.begin(),x.end()
#define google(x) cout << "Case #" << x << ": ";
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
// #define MAX_N 200006
#define modulo 1000000007
// #define modulo 163577857 
// #define modulo 998244353 
#define PI 3.14159265358979323846264338327
#define ordered_set(type) tree<type, null_type, less<type>, rb_tree_tag, tree_order_statistics_node_update> 
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
ll inf = 1e9+7;
// const int maxn = (1<<20);
template<class T> ostream& operator<<(ostream &os, vector<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T> ostream& operator<<(ostream &os, set<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){
	os << "[ ";
	for(auto v  : V) os << "(" << v.first << ":" << v.second << ")";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){
	return os << "(" << V.first << "," << V.second << ")";
}
 
#define cerr cout
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
    clock_t clk=clock();
    #define checktime() cout<<"\nTime Elapsed : "<<float(clock()-clk)/CLOCKS_PER_SEC<<endl
#else
    #define trace(...);
    #define checktime();
#endif

int i,j,lol; 
const ll maxn = 1e18;

ll dp[3001][3001]; ll a[3001]; ll n;

ll solve(ll l, ll r){
    if(l > r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    dp[l][r] = max(a[l] - solve(l+1,r), a[r] - solve(l,r-1));
 
return dp[l][r];
}
int main(){
    io;
    int t = 1;
    // cin >> t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<solve(1,n)<<"\n";
    }
}