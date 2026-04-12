#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define all(m) m.begin(), m.end()
#define uid uniform_int_distribution
#define init(m, x) memset(m, x, sizeof(m));
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fast;
    ll a; cin>>a;
    ll mod = 1e9+7;
    ll e1 = 0, e2 = 0;
    for(; a--;){
        ll x; cin>>x;
        e1 += x;
        e2 += x*x;
        e1 %= mod;
        e2 %= mod;
    }
    ll o = (e1*e1-e2+mod)%mod;
    o = (o*500000004)%mod;
    cout<<o;
}