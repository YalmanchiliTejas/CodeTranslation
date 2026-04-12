    #include<bits/stdc++.h>
    using namespace std;
    using ll=long long;
    string s;
    int sum;
    ll mod=1e9+7;
    int dp[10001][101][2];
    ll solve(int i,int d,bool b)
    {
        
      if(dp[i][d][b]!=-1)
      return dp[i][d][b];
      int ub=(b==1)?(s[i]-'0'):9;
      ll ans=0;
      if(i==s.size()-1)
      {
        for(int x=0;x<=ub;x++)
        {
          if(x%sum==d)
          ans++;
        }
        return dp[i][d][b]=ans;
      }
      for(int j=0;j<=ub;j++)
      {
        ans+=solve(i+1,(sum+d-j%sum)%sum,(b&&(j==ub)));
        ans=ans%mod;
      }
      return dp[i][d][b]=ans;
    }
    int main()
    {
      memset(dp,-1,sizeof(dp));
      cin>>s;
      cin>>sum;
      cout<<(mod+solve(0,0,1)-1)%mod<<endl;
      return 0;
    }