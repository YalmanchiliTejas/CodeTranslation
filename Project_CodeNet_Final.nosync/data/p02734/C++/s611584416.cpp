#include <bits/stdc++.h>
#define int long long
const int MOD = 998244353;
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 3005, maxa = 3005;

int n, s, a[maxn], ways, cnt[maxa] = {0};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = maxa - 1; j > a[i]; j--)
        {
            cnt[j] += cnt[j - a[i]];
            cnt[j] %= MOD;
        }
        cnt[a[i]] += (i + 1);   // counted by i + 1 Ls
        cnt[a[i]] %= MOD;
        ans += cnt[s];    
        ans %= MOD;
    }
    cout << (ans + MOD) % MOD << "\n";
    return 0;
}