#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<int> H(N); for (auto& h : H) cin >> h;
    int M = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] >= M) ans++;
        M = max(M, H[i]);
    }
    cout << ans << '\n';
    return 0;
}