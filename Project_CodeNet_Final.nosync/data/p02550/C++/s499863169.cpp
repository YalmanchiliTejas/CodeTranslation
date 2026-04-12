#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    vl a;
    vi used(m+1, -1);
    a.emplace_back(x);
    used[x] = 0;
    int l = -1, r = -1;
    while(1) {
        x *= x;
        x %= m;
        if(used[x] >= 0) {
            l = used[x];
            r = a.size();
            break;
        }
        else {
            used[x] = a.size();
            a.emplace_back(x);
        }
    }
    ll ans = 0;
    ll sum = 0;
    int d = r - l;
    if(n <= l) {
        rep(i, n) ans += a[i];
        cout << ans << '\n';
        return 0;
    }
    rep(i, l) ans += a[i];
    REP(i, l, r) sum += a[i];
    n -= l;
    ans += sum * (n / d);
    n %= d;
    REP(i, l, l+n){
        ans += a[i];
    }
    cout << ans << '\n';
    return 0;
}