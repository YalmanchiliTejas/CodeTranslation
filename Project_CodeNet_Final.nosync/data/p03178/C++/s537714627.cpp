#include <bits/stdc++.h>
#define f                           first
#define s                           second
#define task                        "test"
#define fi			                freopen(task".inp", "r", stdin)
#define fo			                freopen(task".out", "w", stdout)
#define reset(a, b)                 memset(a, b, sizeof(a))
#define MAX(a, b)                   a = max(a, b)
#define MIN(a, b)                   a = min(a, b)

using namespace std;

typedef long long                   LL;
typedef pair<int,int>               II;

const LL mod = 1e9 + 7;
const LL N   = 1e5 + 5;

/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
string k;
long long dp[10005][105][2];
int d;

long long calc(int idx, int sum, bool t)
{
    if (idx == k.size())
        return (!sum) ? 1 : 0;
    if (dp[idx][sum][t] != -1)
        return dp[idx][sum][t];
    int m = (t) ? (k[idx] - 48) : 9;
    LL res = 0;
    for (int i = 0; i <= m; i++)
    {
        bool nt = (i == (k[idx] - 48)) ? t : 0;
        res += calc(idx + 1, (sum + i) % d, nt);
        res %= mod;
    }
    return dp[idx][sum][t] = res;
}

LL f() {
	LL v = 0;
	for (int i = 0; i < k.size(); i++)
		for (int j = 1; j <= (i ? 9 : k[0] - '0'); j++)
			v =(v + calc(i + 1, j % d, (i ? 0 : j == k[0] - '0'))) % mod;
	return v;
}

void solve()
{
    cin >> k >> d;
    reset(dp, -1);
    cout << f();
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
//    fi;
//    fo;
    solve();
    return 0;
}
