#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int i;
char ch[10000];
int main()
{
	scanf("%s",ch);
	for (i=1;i<strlen(ch);i++)
	{
		if (ch[i-1]=='A'&&ch[i]=='C') 
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}