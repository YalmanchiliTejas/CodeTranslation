#include<stdio.h>
int main(void)
{
	int a,s,d,i,max,f,flg;
	flg=0;
	while(1){
	max=0;
		for(i=1;i<=5;i++){
		scanf("%d %d",&a,&s);
		if(a==0 && s==0){
			flg=1;
			break;
		}
			d=a+s;
			if(max<d){
				max=d;
				f=i;
			}
		}
		if(flg==1){
			break;
		}
	if(f==1){
		printf("A %d\n",max);
	}
	if(f==2){
		printf("B %d\n",max);
	}
	if(f==3){
		printf("C %d\n",max);
	}
	if(f==4){
		printf("D %d\n",max);
	}
	if(f==5){
		printf("E %d\n",max);
	}
	}
	return 0;
}