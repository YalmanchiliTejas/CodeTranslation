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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, x, m;
    cin >> n >> x >> m;
    vector<lli> v(m + 2);
    vector<lli> summ(m + 2);

    // vector<lli>()
    map<lli, lli> ma;
    if (n <= m)
    {
        lli a = x;
        for1(i, 1, n)
        {
            x *= x;
            x %= m;
            a += x;
        }
        cout << a << endl;
        return 0;
    }
    v[1] = x % m;
    summ[1] = v[1];
    lli f1, f2;
    for1(i, 2, m + 2)
    {
        v[i] = v[i - 1];
        v[i] *= v[i - 1];
        v[i] %= m;
        summ[i] = v[i] + summ[i - 1];
        // summ[i] %=
        if (ma[v[i]] != 0)
        {
            f2 = i, f1 = ma[v[i]];
            break;
        }
        ma[v[i]] = i;
    }
    // cout << f2 << " " << f1 << " " << summ[f2] << endl;
    lli r = f2 - f1;
    lli left = n - f2;
    lli mul = left / r;
    lli rem = left % r;

    lli rec = summ[f2] - summ[f1];
    // rec %= m;
    rec *= mul;
    // rec %= m;
    summ[f2] += rec;
    // summ[f2] %= m;
    lli ans = summ[f2];
    lli prev = v[f2];
    // cout << prev << endl;
    // cout << n - rem + 1 << " " << n << endl;
    for (lli i = n - rem + 1; i <= n; i++)
    {
        // cout << i << endl;
        prev *= prev;
        prev %= m;
        ans += prev;
        // ans %= m;
        // cout << prev << endl;
    }
    cout << ans << endl;
}