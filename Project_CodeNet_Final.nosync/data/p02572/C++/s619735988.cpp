#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	const int Mod=1e9+7;
	int t;
	while(cin>>t)
	{
		int n[t],m[t];
		cin>>n[0];
		m[0]=n[0];
		for(int i=1;i<t;i++) 
		{
			cin>>n[i];
			m[i]=n[i]+m[i-1];
		}
		int sum=0;
		for(int i=0;i<t-1;i++)
		{
			sum=(m[t-1]-m[i])%Mod*n[i]+sum;
			sum%=Mod;
		}
		cout<<sum<<"\n";
	}
}
/*
1,2,3,4,5
1*(2+3+4+5)
2*(3+4+5)
*/