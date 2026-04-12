#include<iostream>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
//Rを右端に固定したときのカウントを用意（今だけの増加量）
//それを累積するやつを用意
int main(){
  ll N,S; cin>>N>>S;
  ll A[N+100],DP[N+100][S+100][3];
  DP[0][0][0]=1;
  for(int i=0; i<N; i++){
    ll a;
    cin>>a;
    A[i]=a;
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<=S; j++){
      DP[i+1][j][0]+=DP[i][j][0];//i00だけ1、それ以外０。ifの中のa[i]自身の場合が加算
      (DP[i+1][j][1]+=DP[i][j][0]+DP[i][j][1])%=MOD;
      (DP[i+1][j][2]+=DP[i][j][0]+DP[i][j][1]+DP[i][j][2])%=MOD;
      if(j+A[i]<=S){
        (DP[i+1][j+A[i]][1]=DP[i][j][0]+DP[i][j][1])%=MOD;
        (DP[i+1][j+A[i]][2]=DP[i][j][0]+DP[i][j][1])%=MOD;
      }
    }
  }
  cout<<DP[N][S][2]<<endl;
}