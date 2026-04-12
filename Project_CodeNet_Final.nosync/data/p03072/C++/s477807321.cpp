#include<bits/stdc++.h>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false);
	int max = 0,sum=0;
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a >= max)
		{
			sum++;
			max = a;
		}
	}
	cout << sum<<endl;
	return 0;
}