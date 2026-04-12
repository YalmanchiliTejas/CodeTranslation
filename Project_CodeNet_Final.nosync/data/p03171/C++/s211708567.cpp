#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ull unsigned long long
#define mp make_pair
#define F first
#define S second
#define mod 1000000007

int n;

ll dp[3005][3005];

int main()
{
    scanf("%d", &n);
    vector<ll> v(n+5);

    for(int i=1; i<=n; i++) 
        scanf("%lld", &v[i]);
    
    dp[1][1] = v[1];

    for(int i=n; i>0; i--)
    {
        for(int j = i; j<n+1; j++)
        {
            dp[i][j] = max(v[i] - dp[i+1][j] ,v[j] - dp[i][j-1]);
        }
    }

    cout << dp[1][n] << endl; 

}
