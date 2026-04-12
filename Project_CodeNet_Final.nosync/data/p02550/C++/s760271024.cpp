#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

vector<ll> v;
map<ll, int> mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, x, m, ret = 0; cin >> n >> x >> m;
    int idx = -1;
    for(int i=1; i<=n; i++){
        if(mp.count(x)){ idx = i; break; }
        mp[x] = i; v.push_back(x);
        ret += x;
        x *= x; x %= m;
    }
    if(mp.size() == n){ cout << ret; return 0; }
    ll sz = idx - mp[x], rem = n - idx + 1;
    ll val = 0;
    for(int i=mp[x]-1; i<v.size(); i++) val += v[i];
    ret += rem / sz * val; rem %= sz;
    for(int i=0; i<rem; i++) ret += v[mp[x]-1+i];
    cout << ret;
}