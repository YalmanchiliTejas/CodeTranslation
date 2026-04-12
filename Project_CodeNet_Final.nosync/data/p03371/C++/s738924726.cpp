#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 1000000000;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int inf = max(x,y);
    ll ans = INF;
    for(int i=0;i<=inf;++i) {
        ll tmp = 2*i*c+max(0, (x-i)*a)+max(0, (y-i)*b);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
