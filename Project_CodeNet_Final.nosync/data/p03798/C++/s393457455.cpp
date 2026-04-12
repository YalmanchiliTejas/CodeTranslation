#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf lca BIT

int n;
string state;

bool solve(int bef, int now)
{
    string ans;
    int en = bef, st = now;
    rep(i, n-1) {
        ans.pb( (now == 1) ? 'S' : 'W' );
        if (now == 1) {
            if (state[i] == 'o') {
                int tmp = now;
                now = bef;
                bef = tmp;
            } else {
                int tmp = now;
                now = -bef;
                bef = tmp;
            }
        } else {
            if (state[i] == 'o') {
                int tmp = now;
                now = -bef;
                bef = tmp;
            } else {
                int tmp = now;
                now = bef;
                bef = tmp;
            }
        }
    }
    ans.pb( (now == 1) ? 'S' : 'W' );
    if (now != en) return false;
        if (now == 1) {
            if (state[state.size()-1] == 'o') {
                if (bef == st) {
                    std::cout << ans << std::endl;
                    return true;
                } else {
                    return false;
                }
            } else {
                if (bef != st) {
                    std::cout << ans << std::endl;
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            if (state[state.size()-1] == 'o') {
                if (bef != st) {
                    std::cout << ans << std::endl;
                    return true;
                } else {
                    return false;
                }
            } else {
                if (bef == st) {
                    std::cout << ans << std::endl;
                    return true;
                } else {
                    return false;
                }
            }
        }
}

signed main()
{
    cin >> n;
    cin >> state;

    if (solve(1, 1)) {
   //     std::cout << 1 << std::endl;
        return 0;
    } else if (solve(1, -1)) {
  //      std::cout << 2 << std::endl;
        return 0;
    } else if (solve(-1, 1)) {
 //       std::cout << 3 << std::endl;
        return 0;
    } else if (solve(-1, -1)) {
//        std::cout << 4 << std::endl;
        return 0;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
