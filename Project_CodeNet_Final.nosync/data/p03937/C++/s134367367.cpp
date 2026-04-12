#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    vector<pair<int, int>> a;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                a.push_back(make_pair(i, j));
            }
        }
    }
    sort(all(a));
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1].first != a[i].first && a[i].second > a[i + 1].second) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}
