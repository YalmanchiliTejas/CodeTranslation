#include<stdio.h>
int main(void)
{
	
	int n,i,temp;
	char str[10];
	while(1){
		int top=1,yoko[4]={2,3,5,4},soko=6,total=1;
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%s",str);
			switch(str[0]){
				case 'N':
					temp=top;
					top=yoko[0];
					yoko[0]=soko;
					soko=yoko[2];
					yoko[2]=temp;
					break;
				case 'E':
					temp=top;
					top=yoko[3];
					yoko[3]=soko;
					soko=yoko[1];
					yoko[1]=temp;
					break;
				case 'S':
					temp=top;
					top=yoko[2];
					yoko[2]=soko;
					soko=yoko[0];
					yoko[0]=temp;
					break;
				case 'W':
					temp=top;
					top=yoko[1];
					yoko[1]=soko;
					soko=yoko[3];
					yoko[3]=temp;
					break;
				case 'R':
					temp=yoko[0];
					yoko[0]=yoko[1];
					yoko[1]=yoko[2];
					yoko[2]=yoko[3];
					yoko[3]=temp;
					break;
				case 'L':
					temp=yoko[0];
					yoko[0]=yoko[3];
					yoko[3]=yoko[2];
					yoko[2]=yoko[1];
					yoko[1]=temp;
					break;
				default :
					break;
			}
			total+=top;
		}
		printf("%d\n",total);
	}
	return 0;
}