/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M_MAX = 100002;

ll n;
int x, m;

int first[M_MAX];

ll sp[M_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> m;
    int a = x;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        sp[i] = sp[i - 1] + a;
        if(first[a] != 0)
        {
            ans += (sp[i - 1] - sp[first[a] - 1]) * ((n - i + 1) / (i - first[a]));
            ans += sp[first[a] + (n - i + 1) % (i - first[a]) - 1] - sp[first[a] - 1];
            break;
        }
        ans += a;
        first[a] = i;
        a = 1LL * a * a % m;
    }
    cout << ans << "\n";

    return 0;
}
