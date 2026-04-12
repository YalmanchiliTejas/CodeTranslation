#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);
vector<pii> seg[4*maxn];
vector<ll> fat(maxn, -1), inv(maxn, -1);
vector<ll> v(maxn + 1);

ll fexp(ll base, ll p){
    ll ans = 1;

    while (p){
        if(p&1) ans = (ans * base)%mod;
        base = (base * base)% mod;
        p = p >> 1;
    }
    return ans;
}

void init(){
    fat[0] = fat[1] = inv[1] = 1;
    for (ll i=2; i<maxn; i++){
        fat[i] = (fat[i-1] * i)%mod;
        inv[i] = fexp(fat[i], mod-2);
    }
}

ll combina(ll n, ll k){
    if (n == k || k == 0) return 1;
    if (n < k) return 0;

    return (((fat[n] * inv[k])%mod)*inv[n - k])%mod;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    string s;
    cin >> s;

    if (s == "AAA" ||s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}