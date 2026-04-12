#include <stdio.h>
#define P 800;
int main(){
	int n,x,y,i=0;
	scanf("%d", &n);
	x=n*800;
	while(n>=15){
		n-=15;
		i++;
	}
	y=i*200;
	printf("%d", x-y);
}