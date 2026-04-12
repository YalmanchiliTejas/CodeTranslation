#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n, x, m;
    cin >> n >> x >> m;
    map<ll, int> mp;
    vector<int> p(1);
    ll t = 1;
    int s = 0;
    for(int i = 1; i <= m + 1; ++i){
        t = (t * x) % m;
        if(mp.count(t)){
            s = mp[t];
            break;
        }
        mp[t] = i;
        p.push_back(t);
    }
    int w = p.size() - 1;
    int cl = w + 1 - s;
    t = 1;
    map<ll, int> mp2;
    vector<int> p2(1);
    s = 0;
    for(int i = 1; i <= m + 1; ++i){
        while(t > w){
            t -= cl;
        }
        if(mp2.count(t)){
            s = mp2[t];
            break;
        }
        mp2[t] = i;
        p2.push_back(t);
        t = t * 2;
    }
    cl = p2.size() - s;
    ll ans = 0;
    for(int i = 1; i < s; ++i)
        ans += p[p2[i]];
    for(int i = s; i < s + cl; ++i){
        ans += p[p2[i]] * ((n - s + 1) / cl);
        if((n - s + 1) % cl > i - s)
            ans += p[p2[i]];
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}