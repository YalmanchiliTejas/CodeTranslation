#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c[3];
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%c",&c[i]);
	}
	if(c[0]==c[1]&&c[1]==c[2])
	printf("No");
	else
	printf("Yes");
}