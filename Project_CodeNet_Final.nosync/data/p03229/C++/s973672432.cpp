#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
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
    ll n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a), greater<ll>());
    // a<b>c<d>e<f…と考えると、
    // nが偶数の場合; 1回減算が1種類、1回加算が1種類、2回の減算・加算が(n/2)-1種類
    // nが奇数の場合; 1回減算が2種類、2回の減算が(n/2-1)種類、2回の加算が(n/2)種類
    //       or      1回加算が2種類、2回の減算が(n/2)種類、2回の加算が(n/2)-1種類
    ll ans = 0;
    if(n%2 == 0){
        // 偶数なら
        for(ll i=0; i<(n/2)-1; i++) ans += a[i]*2;
        ans += a[n/2-1];
        ans -= a[n/2];
        for(ll i=n/2+1; i<n; i++) ans -= a[i]*2;
    }
    else{
        // 奇数なら
        ll tmp1 = 0, tmp2 = 0;
        for(ll i=0; i<(n/2)-1; i++) tmp1 += a[i]*2;
        tmp1 += a[n/2-1];
        tmp1 += a[n/2];
        for(ll i=n/2+1; i<n; i++) tmp1 -= a[i]*2;

        for(ll i=0; i<(n/2); i++) tmp2 += a[i]*2;
        tmp2 -= a[n/2];
        tmp2 -= a[n/2+1];
        for(ll i=n/2+2; i<n; i++) tmp2 -= a[i]*2;

        ans = max(tmp1, tmp2);
    }
    cout << ans << endl;
}