#include<stdio.h>

int main(){
	int n,a,b,c,x,i,t,y[101];
	for( ; scanf("%d%d%d%d%d",&n,&a,&b,&c,&x),n|a|b|c|x ; printf("%d\n",t>10000?-1:t) ){
		for(i=0;i<n;i++)
			scanf("%d",y+i);
		for(t=i=0;t<10001&&i<n;){
			if( y[i] == x )
				if(++i==n)break;
			x=(a*x+b)%c;
			t++;
		}
	}
}