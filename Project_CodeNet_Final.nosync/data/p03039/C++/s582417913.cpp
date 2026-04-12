#include<iostream>
using namespace std;
long mod=1e9+7;
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
long N,M,K;
main()
{
	cin>>N>>M>>K;
	long A=1,B=1,C=1;
	for(int i=1;i<=N*M-2;i++)A=A*i%mod;
	for(int i=1;i<=N*M-K;i++)B=B*i%mod;
	for(int i=1;i<=K-2;i++)C=C*i%mod;
	cout<<A*power(B*C%mod,mod-2)%mod*((mod+1)/2)%mod*(N*N%mod*M%mod*(M+1)%mod*(M-1)%mod+M*M%mod*N%mod*(N+1)%mod*(N-1)%mod)%mod*power(3,mod-2)%mod<<endl;
}