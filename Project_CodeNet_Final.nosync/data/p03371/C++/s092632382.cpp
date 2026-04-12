#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;
    if(c * 2 < a + b){
        if(x > y){     
            ans += 2 * c * y;
            ans += (x-y) * a;
        }
        else{
            ans += 2 * c * x;
            ans += (y-x) * b;
        }
        ans = min(ans, 2 * c * max(x, y));
    }
    else{
        ans += a * x + b * y;
    }
    cout << ans << endl;

    return 0;
}