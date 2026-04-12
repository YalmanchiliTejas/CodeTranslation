#include <cstdio>
#include <vector>

const long long mod=998244353ll;
const int MSIZE=10000009;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}
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

long long Ch(int i,int j)
{
  return F[i]*iF[j]%mod*iF[i-j]%mod;
}

long long p2[MSIZE];

int main()
{
  int n;
  scanf("%d",&n);
  prev(n/2+1);
  p2[0]=1ll;
  for(int i=1;i<=n/2;i++){
    p2[i]=2ll*p2[i-1]%mod;
  }
  std::vector<long long> S(n/2+2);
  S[n/2+1]=0ll;
  for(int i=n/2;i>=0;i--){
    S[i]=(S[i+1]+Ch(n/2,i)*p2[n/2-i]%mod)%mod;
  }
  long long bad=0ll;
  for(int i=0;i<=n/2;i++){
    ad(bad,Ch(n/2,i)*p2[n/2-i]%mod*S[n/2-i+1]%mod);
  }
  printf("%lld\n",(pw(3,n)+2*mod-2*bad)%mod);
  return 0;
}
