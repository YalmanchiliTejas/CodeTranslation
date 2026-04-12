#include <bits/stdc++.h>
using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;

const long long INF = 1LL << 60;
vector<ll> a(51, 1), p(51, 1);

ll burger(ll n, ll x) {
    if (n == 0) {
        if (x >= 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (x <= a[n - 1] + 1) {
        return burger(n - 1, x - 1);
    }
    else {
        return p[n - 1] + 1 + burger(n - 1, x - a[n - 1] - 2);
    }
}

int main()
{
    ll N, X;
    cin >> N >> X;

    repd(i, 1, N + 1) {
        a[i] = 2 * a[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }

    ll ans = 0;
    if (X == 2 + a[N - 1]) {
        ans = p[N - 1] + 1;
    }
    else if (X == 3 + 2 * a[N - 1]) {
        ans = 2 * p[N - 1] + 1;
    }
    else {
        ans = burger(N, X);
    }

    cout << ans << endl;
    return 0;
}