#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

ll saiki(ll n, ll x)
{
    if (n == 0)
        return 1;
    ll a = pow(2, n + 1) - 3;
    ll b = pow(2, n) - 1;

    if (x == 1)
        return 0;
    else if (x <= 1 + a)
        return saiki(n - 1, x - 1);
    else if (x == 2 + a)
        return b + 1;
    else if (x <= 2 * a + 2)
        return saiki(n - 1, x - a - 2) + b + 1;
    else if (x == 2 * a + 3)
        return 2 * b + 1;
}
int main()
{
    ll n, x;
    cin >> n >> x;
    cout << saiki(n, x) << endl;
}