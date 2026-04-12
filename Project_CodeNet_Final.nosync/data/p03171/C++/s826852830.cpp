#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define sz(x) (int)x.size()
#define aint(v) v.begin(), v.end()
#define in(x) cin >> x;
#define ind(x) ll (x); cin >> x;
#define ins(x) string (x); cin >> x;
#define rep(ai, j, k) for(ll ai=j; ai<=k; ai++)
#define sep(ai, j, k) for(ll ai=j; ai>=k; ai--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inputarr(x,y) for(ll ai=1; ai<=y; ai++) {cin >> x[ai];}
#define inpprefixarr(arr,y) cin>> arr[0]; for(ll ai=1;ai<y;ai++) {ll temp; cin >> temp; arr[ai]= temp + arr[ai-1];}
#define indarr(y) ll (y); cin >> y; ll arr[y+1]; inputarr(arr,y);

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watcharrsz(x) cout << (#x) << " starts:\n"; for(ll ai=0;ai<sz(x);ai++) {cout << x[ai]<<" ";} cout << "\n" << (#x) << "ends\n";
#define watcharr(x,n) cout << (#x) << " starts:\n"; for(ll ai=0;ai<n;ai++) {cout << x[ai]<<" ";} cout << "\n" << (#x) << "ends\n";
#define watchg(x,n,y) cout << (#x) << " starts:\n"; for(ll ai=0; ai<=n; ai++) {cout << (ai) << ":"; for(ll aj=0; aj<x[ai].size();aj++) {cout << x[ai][aj]<< y;} cout << "\n";}cout << "\n"<< (#x) << "ends\n";
#define watch2darr(x,m,n,y) cout << (#x) << " starts:\n"; for(ll ai=1;ai<=m;ai++) { for(ll aj=1;aj<=n;aj++) {cout << x[ai][aj]<< y;} cout << "\n";}cout << "\n"<< (#x) << "ends\n";

#define print(x,y) cout << (x) << y;
#define printarrsz(x,y) for(ll ai=0; ai<sz(x); ai++) {cout << x[ai]<< y;} cout << "\n";
#define printarr(x,n,y) for(ll ai=0; ai<n; ai++) {cout << x[ai]<< y;} cout << "\n";
#define print2darr(x,m,n,y) for(ll ai=0;ai<m;ai++) { for(ll aj=0;aj<n;aj++) {cout << x[ai][aj]<< y;} cout << "\n";}cout << "\n";
#define mod(x) = (x % m + m) % m;

const ll m = (ll)1000000007;
const ll N = 3e6+5;
const ll INF = 1ll<<63; 

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef set<ll> sl;
typedef map<ll,ll> mll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef priority_queue<pll, vpll, greater <pll> > pqg;
/***************************Code Begins Here *****************************/

ll dp[3010][3010];
ll arr[3010];
ll n;

ll dpz(ll i,ll j) {
    if(dp[i][j]>0) return dp[i][j];

    ll temp;
    if((n-(j-i))%2==0) {
        if(j-i==1) return arr[i];
        temp = -1e12;
        temp = max(dpz(i+1,j)+arr[i],dpz(i,j-1)+arr[j-1]);
    }
    else {
        if(j-i==1) return 0;
        temp = 1e13;
        temp = min(dpz(i+1,j),dpz(i,j-1));
    }
    dp[i][j] = temp;
    return dp[i][j];
}

void solve()
{
    // Never use x,y here, try to use i,j in loops only
    in(n);
    ll sum=0;
    rep(i,0,n-1) {
        in(arr[i]);
        sum+=arr[i];
    }
    ll x = dpz(0,n);
    ll y = sum - x;
    print(x-y,endl);
}

signed main()
{
    ios
    ll t=1;
    // cin>>t;

// #ifndef ONLINE_JUDGE
//     time_t time_t1, time_t2;
//     time_t1 = clock();
// #endif

    while(t--)
        solve();

// #ifndef ONLINE_JUDGE
//     time_t2 = clock();
//     cout << "time taken :" << time_t2 - time_t1 << endl;
// #endif
    return 0;
}