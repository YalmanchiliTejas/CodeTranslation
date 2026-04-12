#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
typedef long long ll;
typedef vector<ll> vl;
#define rp(i, f, t) for (long long int i = f; i < t; i++)
#define pr(i, f, t) for (long long int i = t - 1; i >= f; i--)
#define ca(n, a) rp(ca_i, 0, n) cout << a[ca_i] << ((ca_i == n - 1) ? "\n" : " ")
#define za(n, a) rp(za_i, 0, n) a[za_i] = 0
#define be(a) a.begin(), a.end()
#define ce(a) cout << (a) << endl
int main()
{
    ll r, g, b;
    cin >> r >> g >> b;
    if ((g * 10 + b) % 4 == 0)
        ce("YES");
    else
        ce("NO");
}