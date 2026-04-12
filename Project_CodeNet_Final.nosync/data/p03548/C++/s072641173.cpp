#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	 int x,y,z,n,m;
	 scanf("%d %d %d",&x,&y,&z);
	 m=(x-z)%(y+z);
	 	 printf("%d\n",(x-z)/(y+z));
	return 0;
}

