#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int h[n];
	for(int i = 0; i < n;i++)
		cin >> h[i];
	int current = h[0];
	int result = 1;
	for(int i = 1; i < n;i++)
	{
		if(h[i] >= current)
			{
				result++;
				current = h[i];
			}
	}
	cout << result << endl;
}