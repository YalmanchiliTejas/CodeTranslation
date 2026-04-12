#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int x, y, z;
    cin >> x >> y >> z;

    if(x<2*y+3*z) cout << 1 << endl;
    else {
        int ans = 1;
        int l = 2*y+3*z;
        bool flg = true;
        while(flg) {
            ans++;
            l += y + z;
            if(x<l) flg = false;
        }
        cout << ans << endl;
    }
    return 0;
}
