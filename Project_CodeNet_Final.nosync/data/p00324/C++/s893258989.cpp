#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
template<class T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<class T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
const int INF = 1e18, MOD = 1e9 + 7;
signed main() {
    INCANT;
    int n, d[222222], sum[222222] = {}, res = -INF;
    bool flag = false;
    map<int, vector<int>> m;
    cin>>n;
    rep(i, n){
        cin>>d[i];
        sum[i + 1] = sum[i] + d[i];
        m[sum[i]].push_back(i - 1);
    }
    m[sum[n]].push_back(n - 1);
    each(p, m){
        if(p.second.size() == 1) continue;
        flag = true;
        sort(all(p.second));
        chmax(res, p.second[p.second.size() - 1] - p.second[0]);
    }
    if(flag) cout<<res<<endl;
    else cout<<0<<endl;
}

