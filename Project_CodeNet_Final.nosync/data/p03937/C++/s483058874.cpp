#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define dump(x) cerr<<#x<<": "<<x<<endl
#define debug(x) cerr<<#x<<": "<<x<<" ("<<__LINE__<<")"<<endl
using namespace std;
using vint = vector<int>;
using vdouble = vector<double>;
using vstring = vector<string>;
using ll = long long;
using vll = vector<ll>;

int main() {
    int h, w; cin >> h >> w;
    vstring a(h+2, "");
    rep(i, w) {
        a[0] += ".";
        a[h+1] += ".";
    }
    FOR(i, 1, h+1) {
        string s; cin >> s;
        a[i] = "." + s + ".";
    }
    FOR(y, 1, h+1) {
        FOR(x, 1, w+1) {
            if(a[y][x] == '#' && a[y+1][x-1] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}
