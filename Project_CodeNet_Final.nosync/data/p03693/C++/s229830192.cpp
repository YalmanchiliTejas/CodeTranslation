#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	int temp=100*r+10*g+b;
	if(temp%4==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}