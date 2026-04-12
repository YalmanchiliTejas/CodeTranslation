#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int H, W;
char A[9][9];

int main()
{
    cin >> H >> W;

    rep(i, H) {
        rep(j, W) cin >> A[i][j];
    }

    int x = 0, y = 0;
    A[y][x] = 0;
    while (1) {
        if (x + 1 >= W && y + 1 >= H) break;
        if (A[y + 1][x] == '#') {
            y++;
            A[y][x] = '.';
        }
        else if (A[y][x + 1] == '#') {
            x++;
            A[y][x] = '.';
        }
        else break;
    }

    rep(i, H) {
        rep(j, W) {
            if (A[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    return 0;
}