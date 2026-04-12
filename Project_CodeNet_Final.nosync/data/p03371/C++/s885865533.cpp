#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (a + b <= 2 * c)
        ans = a * x + b * y;
    else
    {
        if (x <= y)
            ans = 2 * c * x + (y - x) * min(b, 2 * c);
        else
            ans = 2 * c * y + (x - y) * min(a, 2 * c);
    }
    OP(ans);

    return 0;
}