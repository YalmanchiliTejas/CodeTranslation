
//
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

//int dr1[] = {-1, 0, 1, 0};
//int dc1[] = {0, 1, 0, -1};
//int dr3[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
//int dc3[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
const int MOD = 998244353;
const int INF = 1000000007;
const int MAXN = (int)3000+1;

void setIO(string name)
{
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

ll modx(ll a)
{
    return (a%MOD+MOD)%MOD;
}

ll times(ll a, ll b)
{
    return modx(modx(a)*modx(b));
}

ll add(ll a, ll b)
{
    return modx(modx(a)+modx(b));
}

ll sub(ll a, ll b)
{
    return modx(MOD+modx(a)-modx(b));
}

ll arr[MAXN], dp[MAXN][MAXN], n, s, ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //setIO("");
    cin >> n >> s;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        for(int j=0; j<=s; j++)
            dp[i+1][j] = dp[i][j];

        dp[i+1][arr[i]] = add(dp[i+1][arr[i]], i+1);
        for(int j=0; j+arr[i] <= s; j++)
        {
            dp[i+1][j+arr[i]] = add(dp[i+1][j+arr[i]], dp[i][j]);
        }
        ans = add(dp[i+1][s], ans);
    }

    cout << ans;

    return 0;
}
