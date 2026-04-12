#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  int n;
  cin>>n;
  ll a[n],large0,small0,ans=0;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  if(n%2==0){
    large0=0;
    small0=0;
    for(int i=0;i<n/2-1;i++){
      large0+=a[n-i-1]-a[i];
      large0+=a[n-i-1]-a[i+1];
    }
    large0+=a[n/2]-a[0];
    ans=max(ans,large0);
    for(int i=0;i<n/2-1;i++){
      small0+=a[n-i-1]-a[i];
      small0+=a[n-i-2]-a[i];
    }
    small0+=a[n-1]-a[n/2-1];
    ans=max(ans,small0);
  }
  else{
    large0=0;
    small0=0;
    for(int i=0;i<n/2-1;i++){
      large0+=a[n-i-1]-a[i];
      large0+=a[n-i-1]-a[i+1];
    }
    large0+=a[n/2+1]-a[n/2-1];
    large0+=a[n/2]-a[0];
    ans=max(ans,large0);
    for(int i=0;i<n/2-1;i++){
      small0+=a[n-i-1]-a[i];
      small0+=a[n-i-2]-a[i];
    }
    small0+=a[n/2+1]-a[n/2-1];
    small0+=a[n-1]-a[n/2];
    ans=max(ans,small0);
  }
  cout<<ans<<endl;
}
