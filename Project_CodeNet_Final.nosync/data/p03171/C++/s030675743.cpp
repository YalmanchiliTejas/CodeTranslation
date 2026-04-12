#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define double long double
#define x first
#define y second
#define long long long
#define int long 



           //       |----|       /\      |    |   -----   |
           //       |   /       /  \     |    |     |     |
           //       |--/       /----\    |----|     |     |
           //       |   \     /      \   |    |     |     |
           //       |    \   /        \  |    |   -----   -------

int n;
int cache[3002][3002][2];
int arr[3002];
int dp(int i,int j,int c)
{
	if(i>j)
		return 0;
	if(cache[i][j][c]!=-1)
		return cache[i][j][c];
	if(c==0)
		return cache[i][j][c]=max(arr[i]+dp(i+1,j,c^1),arr[j]+dp(i,j-1,c^1));
	else
		return cache[i][j][c]=min(dp(i+1,j,c^1),dp(i,j-1,c^1));
}
int32_t main()
{
    IOS
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	sum+=arr[i];
    }
    memset(cache,-1,sizeof(cache));
    cout<<(2*dp(0,n-1,0)-sum);
}