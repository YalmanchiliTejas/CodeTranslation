#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long
//template
int dp[2003][2003];
std::vector<int> gy(100000);

std::vector<int> w(1000000);
int pw(int n,int k){
  int res=1;
  while(k){
    if(k%2)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k/=2;
  }
  return res;
}
int nCk(int n,int k){
  if(n<k)return 0;
  int res=w[n];
  res*=gy[k];res%=MOD;
  res*=gy[n-k];res%=MOD;
  return res;
}

int qwe(int a,int b,int c){
  return nCk(c,a*b)*w[a*b]%MOD*pw(pw(w[a],b),MOD-2)%MOD*gy[b]%MOD;
}

//main
signed main(){
  int N,A,B,C,D;cin>>N>>A>>B>>C>>D;
  w[0]=1;for(int i=1;i<1000000;i++)w[i]=w[i-1]*i%MOD;
  for(int i=0;i<100000;i++)gy[i]=pw(w[i],MOD-2);
  memset(dp,0,sizeof(dp));dp[A-1][N]=1;
  for(int i=A;i<=B;i++){
    for(int j=0;j<=N;j++)dp[i][j]=dp[i-1][j];
    for(int j=C;j<=D;j++){
      for(int k=N-i*j;k>=0;k--){
        dp[i][k]+=qwe(i,j,k+i*j)*dp[i-1][k+i*j]%MOD;
        dp[i][k]%=MOD;
      }
    }
  }
  /*
  for(int i=0;i<=5;i++){
    for(int j=0;j<7;j++)cout<<dp[i][j]<<" ";cout<<endl;
  }
  */
  cout<<dp[B][0]<<endl;
}
