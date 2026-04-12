#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>

using namespace std;

int main()
{
	char s[10];
	scanf("%s",s);
	for (int i=0;i<strlen(s)-1;i++)
	{
		if (s[i]=='A')
		{
			if (s[i+1]=='C')
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
