//  Author: Tanuj Johal
//  It's a show time, Enjoy your everyday.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll          long long
#define fio         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define vi          vector<ll>
#define pp          push_pop
#define pll         pair<ll,ll>
#define in          insert
#define ini(a,n)    memset(a,n,sizeof(a))
#define ff          first
#define ss          second
#define inf         1e18
#define all(p)      p.begin(), p.end()
#define que_max     priority_queue <int>
#define que_min     priority_queue <int, vi, greater<int>>
#define print(a)    for(auto i:a){cout<<i<<" ";}
#define print1(a)   for(auto i:a){cout<<i.ff<<" "<<i.ss<<endl;}
#define run_time cout << "\nTIME = " << clock() - tt << endl; tt = clock();

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> Set;
unordered_map<ll,set<ll>> g;
unordered_map<ll,ll> vis;
ll tt;
const ll mod = 1e9+7;

ll power(ll x,ll y,ll p){ll r=1;x=x%p;while(y>0){if(y&1)r=(r*x)%p;y=y>>1;x=(x*x)%p;}return r;}
const ll N = 2e5 + 10;
ll dx[4]={-1, +1, 0, 0};
ll dy[4]={0, 0, +1, -1};
bool imp = false;


void solve()
{

    ll n; cin>> n;
    if(n >= 30)
        cout << "Yes\n";
    else
        cout << "No\n";

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    fio
//    precompute();

    int t=1;
    if(imp) cin>>t;
    tt = clock();
    while(t--)
    {
        // cout<<"Case #"<<tc<<": ";
        g.clear();
        vis.clear();
        solve();
        // tc++;
    }
//    run_time;

}