#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i].second] = i;
    }

    for (int i = 0; i < n; ++i) {
        int want = (n - 1) / 2;
        if (pos[i] <= want) {
            cout << a[want + 1].first << '\n';
        }
        else {
            cout << a[want].first << '\n';
        }
    }

    return 0;
}