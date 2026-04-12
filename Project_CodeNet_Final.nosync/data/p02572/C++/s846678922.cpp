#include<iostream>
using namespace std;
const long mod=1e9+7;
int N;
long S,T;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		long A;cin>>A;
		S=(S+A*T)%mod;
		T=(T+A)%mod;
	}
	cout<<S<<endl;
}
