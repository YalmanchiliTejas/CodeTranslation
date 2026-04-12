#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
char s[100001];
signed main()
{
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<n;i++)
		if(s[i]!=s[i+1])
		{
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}
