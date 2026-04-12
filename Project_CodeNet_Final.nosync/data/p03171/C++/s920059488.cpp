#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll mem[3005][3005];
ll ara[3005];

ll dp(ll ara[], int i, int j)
{
    if (i > j)
    {
        return 0;
    }

    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }

    mem[i][j] = max(ara[i] - dp(ara, i + 1, j), ara[j] - dp(ara, i, j - 1));

    return mem[i][j];
}

int main()
{
    int n;
    cin >> n;

    memset(mem, -1, sizeof(mem));

    for (int i = 1; i <= n; i++)
    {
        cin >> ara[i];
    }

    cout << dp(ara, 1, n) << endl;

    return 0;
}