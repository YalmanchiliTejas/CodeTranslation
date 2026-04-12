#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,1,-1,0};

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (a+b <= 2*c) {
        ans = a*x + b*y;
        cout << ans << endl;
    }
    else {
        while (x>0 && y>0) {
            ans += 2*c;
            x--; y--;
        }
        if (x+y == 0) {
            cout << ans << endl;
        }
        else {
            if (x > 0) {
                if (a <= 2*c) ans += x*a;
                else ans += 2*x*c;
            }
            else {
                if (b <= 2*c) ans += y*b;
                else ans += 2*y*c;
            }
            cout << ans << endl;
        }
    }
}