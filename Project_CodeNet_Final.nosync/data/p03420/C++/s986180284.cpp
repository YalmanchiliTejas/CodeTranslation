#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k,ans=0;
  cin>>n>>k;
  if(k==0)cout<<n*n<<endl;
  else{
    for(int i=1;i<n;i++){
      if(i>=k)ans+=n-i;
      if(i>k){
	ans+=(i-k)*((n/i)-1);
	ans+=max(0LL,(n-(i*(n/i))+1)-k);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
