#include<bits/stdc++.h>
using namespace std;
long i,n,a[100010],ans;
int main(){
  cin>>n;
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  ans=a[n-1]+a[n-2]-(a[0]*2);
  for(i=1;i<n/2;i++)ans+=a[n-i]+a[n-i-2]-(a[i]*2);
  if(n%2&&a[n/2+1]-a[n/2]>a[n/2]-a[n/2-1])ans+=a[n/2+1]+a[n/2-1]-(a[n/2]*2);
  cout<<ans<<endl;
}
