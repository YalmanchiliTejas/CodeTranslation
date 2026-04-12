#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int a,b,n,s=0,mod=1000000007;
  cin>>a>>b>>n;
  int l=0,r=1e15+9;
  while(r-l>1){
    int mid=(l+r)/2;
    if(mid&&(a-b)>=1e18/mid){
      r=mid;
      continue;
    }
    int c=n-mid*(a-b);
    if( c+a-b>=a && c>=0 )l=mid;
    else r=mid;
  }
  cout<< (((n-(l%mod)*(a-b))%mod)+((l%mod)*(a%mod)))%mod <<endl;
}
