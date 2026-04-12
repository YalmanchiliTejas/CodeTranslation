#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    while (1) {
        int N;
        cin >> N;
        if(N==0)
            break;
        int mi = INF, ma = 0, ans = 0;
        rep(i, N) {
            int in;
            cin >> in;
            ans += in;
            mi = min(mi, in);
            ma = max(ma, in);
        }
        cout << (ans - mi - ma) / (N - 2) << "\n";
    }

    return 0;
}
