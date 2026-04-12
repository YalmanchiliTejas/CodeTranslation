#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) for(auto&& x : v){cout << x << " ";} cout << endl
#define printVV(vv) for(auto&& v : vv){for(auto&& x : v){cout << x << " ";}cout << endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto&& p : vp) printP(p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while(cin >> n, n) {
        vvi vv(2);
        rep(j, 2) vv[j].emplace_back(-inf);
        rep(i, n) {
            int j;
            cin >> j;
            if ((i + 1) & 1 || vv[j^1].back() != i - 1) {
                if (vv[j].back() == i - 1) {
                    vv[j].back() = i;
                } else {
                    vv[j].emplace_back(i);
                }
            } else {
                vv[j^1].pop_back();
                if (vv[j].back() != -inf) {
                    vv[j].back() = i;
                } else {
                    vv[j].emplace_back(i);
                }
            }
        }

        vi v(n);
        rep(j, 2) {
            rep2(i, 1, vv[j].size()) {
                v[vv[j][i]] = (j ? -1 : 1);
            }
        }

        if (v.back() == -1) v.back() = 0;
        rrep(i, n - 1) {
            v[i] += v[i + 1];
        }

        cout << accumulate(all(v), 0) << endl;
    }
}