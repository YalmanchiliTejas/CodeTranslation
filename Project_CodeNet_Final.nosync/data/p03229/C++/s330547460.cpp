#include<bits/stdc++.h>
using namespace std;
long i,n,a[100010],b[100010],ans,tmp1,tmp2;
int main(){
  cin>>n;
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  if(n&1){
    for(i=0;i<n/2;i++)b[i*2+1]=a[i];
    b[n-1]=a[n/2];
    for(i=0;i<n/2;i++)b[i*2]=a[n/2+1+i];
    for(i=0;i<n-1;i++)tmp1+=abs(b[i+1]-b[i]);

    b[0]=a[n/2];
    for(i=0;i<n/2;i++)b[i*2+2]=a[i];
    for(i=0;i<n/2;i++)b[i*2+1]=a[n/2+1+i];
    for(i=0;i<n-1;i++)tmp2+=abs(b[i+1]-b[i]);
    
    ans=max(tmp1,tmp2);
  }else{
    for(i=0;i<n/2;i++)b[i*2+1]=a[i];
    for(i=0;i<n/2;i++)b[i*2]=a[n/2+i];
    for(i=0;i<n-1;i++)ans+=abs(b[i+1]-b[i]);
  }
  cout<<ans<<endl;
}
