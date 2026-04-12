#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int count=0;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		int flag=1;
		int count=0;
		for (int j = 0; j < i; ++j)
		{
			if(v[j]>v[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)count++;
		ans+=count;
	}
	cout<<ans<<endl;;
}	
