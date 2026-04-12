#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

using lint = long long;
using ldouble = long double;

bool solve() {
    int N, L, R;
    cin >> N >> L >> R;
    if (N == 0) return false;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    int ans = 0;
    for (int x = L; x <= R; ++x) {
        int i;
        for (i = 0; i < N; ++i) {
            if (x % A[i] == 0) break;
        }

        ans += (i % 2 == 0);
    }

    cout << ans << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}

