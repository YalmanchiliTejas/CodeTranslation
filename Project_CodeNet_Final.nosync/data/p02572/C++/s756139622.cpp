#include <iostream>
using namespace std;
int main(){
   long long i,n,a[200010],suff[200010];
   cin>>n;
   for(i=1;i<=n;i++){
       cin>>a[i];
   }
   for(i=n-1,suff[n]=a[n];i>1;i--){
       suff[i]=(a[i]+suff[i+1])%1000000007;
   }
   long long ans=0;
   for(i=1;i<n;i++){
       ans+=a[i]*suff[i+1];
       ans%=1000000007;
   }
   cout<<ans;
}