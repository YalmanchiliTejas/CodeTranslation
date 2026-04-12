#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

int solve(int n, const vector<int> & a) {
    multiset<int> fronts;  // of LISs
    REP_R (i, n) {
        auto it = fronts.upper_bound(a[i]);
        if (it != fronts.end()) {
            fronts.erase(it);
        }
        fronts.insert(a[i]);
    }
    return fronts.size();
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}
