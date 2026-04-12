#include<bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x) memset(x,0,sizeof(x))
#define lson (root<<1)
#define rson (root<<1|1)
#define EM emplace
#define EM_back emplace_back
using namespace std;
typedef pair<int,int> pii;
int n;
int a[3020];
int dp[3020][3020];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ct=1;
    if(n%2==0)ct=-1;
    for(int i=0;i<n;i++)dp[i][i]=ct*a[i];
    for(int i=2;i<=n;i++)
    {
        ct*=-1;
        if(ct==-1)//second
        {
            for(int j=0;j+i-1<n;j++)
            {
                dp[j][j+i-1]=min(dp[j][j+i-2]+ct*a[j+i-1],
                                 dp[j+1][j+i-1]+ct*a[j]);
            }
        }
        else//first
        {
            for(int j=0;j+i-1<n;j++)
            {
                dp[j][j+i-1]=max(dp[j][j+i-2]+ct*a[j+i-1],
                                 dp[j+1][j+i-1]+ct*a[j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
	return 0;
}
