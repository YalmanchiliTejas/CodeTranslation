#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s,t;
  cin>>s>>t;
  int dp[2][t.size()+1];
  memset(dp,0,sizeof(dp));
  for(int x=0;x<2;x++){
    queue<int> q[26];
    for(int i=0;i<(int)s.size();i++)
      q[s[i]-'a'].push(i);
    int p=0,f=0;
    for(int i=0;i<(int)t.size();i++){
      int c=t[i]-'a';
      while(!q[c].empty()&&q[c].front()<p) q[c].pop();
      if(q[c].empty()){
	f=1;
	break;
      }
      p=q[c].front();q[c].pop();
      dp[x][i]=p;
    }
    if(f){
      cout<<"no"<<endl;
      return 0;
    }
    if(x) break;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
  }
  int f=1;
  for(int i=0;i<(int)t.size();i++){
    //cout<<dp[1][i]+1<<" "<<(s.size()-dp[0][t.size()-(i+1)])<<endl;
    f&=(dp[1][i]+1)==(s.size()-dp[0][t.size()-(i+1)]);
  }
  cout<<(f?"yes":"no")<<endl;
  return 0;
}