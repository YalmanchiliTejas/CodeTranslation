#include<bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt","rt",stdin);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int p = arr[0];
	int c = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i] >= p)
		{
			c++;
			p = arr[i];
		}
	}
	cout<<c<<endl;
}