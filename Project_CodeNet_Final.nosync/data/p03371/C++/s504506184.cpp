#include <stdio.h>
int main(void)
{
	int a,b,c,x,y,i,m,mini=2147483647;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	for(i=0; i<=100000; i++){
		if(i>=x && i>=y){
			m=i*2*c;
			if(mini>m){
				mini=m;
			}
			break;
		}
		if(i<x && i>=y){
			m=i*2*c+(x-i)*a;
			if(mini>m){
				mini=m;
			}
		}
		if(i>=x && i<y){
			m=i*2*c+(y-i)*b;
			if(mini>m){
				mini=m;
			}
		}
		if(i<x && i<y){
			m=i*2*c+(x-i)*a+(y-i)*b;
			if(mini>m){
				mini=m;
			}
		}
	}
	printf("%d\n",mini);
	return 0;
}