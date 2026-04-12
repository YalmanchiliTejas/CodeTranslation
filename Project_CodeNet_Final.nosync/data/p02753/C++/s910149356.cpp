#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int i;
	int sum=0,num=0;
	char ch[10005];
	scanf("%[^\n]",ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='A')
		sum++;
		if(ch[i]=='B')
		num++;
	}
	if(sum>0&&num>0)
	printf("Yes");
	else
	printf("No");
}
