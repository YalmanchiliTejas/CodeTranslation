#include <bits/stdc++.h>
using namespace std;

#define INPUT freopen("input.txt", "r", stdin);

#define ll long long
#define ld long double

#define len(s) s.size()

#define fl(st, en, in) for (int i = st; i < en; i += in)
#define rfl(st, en, de) for (int i = st; i < en; i -= de)
#define fll fl(0, n, 1)
#define ifl(st, en, in) for (int j = st; j < en; j += in)

#define cy cout << "Yes" << endl;
#define cn cout << "No" << endl;
#define ci(s) cin >> s
#define co(s) cout << s << endl

#define vl vector<ll>
#define pb(x) push_back(x)

#define ms(arr, x) memset(arr, x, sizeof(arr))

#define inf INT_MAX

#define mod (ll)1000000007

void solve()
{
    ll n;
    ci(n);
    ll ar[n];
    fll
    {
        ci(ar[i]);
    }
    ll pre[n];
    ms(pre, 0);
    fll
    {
        if (i == 0)
            pre[i] = ar[i];
        else
        {
            pre[i] = pre[i - 1] + ar[i];
        }
        //pre[i] %= mod;
    }
    ll ans = 0;
    fll
    {
        ans += ((ar[i] % mod) * ((pre[n - 1] - pre[i]) % mod));
        ans = ans % mod;
    }
    co(ans);
}

int main()
{
    //INPUT;
    // int t;
    // ci(t);
    // while (t--)
    solve();
}