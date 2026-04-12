#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,max,ans,i,temp;
	cin >> n;
	max = -1;
	ans = 0;
	for(i=0; i<n; i++)
	{
		cin >> temp;
		if(temp >= max)
		{
			max = temp;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
