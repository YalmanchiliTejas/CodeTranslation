#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vs grid(h);
    rep(i, h) cin >> grid[i];
    vi ansi(h, 0);
    vi ansj(w, 0);
    rep(i, h) {
        bool flag = false;
        rep(j, w) {
            if (grid[i][j] == '#') flag = true;
        }
        if (flag) ansi[i] = 1;
    }
    rep(j, w) {
        bool flag = false;
        rep(i, h) {
            if (grid[i][j] == '#') flag = true;
        }
        if (flag) ansj[j] = 1;
    }
    rep(i, h) {
        if (!ansi[i]) continue;
        rep(j, w) {
            if (!ansj[j]) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
}