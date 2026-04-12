#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    if(a+b>=2*c) {
        ans += 2 * c * min(x, y); 
    }
    else ans += (a+b) * min(x, y);

    if(x>y) {
        if(a>=2*c) ans += 2*c*(x-y);
        else ans += a*(x-y);
    }
    else if(x<y) {
        if(b>=2*c) ans += 2*c*(y-x);
        else ans += b*(y-x);
    }
    else ;
    
    cout << ans << endl;
    return 0;
}
