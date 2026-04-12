#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) for(auto _x:_v){cout<<_x<<" ";}cout<<endl
#define printVS(vs) for(auto x : vs){cout << x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto p : vp) printP(p);
#define readV(_v) rep(j, _v.size()) cin >> _v[j];
#define readVV(_vv) rep(i, _vv.size()) readV(_vv[i]);
#define output(_x) cout << _x << endl;

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct Rect {
    int r1, c1, r2, c2;
    Rect(){}
    Rect(int _r1, int _c1, int _r2, int _c2) : r1(_r1), c1(_c1), r2(_r2), c2(_c2) {}
    bool includes(double r0, double c0) {
        return r1 <= r0 && r0 <= r2 && c1 <= c0 && c0 <= c2;
    }
};

// N, E, S, W
const int dx[4] = {-1, 0,  1,  0};
const int dy[4] = { 0, 1,  0, -1};

bool inside(int x, int y, int H, int W) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while (cin >> n, n) {
        vector<Rect> rects;
        map<int, int> mp;
        rep(i, n) {
            int l, t, r, b;
            cin >> l >> t >> r >> b;
            rects.emplace_back(b, l, t, r);
            mp[b] = 0;
            mp[l] = 0;
            mp[t] = 0;
            mp[r] = 0;
        }
        mp[-inf] = 0;
        mp[inf] = 0;

        int sz = 0;
        for (auto& p : mp) {
            p.second = sz++;
        }

        rep(i, n) {
            rects[i].r1 = mp[rects[i].r1];
            rects[i].c1 = mp[rects[i].c1];
            rects[i].r2 = mp[rects[i].r2];
            rects[i].c2 = mp[rects[i].c2];
        }

        vvi a(sz, vi(sz, -1));

        auto valid = [&](int i, int j, int ni, int nj) {
            if (!inside(ni, nj, sz, sz)) return false;
            if (a[ni][nj] != -1) return false;
            rep(k, n) {
                if (rects[k].includes(i + 0.5, j + 0.5) ^ rects[k].includes(ni + 0.5, nj + 0.5)) {
                    return false;
                }
            }
            return true;
        };

        std::function<void(int, int, int)> dfs = [&](int i, int j, int color) {
            a[i][j] = color;
            rep(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                if (valid(i, j, ni, nj)) {
                    dfs(ni, nj, color);
                }
            }
        };

        int ans = 0;
        rep(r0, sz) {
            rep(c0, sz) {
                if (a[r0][c0] == -1) {
                    // cout << "r0 = " << r0 << ", c0 = " << c0 << endl;
                    dfs(r0, c0, ans++);
                }
            }
        }

        // printVV(a);

        cout << ans << endl;
    }

}