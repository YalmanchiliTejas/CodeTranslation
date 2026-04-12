#include<iostream>
using namespace std;
const long mod=1e9+7;
string C;
long p10[10101];
long f(string A)
{
	long a[10101]={};
	a[A.size()]=1;
	for(int i=A.size();i--;)
	{
		a[i]=(a[i+1]+p10[A.size()-i-1]*(A[i]-'0'))%mod;
	}
	int zf=C=="0"?1:0;
	long ret=zf,cur=0;
	for(int i=0;i+C.size()<=A.size();i++)
	{
		int t=0;
		for(int j=0;j<C.size();j++)
		{
			if(A[i+j]!=C[j])
			{
				t=A[i+j]<C[j]?-1:1;
				break;
			}
		}
		(ret+=(cur+(t==1)-zf)*p10[A.size()-i-C.size()])%=mod;
		if(t==0)(ret+=a[i+C.size()])%=mod;
		cur=(cur*10+A[i]-'0')%mod;
	}
	return ret;
}
main()
{
	p10[0]=1;
	for(int i=1;i<10101;i++)p10[i]=p10[i-1]*10%mod;
	string A,B;
	cin>>A>>B>>C;
	long b=f(B);
	if(A!="0")
	{
		A[A.size()-1]--;
		for(int i=A.size();i--;)
		{
			if(A[i]<'0')
			{
				A[i]+=10;
				A[i-1]--;
			}
			else break;
		}
		b+=mod-f(A);
	}
	cout<<b%mod<<endl;
}

