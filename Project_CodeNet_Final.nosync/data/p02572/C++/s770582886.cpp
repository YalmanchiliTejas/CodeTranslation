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
#define w(x)            ll x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fio(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    fio();

    ll n;
    cin>>n;

    ll a[n];
    for(ll x=0;x<n;x++) cin>>a[x];

    ll cSum[n];
    cSum[n-1] = a[n-1];
    for(ll x=n-2;x>=0;x--) cSum[x] = (a[x] + cSum[x+1]) % mod;

    ll res = 0;
    for(ll x=0;x<n-1;x++){
        res = (res + (cSum[x+1] * a[x]) % mod) % mod;
    }

    cout<<res;

    return 0;
}