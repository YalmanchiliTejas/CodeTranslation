#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tlll tuple<ll, ll, ll>

ll inf = 5e18+7;
 
ll pw(ll x, ll y) {
    if (y == 0) return 1;
    else if (y == 1) return x % inf;
    else if (y % 2 == 0) {
        ll p = pw(x, y / 2);
        return p * p % inf;
    }
    else {
        ll p = pw(x, y / 2);
        return p * p % inf * x % inf;
    }
}

ll dv(ll x, ll y) {
    return x * pw(y, inf - 2) % inf;
}
 
ll comb(ll cn, ll cr) {
    ll v = 1;
    if (cn < cr || cn < 0 || cr < 0) return 0;
    for (int i = 1; i <= cr; i++) {
        v = v * (cn - i + 1);
        v = v / i;
    }
    return v;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    int d = n.size() - 1;
    if (k > n.size()) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    ans += pw(9, k) * comb(d, k);
    if (k == 1) {
        ans += (n[0] - 48);
    }
    else if (k == 2) {
        cerr << ans << endl;
        ans += max(n[0] - 49, 0) * pw(9, k - 1) * comb(d, k - 1);
        cerr << ans << endl;
        if (n[1] != '0') {
            ans += pw(9, k - 1) * comb(d - 1, k - 1);
            ans += n[1] - 48;
        }
        else {
            int idx = 1;
            while (idx < n.size() && n[idx] == '0') idx++;
            if (idx != n.size()) {
                ans += pw(9, k - 1) * comb(d - idx, k - 1);
                ans += n[idx] - 48;
            }
        }
    }
    else if (k == 3) {
        cerr << ans << endl;
        ans += max(n[0] - 49, 0) * pw(9, k - 1) * comb(d, k - 1);
        cerr << ans << endl;
        int idx = 1, one;
        while (idx < n.size() && n[idx] == '0') idx++;
        if (idx != n.size()) {
            if (n.size() != k) ans += pw(9, k - 1) * comb(d - idx, k - 1);
            cerr << ans << endl;
            ans += (n[idx] - 49) * pw(9, k - 2) * comb(d - idx, k - 2);
            cerr << ans << endl;
            idx++;
        }
        while (idx < n.size() && n[idx] == '0') idx++;
        if (idx != n.size()) {
            if (n.size() != k) ans += pw(9, k - 2) * comb(d - idx, k - 2);
            cerr << ans << endl;
            ans += (n[idx] - 48) * pw(9, k - 3) * comb(d - idx, k - 3);
            cerr << ans << endl;
            idx++;
        }
    }
    
    cout << ans << endl;
}
