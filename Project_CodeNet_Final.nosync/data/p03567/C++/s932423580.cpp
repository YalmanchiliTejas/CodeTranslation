#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	char str[6] = {0};
	scanf("%s",str);
	int i;
	for(i=0;i<5;i++)
	{
		if(str[i]=='A' && str[i+1]=='C')
		{
			printf("Yes\n");
			break;
		}
	}
	if(i == 5)
		printf("No\n");
	return 0;
}