#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int main()
{
	int x,y,z,i;
	while(~scanf("%ld %ld %ld",&x,&y,&z))
	{
		i=(x-z)/(z+y);
		printf("%ld\n",i);
	}
}
