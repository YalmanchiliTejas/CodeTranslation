#include<stdio.h>
int main(void)
{
	int x,y,z,cnt,w;
	scanf("%d %d %d",&x,&y,&z);
	cnt=0;
	w=y+z;
	x-=z;
	while(1){
		if(x>=w){
			cnt++;
			x-=w;
		}
		else	break;
	}
	printf("%d\n",cnt);
	return 0;
}
