#include<stdio.h>
int n,t,e,r,x;
int main() {
	scanf("%d%d%d",&n,&t,&e);r=-1;
	for(int i=0;i<n;i++) {
		scanf("%d",&x);
		if(t-e<=(t+e)/x*x)r=i+1;
	}
	printf("%d\n",r);
}