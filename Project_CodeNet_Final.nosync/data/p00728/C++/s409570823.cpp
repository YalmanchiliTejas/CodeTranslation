#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n) 
	{
		int in[n];
		for(int i = 0; i < n; ++i)
		{
			cin>>in[i];
		}
		sort(in,in+n);
		int ans=0;
		for(int i = 1; i < n-1; ++i)
		{
			ans+=in[i];
		}
		cout<<ans/(n-2)<<endl;
	}
  return 0;
}