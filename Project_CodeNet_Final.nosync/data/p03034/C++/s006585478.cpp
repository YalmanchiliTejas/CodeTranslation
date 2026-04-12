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
        while (e > i && (e % i != 0 || s < e)) {
            tmp += S[s] + S[e];
            s += i, e -= i;
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}
