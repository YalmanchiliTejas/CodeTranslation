#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#define IOS ios::sync_with_stdio(0)
#define ull unsigned ll
#define uint unsigned
#define pai pair<int,int>
#define pal pair<ll,ll>
#define IT iterator
#define pb push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
int a[man];
ll pre[man];

signed main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int n;cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        pre[i] %= mod;
    }
    ll res = 0;
    for(int i = 2;i <= n;++i){
        ll tp = 1ll * a[i-1] * ((pre[n] - pre[i-1] + mod) % mod)%mod;
        res = res + tp;
        res %= mod;
    }
    cout<<res<<endl;
    return 0;
}