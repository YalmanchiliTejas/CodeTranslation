#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxh = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int h; cin >> h;
        if (maxh <= h) cnt++;
        maxh = max(maxh, h);
    }

    cout << cnt << endl;

    return 0;
}
