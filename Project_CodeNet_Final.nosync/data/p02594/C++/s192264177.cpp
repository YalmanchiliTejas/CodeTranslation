#include <bits/stdc++.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;

#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(a) a.begin(), a.end()

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline void print_vector(vector<int> &A){
    for (auto&& x : A){
        cout << x << " ";
    }
    cout << endl;
}

inline void print_array(const int A[], int n) {
    REP(i, n) {
        cout << A[i] << " ";
    }
    cout << endl;
}

bool is_prime(int n) {
    if (n == 2) return true;
    for (int i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

inline void solve() {
    int n;
    cin >> n;

    if (n >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}


int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int t;
    t = 1;
    // cin >> t;

    for (int _ = 0; _ < t; _++) {
        solve();
    }

    return 0;
}
