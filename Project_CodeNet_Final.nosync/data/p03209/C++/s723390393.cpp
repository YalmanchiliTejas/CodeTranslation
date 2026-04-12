#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

vector<ll> y(51, 0);
vector<ll> z(51, 0);

ll ans(int n, ll eat, ll pos) {
    if (n == 0) {
        return eat + 1;
    } else if (pos == y[n]) {
        return eat + z[n];
    } else if (pos == 0) {
        return eat;
    } else if (pos < y[n] / 2) {
        return ans(n-1, eat, pos-1);
    } else if (pos == y[n] / 2) {
        return eat + z[n-1] + 1;
    } else {
        return ans(n-1, eat+z[n-1]+1, pos-y[n-1]-2);
    }
}

int main() {
    ll n, x;
    cin >> n >> x;
    y[0] = 1;
    z[0] = 1;
    rep (i, 50) {
        y[i+1] = y[i] * 2 + 3;
        z[i+1] = z[i] * 2 + 1;
    }
    cout << ans(n, 0, x-1);
}