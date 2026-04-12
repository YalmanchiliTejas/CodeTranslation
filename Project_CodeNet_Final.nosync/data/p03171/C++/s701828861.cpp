
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mod 1000000007
#define N 500043
#define mp(a,b) make_pair(a,b)
#define loop(a,b) for(int i=a;i<b;i++)
#define test int t; cin >> t; while(t--)
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)
        cin >> dp[i][i];
    for(int i=1;i<n;i++){
        for(int j=0;i+j<n;j++)
            dp[j][i+j]=max(dp[j][j]-dp[j+1][i+j],dp[i+j][i+j]-dp[j][i+j-1]);
    }
   /* for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[0][n-1] << endl;
}