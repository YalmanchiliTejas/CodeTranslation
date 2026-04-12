#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  int N;
  cin>>N;
  int ans=0,cnt=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    ans=(ans+a*cnt%mod)%mod;
    cnt=(cnt+a)%mod;
  }
  cout<<ans<<endl;
}