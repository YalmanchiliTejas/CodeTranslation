#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
long long a[MAXN];

long long check(long long steps, long long ub, int n)
{
    long long moves = 0;
    for (int i = 0; i < n; i++)
    {
        moves += max(0LL, (a[i] + steps - ub + n) / (n + 1));
    }
    return moves;
}

bool isBad(int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] >= n)
            return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long steps = max(0LL, sum - n * (n - 1));
    long long ub = 0;
    for (long long jump = 1E17; jump > 0; jump /= 2)
    {
        while (check(steps, ub + jump, n) > steps)
            ub += jump;
    }
    ub++;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long add = (a[i] + steps - ub + n) / (n + 1);
        ans += max(0LL, add);
        a[i] = a[i] + steps - max(0LL, add) * (n + 1);
    }
    long long extra = steps - ans;
    while (isBad(n))
    {
        ans++;
        long long big = -1E18;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (extra <= 0)
                a[i]++;
            if (a[i] > big)
            {
                big = a[i];
                pos = i;
            }
        }
        extra--;
        a[pos] -= n + 1;
    }
    cout << ans << endl;
    return 0;
}
