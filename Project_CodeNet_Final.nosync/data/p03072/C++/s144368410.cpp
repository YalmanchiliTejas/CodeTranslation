#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;

    cin >> n;

    int ans = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h >= max) {
            ans++;
            max = h;
        }
    }

    cout << ans << endl;

    return 0;
}
