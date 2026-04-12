#include<bits/stdc++.h>

using namespace std;

vector<long long>vp;


long long dp[3010][3010];
bool visit[3010][3010];
long long dpp(int i,int j)
{

    if(i>j)
    return 0;


    if(visit[i][j])
    return dp[i][j];
    visit[i][j]=1;


    long long ans=vp[i]-dpp(i+1,j);
    ans=max(ans,vp[j]-dpp(i,j-1));

    return dp[i][j]=ans;

}

int  main()
{

  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
     long long x;
     cin>>x;
     vp.push_back(x);
  }
  cout <<dpp(0,n-1);


}
