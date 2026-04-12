#include<bits/stdc++.h>
using namespace std;

const int MXN=10005;
const int MOD=1e9+7;
int add(int&x,int y){return(x+=y)<MOD?x:x-=MOD;}
int sub(int&x,int y){return(x-=y)>= 0?x:x+=MOD;}

char K[MXN];
int D,dp[MXN][105][2];

int main(){
  dp[0][0][0]=1;
  dp[0][0][1]=1;
  scanf("%s%d",K,&D);
  int N=strlen(K);
  reverse(K,K+N);
  for(int i=0;K[i];++i){
    for(int d=0;d<=9;++d){
      for(int k=0;k<D;++k){
        add(dp[i+1][(k+d)%D][0],dp[i][k][0]);
        if(d+'0'<K[i])
        add(dp[i+1][(k+d)%D][1],dp[i][k][0]);
        if(d+'0'==K[i])
        add(dp[i+1][(k+d)%D][1],dp[i][k][1]);
      }
    }
  }
  printf("%d\n",sub(dp[N][0][1],1));
}
