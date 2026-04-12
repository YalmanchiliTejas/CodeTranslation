#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == 'A'&&s[i + 1] == 'C')
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}