#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][4][2];

int main(){
  string n;
  int K;
  cin >> n >> K;
  int digit = n.size();
  dp[0][0][0] = 1;
  for(int i=0;i<digit;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<2;k++){
        int nd=n[i]-'0';
        for(int d=0;d<10;d++){
          int ni=i+1,nj=j,nk=k;
          if(d!=0) nj++;
          if(nj>K) continue;
          if(k==0){
            if(d>nd) continue;
            if(d<nd) nk=1;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[digit][K][1]+dp[digit][K][0] << endl;
}