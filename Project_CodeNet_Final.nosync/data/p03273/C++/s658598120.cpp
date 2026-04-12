#include <bits/stdc++.h>
using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;

const long long INF = 1LL << 60;

int main()
{
    int H, W;
    cin >> H >> W;

    int a[H][W];
    rep(i, H) {
        rep(j, W) {
            char tmp;
            cin >> tmp;
            if (tmp == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    rep(i, H) {
        int cnt = 0;
        rep(j, W) {
            if (a[i][j] == 0 || a[i][j] == -1) {
                cnt++;
            }
        }
        if (cnt == W) {
            rep(j, W) {
                a[i][j] = -1;
            }
        }
    }

    rep(i, W) {
        int cnt = 0;
        rep(j, H) {
            if (a[j][i] == 0 || a[j][i] == -1) {
                cnt++;
            }
        }
        if (cnt == H) {
            rep(j, H) {
                a[j][i] = -1;
            }
        }
    }

    rep(i, H) {
        int cnt = 0;
        rep(j, W) {
            if (a[i][j] == -1) continue;
            else if (a[i][j] == 0) {
                cout << ".";
                cnt++;
            }
            else {
                cout << "#";
                cnt++;
            }
        }
        if (cnt != 0) cout << endl;
    }

    return 0;
}