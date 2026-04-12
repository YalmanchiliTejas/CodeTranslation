#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

int main() {
    int n; cin >> n;
    int h[n]; rep(i, n) cin >> h[i];
    int ans = 0;
    rep(i, n) {
        int flg = 0;
        rep(j, i) {
            if (h[j] > h[i]) {
                flg = 1;
                break;
            }
        }
        if (flg == 0) ans++;
    }
    cout << ans << endl;
}
    
