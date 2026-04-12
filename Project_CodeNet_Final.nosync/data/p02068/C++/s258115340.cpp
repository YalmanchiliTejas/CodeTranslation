#include<iostream>
#include<set>
using namespace std;
int N,A[1000];
set<int>S;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		for(int j=1;j*j<=A[i];j++)
		{
			if(A[i]%j==0)
			{
				S.insert(j);
				S.insert(A[i]/j);
			}
		}
	}
	S.erase(S.find(1));
	long ans=0;
	for(int s:S)
	{
		long now=0;
		for(int i=0;i<N;i++)
		{
			if(A[i]%s==0)now+=A[i];
		}
		if(ans<now)ans=now;
	}
	cout<<ans<<endl;
}

