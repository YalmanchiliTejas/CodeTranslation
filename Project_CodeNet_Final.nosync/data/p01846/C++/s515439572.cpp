#include <bits/stdc++.h>

#define rep(i, a, n) for(int i=(a);i < (n);i++)
#define REP(i, n) rep(i,0,n)
#define all(e) e.begin(),e.end()


#ifdef LOCAL
#define show(x) cerr<<__LINE__" : "<<#x<<" = "<<(x)<<endl
#else
#define show(x) true
#endif

using namespace std;
using ll = long long;
template<class T>
using V=vector<T>;

template<class T, class U>
void chmin(T &t, const U u) { if (t > u) t = u; }

template<class T, class U>
void chmax(T &t, const U u) { if (t < u) t = u; }

const int INF = (1 << 30) - 1;
const ll INFL = (ll) 5e15;
const int MOD = 1e9 + 7;

class Solver {
public:
    bool solve() {
        cin >> S;
        if (S == "#") return false;

        int sz = 0;
        for (auto c:S) {
            if (c == '/') sz++;
        }
        grid.resize(sz + 1);

        int l = 0;
        for (auto c:S) {
            if (c == 'b') {
                grid[l].emplace_back(1);
            } else if (c == '/') {
                l++;
            } else {
                for (int len = c - '0', i = 0; i < len; i++) {
                    grid[l].emplace_back(0);
                }
            }
        }

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        grid[a][b] = 0;
        grid[c][d] = 1;

        int len = 0;
        REP(y, grid.size()) {
            REP(x, grid[y].size()) {
                if (grid[y][x] == 1) {
                    if (len != 0) {
                        cout << len;
                        len = 0;
                    }
                    cout << 'b';
                } else {
                    len++;
                }
            }
            if (len != 0) {
                cout << len;
                len = 0;
            }
            if(y+1!=grid.size()){
                cout << '/';
            }
        }
        cout << endl;

        return true;
    }

private:
    string S;
    V<V<int>> grid;
};

int main() {

    while (Solver().solve());

    return 0;
}
