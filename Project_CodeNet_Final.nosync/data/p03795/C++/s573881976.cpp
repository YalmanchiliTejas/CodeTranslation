#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c=0;
	scanf("%d",&n);
	if(n>=1&&n<=100)
	{
		for(int x=1;x<=n;x++)
		{
			c+=800;
			if(x==15||x==30||x==45||x==60||x==75||x==90)
			{
				c-=200;
			}
			
		}
		printf("%d",c);
	}
}