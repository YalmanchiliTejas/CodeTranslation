#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 0x3f3f3f3f
#define MS(x, i) memset(x, i, sizeof x)
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define MOD 998244353
#define NOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[105][10][4];
int len;
int a[105];

int k;

inline int read() {
    int ret = 0, sgn = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        ret = ret*10 + ch - '0';
        ch = getchar();
    }
    return ret*sgn;
}

ll dfs(int pos, int pre ,int limit, int lead, int kk)
{
    ll sum = 0;
    if(pos > len) return (kk == 0);

    if(!limit && dp[pos][pre][kk] != -1 && !lead) return dp[pos][pre][kk];

    int res = limit ? a[len - pos + 1] : 9;

    for(int i = 0; i <= res; i++)
    {
        if(kk == 0 && i != 0) continue;
        if(i != 0)
            sum += dfs(pos + 1, i, limit && (i == res), lead && !i, kk - 1);
        else
            sum += dfs(pos + 1, i, limit && (i == res), lead && !i, kk);

    }

    return (!limit && !lead) ? dp[pos][pre][kk] = sum : sum;
}

ll part(string s)
{
    len = s.length();
    for(int i = len; i >= 1; i--)
        a[i] = s[len - i] - '0';

    memset(dp, -1, sizeof dp);

    return dfs(1, 0, 1, 1, k);
}

int main()
{
    //NOS
    string s;
    cin >> s;
    k = read();
    ll ans = part(s);
    printf("%lld\n", ans);
}
