#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int Max = -1, ans = 0;

    int t;
    while(n --) {
        cin >> t;
        Max = max(Max, t);
        if(t >= Max) ans += 1;
    }

    cout << ans << endl;
}
