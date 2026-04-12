#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int pw(int n,int k){
  if(k<0)return pw(n,k+MOD-1);
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
std::vector<int> Factorial(1e7+2),Finverse(1e7+2);
void Cinit(){// limit is 5e6 /// write Cinit&pw /// this takes 792ms at AtCoder
  Factorial[0]=1;
  for(int i=1;i<1e7+2;i++)Factorial[i]=Factorial[i-1]*i%MOD;
  for(int i=0;i<1e7+2;i++)Finverse[i]=pw(Factorial[i],MOD-2);
}
int nCk(int n,int k){
  if(n<k)return 1;if(k<0)return 0;
  int res=Factorial[n];
  res*=Finverse[k];res%=MOD;
  res*=Finverse[n-k];res%=MOD;
  return res;
}

signed main(){
  Cinit();
  int n;cin>>n;
  int ans=pw(3,n);
  for(int i=n/2+1;i<=n;i++){
    ans-=2*nCk(n,i)*pw(2,n-i)%MOD;
    ans+=MOD;ans%=MOD;
  }
  cout<<ans<<endl;
}
