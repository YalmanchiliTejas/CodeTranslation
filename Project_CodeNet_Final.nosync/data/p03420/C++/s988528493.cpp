#include <iostream>
long long n,k,a,i;int main(){std::cin>>n>>k;if(!k)a=n*n;else for(i=k+1;i<=n;i++)a+=n/i*(i-k)+(n-n/i*i>=k?n-n/i*i-k+1:0);std::cout<<a;}