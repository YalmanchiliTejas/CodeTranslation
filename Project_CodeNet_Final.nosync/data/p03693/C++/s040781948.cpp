#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,tot=0;
	for(int i=1;i<=3;i++)
	{
		scanf("%d",&x);
		tot=tot*10+x;
	}
	tot%4==0?printf("YES\n"):printf("NO\n");
	return 0;
}