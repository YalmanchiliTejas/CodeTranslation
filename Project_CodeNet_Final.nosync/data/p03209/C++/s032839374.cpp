#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

ll n, a[100005], x, rj, s[55], s2[55];

ll f(ll p, ll pr)
{
    if (pr == 0)
        return 1;

    if (p == 0)
        return 0;

    if (p == s[pr] - 1)
        return s2[pr];

    if (p == s[pr] / 2)
        return 1 + s2[pr - 1];

    if (p < s[pr] / 2)
        return f(p - 1, pr - 1);
    else
        return f(p - s[pr - 1] - 2, pr - 1) + s2[pr - 1] + 1;
}

int main()
{
    cin >> n >> x;
    --x;
    s[0] = 1;
    s2[0] = 1;
    for (int i = 1; i <= 50; ++i)
    {
        s[i] = s[i - 1] * 2 + 3;
        s2[i] = s2[i - 1] * 2 + 1;
    }
    cout << f(x, n) << endl;
}