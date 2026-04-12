#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    
    // 普通にaピザをx枚、bピザをy枚買った場合の金額
    ll ans = a*x + b*y;

    // ABピザ2枚を組み合わせて少ない方を満たす場合
    if(x > y) chmin(ans, 2*y*c + (x-y)*a);
    else if(x < y) chmin(ans, 2*x*c + (y-x)*b);

    // 全部ABピザ2枚の組み合わせで作る場合
    chmin(ans, max(x, y)*2*c);

    // 出力
    cout << ans << endl;
}