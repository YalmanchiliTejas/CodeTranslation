#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, max;
    cin >> n;
    int ans = 1;
    cin >> max;
    for (int i = 1; i < n; ++i) {
        int h;
        cin >> h;
        if (h >= max) {
            max = h;
            ++ans;
        }
    }
    cout << ans << endl;
}
