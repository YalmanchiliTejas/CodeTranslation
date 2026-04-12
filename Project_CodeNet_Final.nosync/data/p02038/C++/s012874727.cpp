#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,n;
	char c,d;
	scanf("%d",&n);
	c='T';
	for(i=0;i<n;i++)	{
		scanf(" %c",&d);
		if(c=='T' && d=='T')	c='T';
		else if(c=='T' && d=='F')	c='F';
		else if(c=='F' && d=='T')	c='T';
		else c='T';
	}
	printf("%c\n",c);
	return 0;
}
