#include<bits/stdc++.h>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false);
	int n, k;
	string str;
	cin >> n >> str >> k;
	for (int i = 0; i < n; i++)
	{
		if (str[i] != str[k - 1])
		{
			str[i] = '*';
		}
	}
	cout << str;
	return 0;
}