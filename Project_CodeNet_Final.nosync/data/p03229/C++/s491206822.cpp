#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,ans=0;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++){
    long long l;
    cin>>l;
    a[i]=l;
  }
  sort(a,a+n);
    for(int i=0;i<n/2;i++){
      ans-=2*a[i];
    }
    for(int i=(n+1)/2;i<n;i++){
      ans+=2*a[i];
    }
  if(n%2==0){
    ans=ans+a[n/2-1]-a[n/2];
  }
  else{
   ans=ans-min(a[n/2]-a[n/2-1],a[n/2+1]-a[n/2]);
  }
  cout<<ans<<endl;
}
