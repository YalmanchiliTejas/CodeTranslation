#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int d[1<<18];
map<long,long>M;
main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	long s=0,ans=0;
	for(long i=0;i<n;i++)
	{
		s+=d[i];
		if(!s)ans=max(ans,i+1);
		if(M[s])ans=max(ans,i-M[s]+1);
		else M[s]=i+1;
	}
	cout<<ans<<endl;
}