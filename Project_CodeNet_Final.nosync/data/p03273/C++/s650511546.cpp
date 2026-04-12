#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
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
    vvc grid(h, vc(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    set<int> hst, wst;
    rep(i, h) {
        bool flag = true;
        rep(j, w) if (grid[i][j] == '#') {
            flag = false;
            break;
        }
        if (flag) hst.insert(i);
    }
    rep(j, w) {
        bool flag = true;
        rep(i, h) if (grid[i][j] == '#') {
            flag = false;
            break;
        }
        if (flag) wst.insert(j);
    }

    rep(i, h) {
        if (hst.count(i)) continue;
        rep(j, w) {
            if (wst.count(j)) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
}