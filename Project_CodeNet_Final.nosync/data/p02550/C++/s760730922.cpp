#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;
int main()
{
    long long n, x, m; cin >> n >> x >> m;
    long long ans = 0;
    vector<long long> remain; int cnt = 0;
    vector<int> used(m+1); used[m] = 1;
    remain.push_back(x); cnt++;
    long long cur = (x*x) % m; long long sum = x;
    while (used[cur] == 0 && cnt < n)
    {
        if (cur == 0)
        {
            cout << sum << '\n'; return 0;
        }
        sum += cur; remain.push_back(cur); cnt++;
        used[cur] = cnt;
        cur = (cur*cur) % m;
    }
    ans += sum; sum = 0; n -= cnt;
    for (int i = used[cur] - 1; i < cnt; i++)
    {
        sum += remain[i];
    }
    int num = cnt - used[cur] + 1;
    ans += sum * (n / num);
    for (int i = used[cur] - 1; i < used[cur] - 1 + (n % num); i++)
    {
        ans += remain[i];
    }
    cout << ans << '\n';
    return 0;
}
