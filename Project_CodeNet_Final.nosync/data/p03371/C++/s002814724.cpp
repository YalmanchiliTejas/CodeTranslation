#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1001001001;

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans;
    if(x > y) ans = min({a*x + b*y, 2*c*y+a*(x-y), 2*c*x});
    else ans = min({a*x + b*y, 2*c*x+b*(y-x), 2*c*y});
    cout << ans << endl;
}
