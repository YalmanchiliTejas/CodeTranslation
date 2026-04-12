#include<stdio.h>
#include<string.h>

char n[102];
int k,l,dp[101][4],bd[101][4];

int max(int a,int b){return a>b?a:b;}

int main(){
  scanf("%s%d",n+1,&k);
  l=strlen(n+1);
  dp[1][1]=n[1]-'1';
  bd[1][1]=1;
  for(int i=2;i<=l;i++){
    if(n[i]=='0'){
      bd[i][1]=bd[i-1][1];
      bd[i][2]=bd[i-1][2];
      bd[i][3]=bd[i-1][3];
    }
    else{
      bd[i][2]=bd[i-1][1];
      bd[i][3]=bd[i-1][2];
      dp[i][1]=bd[i-1][1];
      dp[i][2]=bd[i-1][2];
      dp[i][3]=bd[i-1][3];
    }
    dp[i][1]+=dp[i-1][1]+9;
    dp[i][2]+=dp[i-1][2]+dp[i-1][1]*9+bd[i-1][1]*max(n[i]-'1',0);
    dp[i][3]+=dp[i-1][3]+dp[i-1][2]*9+bd[i-1][2]*max(n[i]-'1',0);
  }
  printf("%d",dp[l][k]+bd[l][k]);
  return 0;
}