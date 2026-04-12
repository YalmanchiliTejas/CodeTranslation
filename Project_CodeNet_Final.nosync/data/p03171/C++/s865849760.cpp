#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define lsc(x)      scanf("%lld",&x)
#define sc(x)       scanf("%d",&x)
#define lpr(x)      printf("%lld ",x)
#define pr(x)       printf("%d ",x)
#define n_l         printf("\n")
#define VI          vector<int>
#define VII         vector<long long int>
#define MI          map<int, int>
#define PI          pair<int, int>
#define m_p         make_pair
#define pb          push_back
#define fi           first
#define se           second
#define mset(x,y)   memset(x,y,sizeof(x))
#define sz(v)       (int)v.size()
#define all(v)      v.begin(), v.end()
#define fr(i, a, n) for(int i=a;i<=n;i++)
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
const int N=(int)3e3+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
int n;
ll a[N], dp[N][N];
ll fn(int i, int j){
    if (i<1 or j<1 or j>n or i>n) return 0;
    if (i==j) return a[i];
    if (i>j) return 0;
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = max(a[i] + min(fn(i+2, j), fn(i+1, j-1)), a[j] + min(fn(i, j-2), fn(i+1, j-1)));
}
int main(){
    sc(n);
    ll sum =0;
    fr(i, 1, n) {
        lsc(a[i]);
        sum +=a[i];
    }
    lpr(2*fn(1, n) - sum);n_l;
    return 0;
}

