#include <stdio.h>
#include <iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c,x,y,same;
    long long int mon=0;
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	if(x==0) mon=y*b;
	else if(y==0) mon=x*a;
	else{
		same=max(x,y)-abs(x-y);
		if(2*c>a+b) mon+=(a+b)*same;
		else mon+=2*c*same;
		int k=(x-y>0?x:y)-same;
		if(x>y) mon+=k*a;
		else mon+=k*b;
	}
	long long int m;
	m=2*c*max(x,y);
	printf("%lld",min(mon,m));
	
	
	return 0;
}