#include <bits/stdc++.h>
using namespace std;

string s;

int m=1e9+7,dp[10009][2][100],p,d;


int dfs(int idx,int z,bool tight){
  if(idx==s.size())return !z;
  int &res=dp[idx][tight][z];
  if(~res)return res;
  res=0;
  int r=(tight?9:s[idx]-48);
  for(int i=0;i<=r;i++){
    res+=dfs(idx+1,(z+i)%d,tight||i<r);
    res%=m;
  }
  return res;
}

int main(){
  memset(dp,-1,sizeof dp);
  getline(cin,s);
  cin>>d;
  cout<<(dfs(0,0,0)-1+m)%m<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////