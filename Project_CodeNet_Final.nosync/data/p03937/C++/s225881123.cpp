#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

vint dx = {1,0};
vint dy = {0,1};

int h, w;
vector<string> field;

bool dfs(int x, int y, vector<string> field) {
    field[y][x] = '.';
    if (x == w-1 && y == h-1) {
        bool ok = true;
        rep(i,h)rep(j,w) if (field[i][j] == '#') ok = false;
        return ok;
    }
    bool res = false;
    rep(i,2) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if (n_x < w && n_y < h && field[n_y][n_x] == '#') {
            res |= dfs(n_x,n_y,field);
        }
    }
    return res;
}

int main() {
    cin >> h >> w;
    field.resize(h);
    rep(i,h) cin >> field[i];
    if (dfs(0,0,field)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}