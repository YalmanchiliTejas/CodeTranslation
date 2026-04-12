#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;

    int ans = 0;
    if (a+b > c*2) {
        int z = min(x,y);
        ans += z * c * 2;
        x -= z;
        y -= z;
        if (x > 0) {
            if (c * 2 < a) ans += c * x * 2;
            else ans += a * x;
        }
        if (y > 0) {
            if (c * 2 < b) ans += c * y * 2;
            else ans += b * y;
        }
    } else {
        ans += a * x + b * y;
    }

    cout << ans << '\n';

    return 0;
}