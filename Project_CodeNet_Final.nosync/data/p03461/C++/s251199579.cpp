#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a, b;
const int maxN = 105;
int d[maxN][maxN];
bool ok[maxN][maxN];
int val[maxN][maxN];
int vert[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> d[i][j];
        }
    }
    int sz = 1;
    for (int cnt1 = 0; cnt1 < 100; cnt1++) {
        for (int cnt2 = 0; cnt2 < 100; cnt2++) {
            vert[cnt1][cnt2] = sz++;
            int at_least_t = 0;
            for (int j = 1; j <= a; j++) {
                for (int k = 1; k <= b; k++) {
                    at_least_t = max(at_least_t, d[j][k] - j * cnt1 - k * cnt2);
                }
            }
            val[cnt1][cnt2] = at_least_t;
            for (int j = 1; j <= a; j++) {
                for (int k = 1; k <= b; k++) {
                    int p = at_least_t + j * cnt1 + k * cnt2;
                    assert(p >= d[j][k]);
                    if (p == d[j][k]) ok[j][k] = true;
                }
            }
        }
    }
    for (int j = 1; j <= a; j++) {
        for (int k = 1; k <= b; k++) {
            if (!ok[j][k]) {
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible" << '\n';
    vector < pair < pair < int, int >, int > > edges;
    int T = sz;
    for (int i = 0; i < maxN; i++) {
        if (i + 1 < maxN) edges.emplace_back(make_pair(i + 1, i + 2), -1);
        if (i + 1 < maxN) edges.emplace_back(make_pair(maxN + i + 1, maxN + i + 2), -2);
        for (int j = 0; j < maxN; j++) {
            edges.emplace_back(make_pair(i + 1, maxN + (maxN - j - 1) + 1), val[i][j]);
        }
    }
    cout << 2 * maxN << " " << edges.size() << '\n';
    for (auto it : edges) {
        cout << it.first.first << " " << it.first.second << " ";
        if (it.second == -1) cout << 'X' << '\n';
        else if (it.second == -2) cout << 'Y' << '\n';
        else cout << it.second << '\n';
    }
    cout << 1 << " " << maxN + maxN  << '\n';
    return 0;
}