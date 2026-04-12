#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,x,y;
int sum=0;
int v,z;
int main() {
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	if(2*c<=a+b)
		sum+=min(x,y)*2*c;
	else sum+=min(x,y)*(a+b);
	if(y>x) z=y-x,v=b;
	else z=x-y,v=a;
	sum+=min(2*c*z,z*v);
	printf("%d\n",sum);
}