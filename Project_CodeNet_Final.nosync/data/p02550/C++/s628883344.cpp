// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

// --------------------------------------------------------------------------------

void solve()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a;
    a.push_back(x);
    set<ll> s;
    int id = -1, id2 = -1;
    int r = -1;
    for (int i = 1;; i++)
    {
        ll tmp = a[i - 1] % m * a[i - 1];
        tmp %= m;
        a.push_back(tmp);
        if (s.count(a[i]))
        {
            id = find(all(a), a[i]) - a.begin();
            id2 = i;
            r = id2 - id;
            break;
        }
        else
            s.insert(a[i]);
    }
    // rep(i, a.size()) cout << a[i] << endl;
    ll wanum = (n - id) / r;
    ll wamod = (n - id) % r;
    ll wan = 0;
    for (int i = id; i < id2; i++)
    {
        wan += a[i];
        // wan %= m;
    }
    ll wam = 0;
    for (int i = id; i < id + wamod; i++)
    {
        wam += a[i];
        // wam %= m;
    }
    ll ans = 0;
    rep(i, id)
    {
        ans += a[i];
        // ans %= m;
    }
    wan *= wanum;
    ans += wan;
    // ans %= m;
    ans += wam;
    // ans %= m;
    cout << ans << endl;
}

// --------------------------------------------------------------------------------

int main()
{
    // srand((unsigned)time(NULL));
    // int bt = clock();
    solve();
    // double et = 1.0 * (clock() - bt) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}