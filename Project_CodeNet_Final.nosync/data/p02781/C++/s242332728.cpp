//
#include<bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//int dr1[] = {-1, 0, 1, 0};
//int dc1[] = {0, 1, 0, -1};
//int dr3[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
//int dc3[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
const int MOD = 1000000007;
const int INF = 1000000007;
const int MAXN = (int)3e5+1;

int main()
{
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    ll dp[102][2][5] = {}; //dp[i][j][k] --> at position i there have been k nonzero digits, j indicates if it is less than s already
    dp[0][0][0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int l=0; l<=k; l++)
            {
                int dig = j ? 9 : (s[i] - '0');
                for(int d = 0; d<=dig; d++)
                {
                    dp[i + 1][j || d < dig][l + (d != 0)] += dp[i][j][l];
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << "\n";

    return 0;
}

