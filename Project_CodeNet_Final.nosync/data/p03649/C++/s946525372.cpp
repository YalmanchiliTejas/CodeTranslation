#include<bits/stdc++.h>
using namespace std;
#define int long long
using Int = __int128;
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  {
    bool flg=1;
    for(int i=0;i<n;i++)
      flg&=a[i]<n;
    if(flg){
      cout<<0<<endl;
      return 0;
    }
  }
  Int sum=0;
  for(int i=0;i<n;i++) sum+=a[i];
  Int L=sum-n*(n-1),R=sum;
  for(Int k=L;k<=R;k++){
    Int s=0;
    for(int i=0;i<n;i++){
      if(a[i]+k<n) continue;
      s+=(a[i]+k-n)/(n+1)+1;
    }
    if(s<=k){
      cout<<(int)k<<endl;
      return 0;
    }
  }
  return 0;
}
