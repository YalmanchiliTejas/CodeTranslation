#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int highest = 0;
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        if (h[j] >= highest) ans++;
        highest = max(highest, h[j]);
    }
    cout << ans << endl;
}
