#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;

int main() {
    int h, w; cin >> h >> w;
    int cnt = 0;
    char a[h][w]; rep(i, h) rep(j, w) {cin >> a[i][j]; if (a[i][j] == '#') cnt++;}
    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}


