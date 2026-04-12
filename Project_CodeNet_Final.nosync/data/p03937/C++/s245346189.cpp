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
#define printVS(_vs) for(auto _x : _vs){cout << _x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;}
#define printP(_p) cout << _p.first << " " << _p.second << endl
#define printVP(_vp) for(auto _p : _vp) printP(_p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<int>> Graph;
const int inf = 1e9;
const int mod = 1e9 + 7;

bool valid(int i1, int j1, int i2, int j2) {
    return (i2 <= i1 && j2 <= j1) || (i1 <= i2 && j1 <= j2);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i1, n) {
        rep(j1, m) {
            rep(i2, n) {
                rep(j2, m) {
                    if (s[i1][j1] == '#' && s[i2][j2] == '#' && !valid(i1, j1, i2, j2)) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Possible" << endl;
}
