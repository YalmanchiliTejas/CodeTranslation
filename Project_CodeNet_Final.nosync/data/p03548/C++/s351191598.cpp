#include <cstdio>
#include <cstring>
#include <cstdlib>
int main()
{
	int x,y,z;
	while(~scanf("%d %d %d",&x,&y,&z)){
		int flag=0;
		x=x-2*z;
		flag=x/(z+y);
		x=x%(z+y);
		if(x>=y) flag++;
		printf("%d\n",flag);
	}
	return 0;
}