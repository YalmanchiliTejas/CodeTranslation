#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int x,y,z,a;
	while(~scanf("%d %d %d",&x,&y,&z))
	{
		for(a = 0; a <= (x - z)/(z + y) ; )
		{
			 a = a + 1;
		}
		a = a - 1;
		printf("%d\n",a);
	}
	return 0;
}