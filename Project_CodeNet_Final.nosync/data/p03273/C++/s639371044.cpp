#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<vector<bool>> del(h, vector<bool>(w));
    rep(i, h) {
        bool ok = true;
        rep(j, w) {
            if (a[i][j]=='#') ok = false;
        }
        if (ok) {
            rep(j, w) del[i][j] = true;
        }
    }
    rep(j, w) {
        bool ok = true;
        rep(i, h) {
            if (a[i][j]=='#') ok = false;
        }
        if (ok) {
            rep(i, h) del[i][j] = true;
        }
    }
    rep(i, h) {
        bool ok = false;
        rep(j, w) {
            if (del[i][j]) continue;
            cout << a[i][j];
            ok = true;
        }
        if (ok) cout << endl;
    }
    return 0;
}
