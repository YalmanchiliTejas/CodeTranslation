#include <stdio.h>
int main(void)
{
	int a,b,c=1,d,e[100]={0},f[10]={1,2,3,5,4,6},i,j,g=0;
	char t[10];
	while(0==0){
		scanf("%d",&a);
		if(0==a){
			break;
		}
		for(i=0;i<a;i++){
			scanf("%s",t);
			if(t[0] == 'N'){
				b=f[0];
				f[0]=f[1];
				f[1]=f[5];
				f[5]=f[3];
				f[3]=b;
			}
			else if(t[0] == 'E'){
				b=f[0];
				f[0]=f[4];
				f[4]=f[5];
				f[5]=f[2];
				f[2]=b;
			}
			else if(t[0] == 'W'){
				b=f[0];
				f[0]=f[2];
				f[2]=f[5];
				f[5]=f[4];
				f[4]=b;
			}
			else if(t[0] == 'S'){
				b=f[0];
				f[0]=f[3];
				f[3]=f[5];
				f[5]=f[1];
				f[1]=b;
			}
			else if(t[0] == 'R'){
				b=f[1];
				f[1]=f[2];
				f[2]=f[3];
				f[3]=f[4];
				f[4]=b;
			}
			else{
				b=f[1];
				f[1]=f[4];
				f[4]=f[3];
				f[3]=f[2];
				f[2]=b;
			}
			c=c+f[0];
		}
		e[g]=c;
		g++;
		f[0]=1;
		f[1]=2;
		f[2]=3;
		f[3]=5;
		f[4]=4;
		f[5]=6;
		c=1;
	}
	for(i=0;i<g;i++){
		printf("%d\n",e[i]);
	}
	return 0;
}