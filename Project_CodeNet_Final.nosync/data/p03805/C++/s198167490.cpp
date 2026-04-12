#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> e;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<int> v(n);
    iota(ALL(v), 1);
    int t = 0;
    do {
        bool all_ok = true;
        for (int i = 0; i < n - 1; i++) {
            bool ok = false;
            for (const auto x : e[v[i]]) {
                if (v[i + 1] == x) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                all_ok = false;
                break;
            }
        }
        if (all_ok) {
            t++;
        }
    } while(next_permutation(ALL(v)) && v[0] == 1);

    cout << t << endl;
}
