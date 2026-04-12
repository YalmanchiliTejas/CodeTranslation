#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int h=0,f,maxv=0;
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		if(f>=maxv)
		{
			h++;
			maxv=f;
		}
	}
	cout<<h<<endl;
	return 0;
} 