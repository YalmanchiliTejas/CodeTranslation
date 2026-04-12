#include<string>
#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main(){
    string s;
    long long int i,j,k,L,m,dp[220][10][10];
    cin >> s;
    scanf("%lld\n",&m);
    L=s.size();
    dp[0][0][0]=1;
    for(i=0;i<L;i++){
        const int D=s[i]-'0';
        for(j=0;j<2;j++){
            for(k=0;k<m+1;k++){
                for(int d=0;d<=(j?9:D);d++){
                    if(d==0){
                        dp[i+1][j||(d<D)][k]+=dp[i][j][k];
                    }
                    else{
                    dp[i+1][j||(d<D)][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    printf("%lld\n",dp[L][0][m]+dp[L][1][m]);
  return 0;
}