#include<stdio.h>

int main(){
	int n,a,b,c,x,i,t,y[101];
	for( ; scanf("%d%d%d%d%d",&n,&a,&b,&c,&x),n; printf("%d\n",t>10000?-1:t) ){
		for(i=0;i<n;)
			scanf("%d",y+i++);
		for(t=i=0;t<10001&i<n;x=(a*x+b)%c,t++)
			if(y[i]==x&&++i==n)break;
	}
}