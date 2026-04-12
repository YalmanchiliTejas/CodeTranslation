#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int

int arr[3007];
int dp[3007][3007]={0};
int maxmargin(int i,int j)
{
    if(i>j)
        return 0;

        if(dp[i][j]!=0)
        return dp[i][j];

        int x = min(maxmargin(i+2,j),maxmargin(i+1,j-1));
        int y = min(maxmargin(i,j-2),maxmargin(i+1,j-1));

        int ans=max(arr[i]+x,arr[j]+y);

    return dp[i][j] = ans;
}

int32_t main()
{
	fast;
	int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
       sum+=arr[i];
    }
    int score = maxmargin(0,n-1);
    int d = sum-score;
    cout<<score-d<<"\n";

	return 0;
}
