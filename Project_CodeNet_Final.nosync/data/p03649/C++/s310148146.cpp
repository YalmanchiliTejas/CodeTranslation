#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define ms(x, v) memset(x, v, sizeof(x))
using namespace std;
ll s[100], n;

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    rep1(i, n) cin >> s[i];

    ll sum, ans = 0;
    do
    {
        sum = 0;

        rep1(i, n)
        {
            ll num = s[i] / n;
            sum += num;
            s[i] %= n;
            s[i] -= num;
        }

        rep1(i, n) s[i] += sum;

        ans += sum;

    } while(sum);
    cout << ans << endl;
    return 0;
}
