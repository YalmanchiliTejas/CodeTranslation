#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int x[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > gg;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        gg.emplace_back(x[i]);
    }
    sort(gg.begin(), gg.end());
    int where = gg[n / 2 - 1];
    for (int i = 1; i <= n; i++) {
        if (x[i] > where) cout << gg[n / 2 - 1] << "\n";
        else cout << gg[n / 2] << "\n";
    }
    return 0;
}