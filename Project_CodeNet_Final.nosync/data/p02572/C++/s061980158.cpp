#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rt return 0
#define endln "\n"
#define all(v) v.begin(), v.end()
#define for1(i, a, b) for (long long int i = a; i < b; i++)
#define for2(i, a, b) for (long long int i = a; i > b; i--)
//  cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;typedef long long int i;
typedef long long int lli;
typedef pair<lli, lli> pll;
lli power(lli x, lli y, lli m)
{
    lli a = 1;
    x %= m;
    while (y > 0)
    {
        if (y & 1)
        {
            a *= x;
            a %= m;
        }
        y /= 2;
        x *= x;
        x %= m;
    }
    return a;
    //log y
}
lli modInverse(lli b, lli m)
{
    return power(b, m - 2, m);
}
lli modDivide(lli a, lli b, lli m)
{
    a %= m;
    lli inv = modInverse(b, m);
    a *= inv;
    a %= m;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    lli mod = 1e9 + 7;
    lli s = 0;
    vector<lli> v;
    for1(i, 0, n)
    {
        lli a;
        cin >> a;
        v.pb(a);
        s += a;
        s %= mod;
    }
    lli ans = 0;
    for1(i, 0, n)
    {
        lli x = s + mod;
        x -= v[i];
        x %= mod;
        x *= v[i];
        x %= mod;
        ans += x;
        ans %= mod;
    }
    ans = modDivide(ans, 2, mod);
    cout << ans << endl;
}