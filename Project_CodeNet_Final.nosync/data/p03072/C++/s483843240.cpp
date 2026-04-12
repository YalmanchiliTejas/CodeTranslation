#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> h;
	int temp=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		if(k>=max(temp,k))
		{
			temp=k;
			ans++;
		}
	}
	cout<<ans<<endl;
}