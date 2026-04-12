#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[10005];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}