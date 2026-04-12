#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
const Int MOD = 1000000007;
int main() {
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    Int ans = 0, sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans = (ans + A[i] * sum) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}