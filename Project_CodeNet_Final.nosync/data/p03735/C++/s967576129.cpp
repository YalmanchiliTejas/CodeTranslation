#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<ll,int>> a(n), b(n);
    ll ma = 0, mi = 1001001001;
    rep(i,n){
        ll x, y; cin >> x >> y; if(x > y) swap(x,y); // x <= y にする
        a[i] = make_pair(x,i);
        b[i] = make_pair(y,i);
        chmax(ma,y); chmin(mi,x);
    }

    ll s1 = 0, s2 = 1001001001;
    rep(i,n){
        chmax(s1, a[i].first); chmin(s2, b[i].first);
    }
    ll ans = (s1 - mi) * (ma - s2);

    sort(all(a));
    s1 = 0; s2 = n-1;
    chmin(ans, (ma - mi) * (a[s2].first - a[s1].first));
    rep(i,n){
        a[i] = b[a[i].second];
        if(a[i].first > a[s2].first) s2 = i;
        if(a[i].first < a[s1].first) s1 = i;
        if(i < n-1 && a[i+1].first < a[s1].first) chmin(ans, (ma - mi) * (a[s2].first - a[i+1].first));
        else chmin(ans, (ma - mi) * (a[s2].first - a[s1].first));
    }
    cout << ans << endl;
    return 0;
}