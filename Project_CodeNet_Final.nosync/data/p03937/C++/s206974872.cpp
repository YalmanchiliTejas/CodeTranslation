#include <bits/stdc++.h>
using namespace std;
int H,W,ans,cnt;
char c;
int main()
{
	scanf("%d %d",&H,&W);
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			scanf(" %c",&c);
			if(c=='#')
				cnt++;
		}
	}
	ans=H+W-1;
	//~ printf("%d %d\n",ans,cnt);
	
	if(cnt==ans)
	{
		printf("Possible");
		return 0;
	}
	printf("Impossible");

}
