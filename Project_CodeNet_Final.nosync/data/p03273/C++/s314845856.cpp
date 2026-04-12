#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define each(e,v) for(auto&& e:(v))
#define all(v) begin(v),end(v)
#define dump(x) cerr<<#x<<": "<<(x)<<endl
#define INF 100000000
#define IINF 9999999999999;
using vint = std::vector<int>;
using ll = long long;
using vll = std::vector<ll>;
template <class T> void chmin(T& a, const T& b) { a = std::min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = std::max(a, b); }
#define output(x) cout << x << endl;

int main() {
    int H, W;
    cin >> H >> W;
    char a[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }

    bool high[H] = {false}, width[W] = {false};
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(a[i][j] == '#') {high[i] = true; width[j] = true;}
        }
    }

    for (int i = 0; i < H; ++i) {
        if(!high[i]) continue;
        for (int j = 0; j < W; ++j) {
            if(!width[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}