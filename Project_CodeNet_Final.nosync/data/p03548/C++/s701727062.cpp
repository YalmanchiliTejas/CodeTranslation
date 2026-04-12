#include <stdio.h>
#include <math.h>
#include <string.h>
#define inf 1000000007;
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
	int a,b,c,i,j,k;
	scanf("%d %d %d",&a,&b,&c);
	i=(a-c)/(b+c);
	printf("%d\n",i);
	return 0;
}
