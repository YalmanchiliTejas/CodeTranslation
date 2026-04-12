#include<bits/stdc++.h>
using namespace std;
int DP[110][5][5];
int main()
{
  int N,K;
  string S;
  cin>>S>>K;
  N=S.length();
  DP[0][0][1]=1;
  for(int i=0;i<N;i++)
    for(int j=0;j<=K;j++)
    {
      if(S[i]=='0'){
        DP[i+1][j][1]+=DP[i][j][1];
      	DP[i+1][j][0]+=DP[i][j][0];
      	DP[i+1][j+1][0]+=DP[i][j][0]*9;
      }
      else
      {
        DP[i+1][j][0]+=DP[i][j][1]+DP[i][j][0];
        for(int _=1;_<10;_++)
          DP[i+1][j+1][0]+=DP[i][j][0];
        for(int _=1;_<S[i]-'0';_++)
          DP[i+1][j+1][0]+=DP[i][j][1];
        DP[i+1][j+1][1]+=DP[i][j][1];
      }
    }
  cout<<DP[N][K][1]+DP[N][K][0]<<endl;
  return 0;
}