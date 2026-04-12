#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll N,M,K;
main()
{
    cin>>N>>M>>K;
    ll A=1,B=1,C=1;
    for(int i=1;i<=M*N-2;i++)A=A*i%mod;
    for(int i=1;i<=M*N-K;i++)B=B*i%mod;
    for(int i=1;i<=K-2;i++)C=C*i%mod;
	cout<<A*power(B*C%mod,mod-2)%mod*((mod+1)/2)%mod*(N*N%mod*M%mod*(M+1)%mod*(M-1)%mod+M*M%mod*N%mod*(N+1)%mod*(N-1)%mod)%mod*power(3,mod-2)%mod<<endl;
    return 0;
}