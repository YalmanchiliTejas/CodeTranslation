#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    bool flag = true;
    ll ans = 0;
    while (flag)
    {
        flag = false;
        rep(i, n)
        {
            if (a[i] >= n)
            {
                flag = true;
                ll cnt = a[i] / n;
                ans += cnt;
                a[i] %= n;
                rep(j, n)
                {
                    if (j == i)
                    {
                        continue;
                    }
                    a[j] += cnt;
                }
            }
        }
    }
    cout << ans << endl;
}