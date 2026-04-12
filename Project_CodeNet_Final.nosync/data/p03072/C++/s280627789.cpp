#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	cin>>arr[1];
	
	int hasil=1;
	int i=2;
	
	lari:
	while (i<=n)
	{
		cin>>arr[i];
		for (int j=1;j<=i-1;j++)
		{
			if (arr[j]<=arr[i])
			{
				continue;
			}
			else
			{
				i++;
				goto lari;

			}
		}
		hasil++;
		i++;
	}
	
	cout<<hasil<<"\n";
	return 0;
}