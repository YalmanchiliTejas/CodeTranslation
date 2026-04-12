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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep (i, n) {
        cin >> a[i];
    }
    sort(all(a), greater<ll>());
    vector<int> b;
    vector<int> c;
    if (n % 2 == 0) {
        rep (i, n / 2 - 1) {
            b.push_back(2);
        }
        b.push_back(1);
        b.push_back(-1);
        rep (i, n / 2 - 1) {
            b.push_back(-2);
        }
        ll ans = 0;
        rep (i, n) {
            ans += a[i] * b[i];
        }
        cout << ans << endl;
    } else {
        rep (i, n / 2) {
            b.push_back(2);
            c.push_back(-2);
        }
        rep (i, n / 2 - 1) {
            b.push_back(-2);
            c.push_back(2);
        }
        rep(i, 2) {
            b.push_back(-1);
            c.push_back(1);
        }
        sort(all(b), greater<int>());
        sort(all(c), greater<int>());
        ll ans0, ans1;
        ans0 = ans1 = 0;
        rep (i, n) {
            ans0 += a[i] * b[i];
            ans1 += a[i] * c[i];
        }
        cout << max(ans0, ans1) << endl;
    }
}