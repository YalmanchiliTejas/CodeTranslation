#include<stdio.h>

int main()
{
	int dice[]={1,2,3},aa,x,t;
	char a[10];
	while(1){
		dice[0]=1;
		dice[1]=2;
		dice[2]=3;
	scanf("%d",&aa);
	if(aa==0) break;
	t=1;
	for(int i=0;i<aa;i++)
	{
		scanf("%s",&a);
		if(a[0]=='N'){
			x=dice[0];
			dice[0]=dice[1];
			dice[1]=7-x;
		}
		if(a[0]=='S'){
			x=dice[0];
			dice[0]=7-dice[1];
			dice[1]=x;
		}
		if(a[0]=='E'){
			x=dice[0];
			dice[0]=7-dice[2];
			dice[2]=x;
		}
		if(a[0]=='W'){
			x=dice[0];
			dice[0]=dice[2];
			dice[2]=7-x;
		}
		if(a[0]=='L'){
			x=dice[1];
			dice[1]=7-dice[2];
			dice[2]=x;
		}
		if(a[0]=='R'){
			x=dice[1];
			dice[1]=dice[2];
			dice[2]=7-x;
		}
		t=t+dice[0];
	}
	printf("%d\n",t);
	}
	return 0;
}