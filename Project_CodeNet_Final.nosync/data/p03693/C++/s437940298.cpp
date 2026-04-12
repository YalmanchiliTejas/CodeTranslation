#include<stdio.h>

int main(void) {
	int r, g, b,num;
	char buf[128];
	
	fgets(buf,128,stdin);
	sscanf(buf,"%d %d %d",&r,&g,&b);
	
	num = r*100 + g*10 + b*1;
	
	if(num%4 == 0) {
		printf("YES");
	} else {
		printf("NO");
	}
	
	return 0;
}