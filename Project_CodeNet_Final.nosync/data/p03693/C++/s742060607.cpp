#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	int a,b,c,sum;
	while(~scanf("%d %d %d",&a,&b,&c))
	{
		sum=a*100+b*10+c;
		if(sum%4==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
