#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll helper(vector <vector <ll>>&dp,vector <ll >&v,int i,int j)
{
    ll start,end;
    if(i>j)
        return 0;
    if(i==j)
        return v[i];
    if(i+1==j)
        return max(v[i],v[i+1]);
    if(dp[i][j]==-1)
    {
        start=v[i]+min(helper(dp,v,i+2,j),helper(dp,v,i+1,j-1));
        end=v[j]+min(helper(dp,v,i+1,j-1),helper(dp,v,i,j-2));
        dp[i][j]=max(start,end);
    }
    return dp[i][j];


}
void solve()
{
    int i,n;
    cin>>n;
    vector <ll> v(n);
    ll X,Y,sum=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
   // cout<<sum<<"\n";
    vector <vector <ll>>dp(n,vector <ll>(n,-1));
    X=helper(dp,v,0,n-1);
    Y=sum-X;
    cout<<X-Y<<"\n";
}
int main()
{
	solve();
	return 0;
}
