#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;
const string YES = "YES";
const string NO = "NO";

void solve(long long X) {
    if (X == 3 or X == 5 or X == 7) cout << YES << endl;
    else cout << NO << endl;
}

int main() {
    bool test_samples = false;
    if (not test_samples) {
        long long X;
        std::cin >> X;
        solve(X);
    } else {
        const char *samples[] = {
            "5",
            "6",
        };
        REP(i, std::distance(ALL(samples))) {
            cerr << "[*] sample " << i << endl;
            istringstream iss(samples[i]);
            long long X;
            iss >> X;
            solve(X);
        }
    }
    return 0;
}