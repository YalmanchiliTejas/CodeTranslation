#include<stdio.h>
int main(void)
{
	int n,a,s,i,x[100],max,flg,c;
	while(1){
		scanf("%d %d",&a,&s);
		if(a==0&&s==0) break;
				x[0]=a+s;	
			for(i=1;i<5;i++){
				scanf("%d %d",&a,&s);	
					x[i]=a+s;
			}
		max=-1;
			for(i=0;i<5;i++){
				if(max<x[i]){
					max=x[i];
					c=i;
				}
			}
		if(c==0){
			printf("A %d\n",max);
		}
		if(c==1){
			printf("B %d\n",max);
		}
		if(c==2){
			printf("C %d\n",max);
		}
		if(c==3){
			printf("D %d\n",max);
		}
		if(c==4){
			printf("E %d\n",max);
		}		
	}
	return 0;
}