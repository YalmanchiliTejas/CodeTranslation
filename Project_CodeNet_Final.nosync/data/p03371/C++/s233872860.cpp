#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    if (a+b <= c*2) {
        ans = a*x+b*y;
    }
    else {
        if (x < y) ans = 2*c*x + min(b*(y-x), 2*c*(y-x)); 
        else ans = 2*c*y + min(a*(x-y), 2*c*(x-y));
    }
    cout << ans << endl;
    return 0;
}