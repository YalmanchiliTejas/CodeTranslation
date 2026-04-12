#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
int dp[301][301],f[301][301];
string ch(string s,string t){
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    s="@"+s,t="@"+t;
    int m=s.size(),n=t.size();
    for(int i=1;i<m;i++)
     for(int j=1;j<n;j++){
      if(s[i]==t[j]){
        dp[i][j]=dp[i-1][j-1]+1;
        f[i][j]=3;
      }
      else{
        if(dp[i-1][j]<dp[i][j-1]){
          dp[i][j]=dp[i][j-1];
          f[i][j]=2;
        }
        else{
          dp[i][j]=dp[i-1][j];
          f[i][j]=1;
        }
      }
    }
    int idx=dp[m-1][n-1];
    string ans;
    for(int i=m-1,j=n-1;i>0&&j>0&&idx;){
      if(f[i][j]==1)i--;
      else if(f[i][j]==2)j--;
      else i--,j--,idx--,ans+=s[i+1];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
main(){
  string s;
  while(cin>>s,s!="#END"){
    string ans;
    for(int i=1;i<s.size();i++){
      string s1=s.substr(0,i);
      string s2=s.substr(i);
      string s3=ch(s1,s2);
      if(ans.size()<s3.size())ans=s3;
    }
    cout<<ans<<endl;
  }
}