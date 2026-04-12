#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f(i, s, n, k) for(int i=s;i<n;i+=k)
#define all_(a) a.begin(),a.end()
#define mp make_pair
#define INF INT_MAX
#define pb push_back


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);  
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n, 1)
    {
        cin >> a[i];
    }  
    ll dp[n+1][n+1] = {0};  // dp[i][j] -> max diff. from i to j
    memset(dp, 0, sizeof(dp));
    for(int L = n-1;L >= 0; --L)
    {
        for(int R = L;R < n; ++R)
        {
            if(L == R) dp[L][R] = a[L];
            else       
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
        }
    }
    cout << dp[0][n-1];
    return 0;
}