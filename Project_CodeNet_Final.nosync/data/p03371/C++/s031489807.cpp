#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))

int main()
{
    int A, B, C; cin >> A >> B >> C;
    long long X, Y; cin >> X >> Y;

    ll ans = INF;
    ans = min(ans, A*X + B*Y);
    ans = min(ans, max(X, Y) * C * 2);
    if (X >= Y) ans = min(ans, min(X, Y)*C*2 + (X-Y)*A);
    else ans = min(ans, min(X, Y)*C*2 + (Y-X)*B);

    cout << ans << endl;
}