#include <cstdio>
#include <cmath>
int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	printf("%d\n",(int)floor((float)(x-z)/(y+z)));
	return 0;
}