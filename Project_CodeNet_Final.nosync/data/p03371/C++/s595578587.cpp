#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
	int a,b,c,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	int ans=min(min(c*max(x,y)*2,c*min(x,y)*2+a*(x-min(x,y))+b*(y-min(x,y))),a*x+b*y);
	printf("%d\n",ans);
	return 0;
}