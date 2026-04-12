#include <bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic warning "-Wconversion"

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) begin(a), end(a)
#define has(a, b) (a.find(b) != a.end())
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)
#define maxval(t) numeric_limits<t>::max()
#define minval(t) numeric_limits<t>::min()
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

using ll = long long;

ll a[51], b[51];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        fora(i, n)
        {
                cin >> a[i];
        }

        ll res = 0;

        while (true)
        {
                ll sum = 0;
                fora(i, n)
                {
                        b[i] = a[i] / n;

                        sum += b[i];
                        res += b[i];

                        a[i] %= n;
                }
                if (sum == 0)
                        break;

                fora(i, n)
                {
                        a[i] += sum - b[i];
                }
        }
        cout << res << '\n';
}
