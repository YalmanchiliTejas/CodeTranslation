#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 3e3 + 50, INF = 1e15, MOD = 1e9 + 7;
ll N, arr[max_N];
ll DP[max_N][max_N];

ll max_diff(ll s, ll e)
{
    if (s == e)
        return arr[s];
    if (e == s + 1)
        return abs(arr[s] - arr[e]);
    ll &res = DP[s][e];
    if (res != -INF)
        return res;
    ll opt1 = arr[s] + min(-arr[e] + max_diff(s + 1, e - 1), -arr[s + 1] + max_diff(s + 2, e));
    ll opt2 = arr[e] + min(-arr[e - 1] + max_diff(s, e - 2), -arr[s] + max_diff(s + 1, e - 1));
    return res = max(opt1, opt2);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        fill(DP[i], DP[i] + max_N, -INF);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cout << max_diff(0, N - 1) << "\n";
    return 0;
}