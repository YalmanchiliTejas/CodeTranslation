#include <stdio.h>
 
int main(void) {
	int a,b,c,x,y,i,ans;
	int pt[10];
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	pt[0]=a*x+b*y;
	if(x<y){
		pt[1]=2*c*x+(y-x)*b;
		pt[2]=2*c*y;
	}else{
		pt[1]=2*c*y+(x-y)*a;
		pt[2]=2*c*x;
	}
	ans=pt[0];
	for(i=0;i<3;i++){
		if(ans>pt[i]){
			ans=pt[i];
		}
	}
	printf("%d",ans);
	return 0;
}