#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    int ans = 0;
    int highest = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        highest = max(highest, h);
        if (h >= highest) ans++;
    }

    cout << ans << endl;
    return 0;
}
