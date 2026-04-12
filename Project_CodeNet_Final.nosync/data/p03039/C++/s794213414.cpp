#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
int modpow(int X,int Y){
  int sum=X,cnt=1;
  vi A;
  while(cnt<=Y){
    A.pb(sum);
    sum*=sum;
    sum%=MOD;
    cnt*=2;
  }
  int M=A.size();
  int ret=1;
  REP(i,1,M){
    if(Y>=(1ll<<M-i)){
      Y-=(1ll<<M-i);
      ret*=A[M-i];
      ret%=MOD;
    }
  }
  return ret;
}
int fac[500000],finv[500000];
void COMinit(){
  fac[0]=fac[1]=finv[1]=finv[0]=1;
  rep(i,2,500000){
    fac[i]=fac[i-1]*i%MOD;
    finv[i]=finv[i-1]*modpow(i,MOD-2)%MOD;
  }
}
int COM(int n,int k){
  if(n<k||n<0||k<0) return 0;
  return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}
signed main(){
  COMinit();
  int N,M,K; cin>>N>>M>>K;
  int ans=0;
  rep(i,1,N){
    ans+=i*(N-i)%MOD*M%MOD*M%MOD*COM(N*M-2,K-2)%MOD;
    ans%=MOD;
  }
  rep(i,1,M){
    ans+=i*(M-i)%MOD*N%MOD*N%MOD*COM(N*M-2,K-2)%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  }

