#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[10010][110][2];

int main(){
  string k;
  cin>>k;
  int n=k.size();
  int d;
  cin>>d;

  dp[0][0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<d;j++){
      for(int f=0;f<=1;f++){
        int lim;
        if(f) lim=9;
        else lim=k[i-1]-'0';

        for(int l=0;l<=lim;l++){
          if(f==0){
            if(l!=lim) dp[i][(j+l)%d][1]=(dp[i][(j+l)%d][1]+dp[i-1][j][0])%MOD;
            else dp[i][(j+l)%d][0]=(dp[i][(j+l)%d][0]+dp[i-1][j][0])%MOD;
          }else{
            dp[i][(j+l)%d][1]=(dp[i][(j+l)%d][1]+dp[i-1][j][1])%MOD;
          }
        }
      }
    }
  }

  cout<<(dp[n][0][0]+dp[n][0][1]-1+MOD)%MOD<<endl;

  return 0;
}
