#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int e[12],i,flg;
	for(i=0;i<12;i++)	scanf("%d",&e[i]);
	sort(e,e+12);
	flg=1;
	for(i=0;i<3;i++)	{
		if(e[i]!=e[i+1])	flg=0;
	}
	for(i=4;i<7;i++)	{
		if(e[i]!=e[i+1])	flg=0;
	}	
	for(i=8;i<11;i++)	{
		if(e[i]!=e[i+1])	flg=0;
	}
	if(flg==1)	printf("yes\n");
	else printf("no\n");
    return 0;
}
