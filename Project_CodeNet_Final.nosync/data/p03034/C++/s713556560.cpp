#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<int> S(N); for (auto &s : S) cin >> s;
    Int ans = 0;
    for (int i = 1; i < N; i++) {
        int s = 0, e = N - 1;
        Int tmp = 0;
        if ((N-1) % i == 0) {
            while (s < e) {
                tmp += S[s] + S[e];
                s += i, e -= i;
                ans = max(ans, tmp);
            }
        } else {
            while (s < N-1 && i < e) {
                tmp += S[s] + S[e];
                s += i, e -= i;
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
