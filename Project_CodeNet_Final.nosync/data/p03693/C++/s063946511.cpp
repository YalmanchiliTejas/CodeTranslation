#include<cstdio>
using namespace std;
int main(void){
	int r,g,y;
	int x;
	scanf("%d %d %d",&r,&g,&y);
	x=r*100+g*10+y;
	if(x%4==0)	printf("YES\n");
	else 		printf("NO\n");
	return 0;
}