#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REPR(i, n) for (ll i = (n); i >= 0; i--)
#define FOR(i, m, n) for (ll i = (m); i < (n); i++)
#define FORR(i, m, n) for (ll i = (m); i >= (n); i--)
#define INF 1e9
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
#define SORT(x) sort((x).begin(), (x).end())
#define dump(x) cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> h(n);
    REP(i, n)
    {
        cin >> h[i];
        // dump(h[i]);
    }
    ll res = 1;
    FOR(i, 1, n)
    {
        bool flag = true;
        // dump(h[i]);
        if (h[i - 1] > h[i])
            flag = false;
        else
        {
            // dump(flag);
            FOR(j, 0, i)
            {
                if (i == j)
                    continue;
                if (h[j] > h[i])
                {
                    // dump(i);
                    // dump(j);
                    flag = false;
                    break;
                }
            }
        }
        // dump(flag);
        if (flag)
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
