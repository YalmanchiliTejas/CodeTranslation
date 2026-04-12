#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
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
std::vector<int> Factorial(5e6),Finverse(5e6);
void Cinit(){// limit is 5e6 /// write Cinit&pw /// this takes 792ms at AtCoder
  Factorial[0]=1;
  for(int i=1;i<5e6;i++)Factorial[i]=Factorial[i-1]*i%MOD;
  for(int i=0;i<5e6;i++)Finverse[i]=pw(Factorial[i],MOD-2);
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
  int h,w,k;cin>>h>>w>>k;
  int ans=0;
  for(int i=1;i<h;i++)ans+=(h-i)*i,ans%=MOD;
  ans*=w;ans%=MOD;ans*=w;ans%=MOD;
  ans*=nCk(h*w-2,k-2);ans%=MOD;
  int ans2=ans;
  swap(h,w);
  ans=0;
  for(int i=1;i<h;i++)ans+=(h-i)*i,ans%=MOD;
  ans*=w;ans%=MOD;ans*=w;ans%=MOD;
  ans*=nCk(h*w-2,k-2);ans%=MOD;
  cout<<(ans+ans2)%MOD<<endl;
}
