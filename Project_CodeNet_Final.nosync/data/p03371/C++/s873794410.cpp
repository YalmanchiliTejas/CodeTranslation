#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll sol = min(x, y) * 2 * c;
    if (x > y)
        sol += (x - y) * a;
    else
        sol += (y - x) * b;
    sol = min(sol, x * a + y * b);
    sol = min(sol, max(x, y) * 2 * c);
    cout << sol;
}
