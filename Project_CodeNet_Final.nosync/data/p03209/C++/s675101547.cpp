#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const int mod = 1e9 + 7;
ll N, X;
vector<ll> a, p;

ll f(ll n, ll x) {
    if (n == 0) {
        if (x <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (x <= 1 + a[n - 1]) {
        return f(n - 1, x - 1);
    } else {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }

}

int main() {
    cin >> N >> X;
    a.push_back(1);
    p.push_back(1);

    rep(i, N) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }

    cout << f(N, X) << endl;
}