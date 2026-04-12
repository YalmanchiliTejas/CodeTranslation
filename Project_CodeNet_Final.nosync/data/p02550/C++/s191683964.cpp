#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, x, m;
    cin >> n >> x >> m;
    vector<int64_t> cnt(m, 0);
    queue<int64_t> rem;
    int64_t index = 1, sum = x, ans = 0, next = (x * x) % m,
            loop = 0;
    cnt[x] = index;
    rem.push(x);
    while (true) {
        if (cnt[next] != 0) break;
        cnt[next] = ++index;
        rem.push(next);
        sum += next, next = (next * next) % m;
    }
    for (auto i = 1; i < cnt[next]; i++) {
        ans += rem.front();
        rem.pop();
    }
    loop = rem.size(), n -= (cnt[next] - 1),
    ans += (n / loop) * (sum - ans);
    for (auto i = 0; i < n % loop; i++) {
        ans += rem.front();
        rem.pop();
    }
    cout << ans << endl;
    return 0;
}