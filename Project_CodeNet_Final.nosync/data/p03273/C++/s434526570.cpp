#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define int ll
//const ll mod = 1000000007;

int h, w;
char a[101][101];
bool a_b[101][101];
bool is_not_print[101][101];
signed main() {
    cin >> h >> w;
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') a_b[i][j] = true;
        }
    }
    // 列
    bool t;
    for (int i=0;i<w;i++) {
        t = true;
        for (int j=0;j<h;j++) {
            t &= a_b[j][i];
        }
        if (t) {
            for (int j=0;j<h;j++) {
                is_not_print[j][i] = true;
            }
        }
    }
    // 行
    for (int i=0;i<h;i++) {
        t = true;
        for (int j=0;j<w;j++) {
            t &= a_b[i][j];
        }
        if (t) {
            for (int j=0;j<w;j++) {
                is_not_print[i][j] = true;
            }
        }
    }
    
    bool flg = false;
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            if (!is_not_print[i][j]) {
                cout << a[i][j];
                flg = true;
            }
        }
        if (flg) {
            cout << endl;
            flg = false;
        }
    }
}