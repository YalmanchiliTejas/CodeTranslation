#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int s, n = 0;
    int mx = 0, mn = 0, sum = 0;
    while (1)
    {
        cin >> n;
        mx = -1;
        mn = 1001;
        sum = 0;
        if (n == 0)
            return 0;
        REP(i, n)
        {
            cin >> s;
            mx = max(mx, s);
            mn = min(mn, s);
            sum += s;
        }
        cout << (sum - mx - mn) / (n - 2) << endl;
    }
}
