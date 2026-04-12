#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll              long long
#define pb              push_back
#define ppb             pop_back
#define endl            '\n'
#define mii             map<ll,ll>
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define vs              vector<string>
#define all(a)          (a).begin(),(a).end()
#define F               first
#define S               second
#define sz(x)           (ll)x.size()
#define hell            1000000007
#define inf             (ll)1e18 + 5
#define PI              3.14159265358979323844
#define rep(i,a,b)      for (ll i=a;i<b;i++)
#define repr(i,a,b)     for (ll i=a-1;i>=b;i--)
#define lbnd            lower_bound
#define ubnd            upper_bound
#define mp              make_pair
#define ios             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(...)      __f(#__VA_ARGS__, __VA_ARGS__)
#define SP(i)           fixed << setprecision(i) 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

using namespace std;
using namespace __gnu_pbds;

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

//primes for hashing 937,991,1013,1409,1741
ll n;
ll arr[3005];
ll dp[3005][3005][2];
ll pre[3005];

ll fin(ll st, ll l, ll ch){
	if (l<1)return 0;
	if (l==1)return arr[st];
	if (dp[st][l][ch]!=-1)return dp[st][l][ch];
	dp[st][l][ch]=max(arr[st]+(pre[st+l]-pre[st+1])-fin(st+1,l-1,!ch),arr[st+l-1]+(pre[st+l-1]-pre[st])-fin(st,l-1,!ch));
	return dp[st][l][ch];
}

void solve() {
    cin>>n;
    pre[0]=0;
    rep(i,0,n){
    	cin>>arr[i];
    	pre[i+1]=arr[i]+pre[i];
    }
    
    memset(dp,-1,sizeof dp);
    cout<<fin((ll)0,n,(ll)0)-min(fin((ll)1,n-1,(ll)1),fin((ll)0,n-1,(ll)1))<<endl;
    // rep(i,0,n+1){
    // 	rep(j,0,n+1){
    // 		trace(i,j,dp[i][j][0],dp[i][j][1]);
    // 	}
    // }
}

signed main() {
    ios
    ll test=1;
    //cin>>test;
    while (test--) solve();
    return 0;
}