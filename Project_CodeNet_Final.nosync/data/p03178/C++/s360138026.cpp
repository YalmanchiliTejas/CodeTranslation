#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[100005][105][2],k,n;
ll mod=1e9+7;
vector<int> num;
ll cal(int i, ll sum, bool pre){
  if(i>=n) return sum==0;
  if(dp[i][sum][pre]!=-1) return dp[i][sum][pre];
  ll ans =0;
  if(pre){
    for(int d=0; d<=num[i]; d++){
      ans+=cal(i+1,(sum+d)%k,d==num[i]);
      if(ans>mod) ans-=mod;
    }
  }
  else {
    for(int d=0; d<=9; d++){
      ans+=cal(i+1,(sum+d)%k,false);
      if(ans>mod) ans-=mod;
    }
  }
  return dp[i][sum][pre]=ans;
}
int main() {
  memset(dp,-1,sizeof dp);
  string s;
  cin>>s;
  cin>>k;
  num.clear();
  n=s.size();
  for(int i=0; i<s.size(); i++){
    num.push_back(s[i]-'0');
  }
  ll ans = cal(0,0,true)-1;
  cout<<ans<<endl;
}
