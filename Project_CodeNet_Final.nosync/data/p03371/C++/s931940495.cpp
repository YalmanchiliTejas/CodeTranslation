#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010;
const double eps = 1e-6;

int a, b, c, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;
    if(a + b <= 2 * c) cout << x * a + y * b << endl;
    else
    {
        int res = 0;
        int n = min(x, y);

        res = n * 2 * c;
        x -= n, y -= n;

        int d, p;
        if(!x) d = y, p = b;
        else d = x, p = a;
        if(2 * c <= p) res += 2 * c * d;
        else res += d * p;

        cout << res << endl;
    }
    return 0;
}
