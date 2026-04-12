#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int menor=0, cnt=0;
	for (int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		if (x>=menor)
		{
			cnt++;
			menor=x;
		}
	}
	cout<<cnt<<endl;
}