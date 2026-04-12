#include <bits/stdc++.h>
#include <algorithm> //next_permutation

using namespace std;
typedef long long ll;
//typedef pair<int, int> P;

int main(){
string n;
int q;
cin>>n;
cin>>q;

ll a=0;
a=n.size();
ll dp[101][2][5];
memset(dp,0, sizeof(dp));
//dp[桁][0:同じ 1:未満][0以外の数]
dp[0][0][0]=1;

for (int i=0; i<a; i++){
 for (int j=0; j<2; j++){
  for (int k=0; k<4; k++){
  if (j==0){ //制約あり
    ll x=n[i]-'0';
    if (x==0){
      dp[i+1][0][k]+=dp[i][0][k];
    }
    else{
    //0のとき
    dp[i+1][1][k]+=dp[i][0][k];
    //制約保持
    dp[i+1][0][k+1]+=dp[i][0][k];
    //それ以外
    dp[i+1][1][k+1]+=dp[i][0][k]*(x-1);
  }
  }
  if (j==1){
    //0のとき
    dp[i+1][1][k]+=dp[i][1][k];
    //それ以外
    dp[i+1][1][k+1]+=dp[i][1][k]*9;


  }



  }

 }


}
ll ans;
ans=dp[a][1][q]+dp[a][0][q];
cout<<ans;
}
