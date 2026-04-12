#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace _gnu_pbds;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define fr(i,a,b) for(ll i = a ; i < b ; i++)
#define stoink stack<ll>
#define quu queue<ll>
#define quee queue<pair<ll,ll>>
#define vec vector <ll>
#define vecd vector<ld>
#define vg vector<vector<ll> >
#define eg vector<pair<ll,ll>>
#define vgw vector<vector<pair<ll,ll> > >
#define pa pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 100000000
#define mod (ll)(1e9+7)
#define endl '\n'
string k;   
ll d;
ll dp[105][10005][2];
ll n;
bool active = false;
ll func(ll pos,bool rest,ll sum) {
    if(pos == 1){
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    if(dp[sum][pos][rest] != -1)
        return dp[sum][pos][rest];
    ll ans = 0;
    if(rest) {
        fr(i,0,10){
            if(i + 48 == k[n - pos + 1])
                break;
            ans = (ans + func(pos - 1,false,(sum + i) % d)) % mod;
        }
        ans = (ans + func(pos - 1,true,(sum + k[n - pos + 1] - 48) % d)) % mod;
    }
    else {
        fr(i,0,10) {
            ans = (ans + func(pos - 1,false,(sum + i) % d)) % mod;        
        }
    }
    return dp[sum][pos][rest] = ans;
}   
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> k;
    cin >> d;
    n = k.length();
    ll res = 0;
    fr(i,0,10) {
        if(i + 48 == k[0])
            break;
        res = (res + func(n,false,i % d)) % mod;
    }
    res = (res + func(n,true,(k[0] - 48) % d)) % mod;
    if(res == 0)
        cout << mod - 1;
    else
        cout << res - 1;    
    return 0;
}   
