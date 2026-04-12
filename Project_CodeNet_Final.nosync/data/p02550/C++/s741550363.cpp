#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    ll x, m;
    cin >> n >> x >> m;
    vector<ll> cnt(m, -1), c;
    ll ans = 0;
    ll num = x;
    ll sum = 0;
    ll idx = -1;
    for(ll i = 0; i < n; i++){
        if(cnt[num] != -1){
            idx = i;
            break;
        }
        else cnt[num] = i;
        c.push_back(num);
        if(i == n-1) break;
        num *= num;
        num %= m;
    }

    if(idx == -1){
        for(auto p: c) ans += p;
        cout << ans << endl;
        return 0;
    }

    for(int i = 0; i < cnt[num]; i++) ans += c[i];
    
    n -= cnt[num];
    for(int i = cnt[num]; i < idx; i++) sum += c[i];
    ans += sum*(n/(idx-cnt[num]));
    
    for(int i = 0; i < n%(idx-cnt[num]); i++) ans += c[i+cnt[num]];
    cout << ans << endl;
}