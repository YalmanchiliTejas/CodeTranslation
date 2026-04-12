
#include<bits/stdc++.h>
using namespace std;
int main(){
  string N;int K;cin>>N>>K;
  vector<vector<long>> DP(N.length(),vector<long>(4,0));
  DP[0][0]=1;
  DP[0][1]=(int)N[0]-48;
  int c=1;
  for(int i=1;i<N.length();i++){
    DP[i][0]=1;
    for(int j=1;j<=3;j++){
      DP[i][j]=DP[i-1][j]+DP[i-1][j-1]*9-(c+1==j?9-((int)N[i]-48):0);
    }
    if((int)N[i]-48!=0)c++;
  }
  cout<<DP[N.length()-1][K];
}