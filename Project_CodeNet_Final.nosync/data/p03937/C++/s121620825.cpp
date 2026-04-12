/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
int h, w;
string a[10];
void yes() {
    cout << "Possible" << endl;
}
void no() {
    cout << "Impossible" << endl;
}
void solve() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> a[i];
    int last = 0;
    for (int i = 0; i < h; i++) {
        int now = 0, s = -1;
        for (int j = 0; j < w; j++) {
            if(a[i][j] == '#') {
                now = j;
                if(s == -1)
                    s = j;
            }
        }
        if(s < last) {
            no(); return;
        }
        last = now;
    }
    yes();
}
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    solve();
    return 0;
}
