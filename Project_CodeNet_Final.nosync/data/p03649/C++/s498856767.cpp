#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
#define prev prev55

long long n, a[500], ss;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    long long fh = 1e18;
    for (int i = 0; i < n; i++) cin >> a[i], ss += a[i];
    for (long long op = ss; op >= 0 && op >= ss - n * n; op--)
    {
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // 0 <= a[i] - x * (n + 1) + op < n
            long long x = (a[i] + op) / (n + 1);
            cnt += x;
            //cout << op << " " << x << endl;
            if (a[i] + op - ((a[i] + op) / (n + 1)) * (n + 1) == n)
            {
                cnt = 1e18;
            }
            //cout << a[i] + op - ((a[i] + op) / (n + 1)) * (n + 1) << endl;
        }
        if (cnt == op)
        {
            fh = op;
            //return 0;
        }
    }
    cout << fh;
}
