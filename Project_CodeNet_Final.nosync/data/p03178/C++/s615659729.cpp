#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define N               200005
#define ff              first
#define ss              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define inp(arr,n)      for(ll x=0;x<n;x++) cin>>arr[x];
#define w(x)            ll x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fio(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

string k;
ll D, dp[10005][105][2];

ll f(ll pos, ll d, bool bound){

    if(dp[pos][d][bound] != -1) return dp[pos][d][bound];

    ll ub = bound ? k[pos] - '0' : 9;
    if(pos == k.length() - 1){
        ll ans = 0;
        for(ll x=0;x<=ub;x++){
            if(x%D == d) ans++;
        }

        return dp[pos][d][bound] = ans;
    }

    ll ans = 0;
    for(ll x=0;x<=ub;x++){
        ans = (ans + f(pos+1, (d + D - x % D) % D, bound and (ub == x))) % mod;
    }

    return dp[pos][d][bound] = ans;
}

int main(){
    fio();

    memset(dp, -1, sizeof dp);

    cin>>k;
    cin>>D;

    cout<<(f(0, 0, true) - 1 + mod) % mod;

    return 0;
}