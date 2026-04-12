#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define INF 1e9
int n;
string s[51];
int t_alpha[30];
int alpha[30];
signed main(){
  cin>>n;
  rep(i,n)cin>>s[i];

  rep(i,30)alpha[i]=INF;


  for(int i=0;i<n;i++){
    for(int j=0;j<s[i].size();j++){
      for(int k=0;k<26;k++){
        if(s[i][j]-'a'==k)t_alpha[k]++;
      }
    }

    for(int p=0;p<30;p++){
      alpha[p]=min(alpha[p],t_alpha[p]);
    }
    rep(i,30)t_alpha[i]=0;

  }

  string ans="";
  for(int i=0;i<30;i++){
    if(alpha[i]>0 && alpha[i]!=INF){
      rep(j,alpha[i])ans+='a'+i;
    }
  }
  cout<<ans<<endl;

}
