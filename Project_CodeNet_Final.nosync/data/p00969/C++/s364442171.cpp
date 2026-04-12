#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; (i) < (n); ++(i))
#define REP3(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;

int solve(int n, vector<int> & a) {
    sort(ALL(a));
    unordered_set<int> index;
    REP (i, n) index.insert(a[i]);

    int answer = 2;
    unordered_map<ll, int> used;
    REP (i, n) {
        REP3 (j, i + 1, n) {
            int d = a[j] - a[i];
            if (not index.count(a[i] + 2 * d)) continue;
            auto key = ((ll)(a[i] % d) << 32) | d;
            if (used.count(key) and a[j] <= used[key]) continue;
            int len = 2;
            while (index.count(a[i] + len * d)) {
                ++ len;
            }
            used[key] = a[i] + (len - 1) * d;
            answer = max(answer, len);
        }
    }

    return answer;
}

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}

