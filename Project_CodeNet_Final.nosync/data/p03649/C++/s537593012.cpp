#include<bits/stdc++.h>
long long a[55],n,i,x,ans;//
main(){
for(std::cin>>n;i<n;std::cin>>a[++i]);
for(;std::sort(a+1,a+n+1),a[n]>=n;a[n]%=n)for(ans+=x=a[n]/n,i=1;i<n;a[i++]+=x); 
std::cout<<ans<<'\n';
}