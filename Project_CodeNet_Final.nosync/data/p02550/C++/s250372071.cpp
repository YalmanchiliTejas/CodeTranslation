#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x, m;
    cin >> n >> x >> m;

    ll prev = x;
    vector<ll> a;
    a.push_back(x);
    vector<ll> mods(m, -1);
    ll t = -1;
    ll si = -1;
    rep1(i, n){
        ll curr = prev*prev % m;
        if(mods[curr] == -1) mods[curr] = i;
        else{
            t = i - mods[curr];
            si = mods[curr];
            break;
        }
        a.push_back(curr);
        prev = curr;
    }
    // rep(i, a.size()) cout << a[i] << " ";
    // cout << endl;
    if(t == -1){
        ll res = 0;
        rep(i, static_cast<int>(a.size())) res += a[i];
        cout << res << endl;
        return 0;
    }

    ll res = 0;
    rep(i, si) res += a[i];
    ll loop = 0;
    for(int i = si; i < si+t; ++i) loop += a[i];
    ll times = (n-si) / t;
    res += loop * times;
    ll remain = (n-si) % t;
    for(int i = si; i < si+remain; ++i) res += a[i];
    // cout << si << " " << t << " " << loop << " " << times << " " << remain << endl;

    cout << res << endl;


    return 0;
}