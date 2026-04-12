#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;
//配列の添字ズレに注意
//=に注意
int main(){
  long mod=1000000007,ans=0,n; cin>>n;
  vector<long> a(n);
  rep(i,n) cin>>a[i];// a の入力

// 累積和
  vector<long> s(n+1,0);// s[0]=0になる
  rep(i,n) s[i+1]=(s[i]+a[i])%mod;

  
  
  for(int i=1;i<n+1;i++){
    ans=(ans+a[i-1]*s[i-1])%mod;
  
  }
  
  
  
  
  
  cout<< ans<<endl;
}
