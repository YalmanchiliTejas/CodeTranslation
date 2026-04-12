#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long i, j;
	for(i=0; i<(1 << n); i++)
	{
		cout << i << ":";
		for(j=0; j<n; j++)
		{
			if(i & (1 << j)) cout << " " << j;
		}
		cout << endl;
	}
	return 0;
}
