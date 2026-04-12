#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
std::vector<int> w(1e6),ww(1e6),wa(1e6);
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
int nCk(int n,int k){
  int res=1;
  res*=w[n];
  res*=ww[n-k];res%=MOD;
  res*=ww[k];res%=MOD;
  return res;
}
//main
//解説AC
signed main(){
  int N,M,K;cin>>N>>M>>K;
  w[0]=1;for(int i=1;i<1e6;i++)w[i]=w[i-1]*i%MOD;
  for(int i=0;i<1e6;i++)ww[i]=pw(w[i],MOD-2);
  for(int i=0;i<1e6;i++)wa[i]=pw(i,MOD-2);
  int res=0;
  res+=N*(N+1)%MOD*(((2*N+1)*wa[3]-1)%MOD)%MOD;
  res%=MOD;
  res*=M;res%=MOD;res*=M;res%=MOD;
  int tmp=res;
  res=0;
  swap(N,M);
  res+=N*(N+1)%MOD*(((2*N+1)*wa[3]-1)%MOD)%MOD;
  res%=MOD;
  res*=M;res%=MOD;res*=M;res%=MOD;
  res+=tmp;res%=MOD;
  res*=wa[4];res%=MOD;
  res*=nCk(N*M-2,K-2);res%=MOD;
  cout<<res<<endl;
}
