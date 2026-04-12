#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 1e9;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> d;
    rep (i, n) {
        ll a;
        cin >> a;
        if (i == 0) {
            d.push_back(a);
            continue;
        }
        int l = -1, r = d.size(), mid;
        while (abs(r - l) > 1) {
            mid = (l + r) / 2;
            if (d[mid] < a) r = mid;
            else l = mid;
        }
        if (r == d.size()) d.push_back(a);
        else d[r] = a;
    }
    cout << d.size() << endl;
    
    return 0;
}

