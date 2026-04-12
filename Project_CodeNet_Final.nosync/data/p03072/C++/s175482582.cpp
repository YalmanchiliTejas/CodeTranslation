#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;

const int INF = 200000000;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> H;
    REP(i, N) {
        int a;
        cin >> a;
        H.push_back(a);
    }

    int count = 1;
    int max_h = H[0];
    REP(i, N - 1) {
        if (max_h <= H[i + 1]) {
            count++;
            max_h = max(H[i + 1], max_h);
        }
    }

    cout << count << "\n";

    return 0;
}
