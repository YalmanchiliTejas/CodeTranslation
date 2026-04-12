#include<bits/stdc++.h>
main(){
long long ans;
int n,k,b;
std::cin>>n>>k;
for (b=k+1;b<=n;++b)ans+=(b-k)*(n/b+1)-std::min(b-k,b-n%b-1)-!k;
std::cout<<ans;
}