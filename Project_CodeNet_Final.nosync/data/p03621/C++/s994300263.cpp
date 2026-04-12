#include <bits/stdc++.h>
using namespace std;

const long long mod=998244353ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
const int MSIZE=10010;
long long inv[MSIZE],F[MSIZE],iF[MSIZE];

void prev(int N)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=iF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    iF[i]=iF[i-1]*inv[i]%mod;
  }
}

int main()
{
  char A[10010],B[10010];
  scanf("%s%s",A,B);
  int X=0,Y=0;
  for(int i=0;A[i];i++){
    if(A[i]=='1'){
      if(B[i]=='0'){
	X++;
      }
      else{
	Y++;
      }
    }
  }
  prev(X+Y+1);
  static long long dp[2][10010]={0},ans=0ll;
  bool b=0;
  dp[b][0]=1;
  for(int i=0;i<=X+Y;i++){
    for(int j=max(0,i-Y);j<=i&&j<=X;j++){
      long long S=dp[b][j];
      dp[b][j]=0;
      ad(dp[!b][j],S*((X-j)*(Y-(i-j))%mod));
      ad(dp[!b][j+1],S*((X-j)*(X-j)%mod));
      if(j==X){
	ad(ans,S*F[X+Y-i]%mod*F[X+Y]%mod*iF[i]%mod);
      }
    }
    b=!b;
  }
  printf("%lld\n",ans);
  return 0;
}
