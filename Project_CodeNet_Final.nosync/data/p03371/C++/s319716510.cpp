#include <stdio.h>
int main(void){
    int a,b,c,x,y,s[3],i,min;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	s[0]=(a*x)+(b*y);
	if(x>y){ 
	    s[1]=(x*2)*c;
	    s[2]=(y*2*c)+(x-y)*a;
	}
	else{
	    s[1]=(y*2)*c;
	    s[2]=(x*c*2)+(y-x)*b;
	}
	min=s[0];
	for(i=0;i<3;i++){
	    if(min>s[i]) min=s[i];

	}
	printf("%d\n",min);
	return 0;
}
