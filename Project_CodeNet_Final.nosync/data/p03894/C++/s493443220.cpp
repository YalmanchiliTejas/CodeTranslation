#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    bool ans[n+2];
    memset(ans, 0, sizeof(ans));
    ans[1] = true;
    int cur = 1;
    while (q--) {
        ans[cur-1] = ans[cur+1] = true;
        int a, b; cin >> a >> b;
        if (cur == a) cur = b;
        else if (cur == b) cur = a;
        swap(ans[a], ans[b]);
    }
    ans[cur-1] = ans[cur+1] = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}