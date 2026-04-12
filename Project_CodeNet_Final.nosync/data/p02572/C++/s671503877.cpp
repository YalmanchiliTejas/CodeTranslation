#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const LL mod = 1e9 + 7;

#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(a) a.begin(), a.end()

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

inline void print_vector(vector<int> &A){
    for (auto&& x : A){
        cout << x << " ";
    }
    cout << endl;
}

inline void print_array(const int A[], int n) {
    REP(i, n) {
        if (i < n - 1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }
    }
}

inline void solve() {
    int n;
    cin >> n;

    int A[n];
    REP(i, n) {
        cin >> A[i];
    }

    LL pre = 0;
    LL res = 0;

    REP(i, n-1) {
        int j = i + 1;
        pre += A[i];
        while (pre > mod) {
            pre -= mod;
        }
        res += (pre * A[j]) % mod;
        res = res % mod;
    }

    cout << res << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int t = 1;
    // cin >> t;

    for (int _ = 0; _ < t; _++) {
        solve();
    }

    return 0;
}
