#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;
long long m;
int main(){
scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
if(a>=2*c&&x>=y){
	m=(long long)x*c*2;
}
else if(b>=2*c&&y>=x){
	m=(long long)y*c*2;
}
else if(a+b>=2*c){
	if(y>=x){
		m=(long long)x*c*2;
		m+=(long long)(y-x)*b;
	}
	else {
		m=(long long)y*c*2;
		m+=(long long)(x-y)*a;
	}
}
else {
	m=(long long)x*a+y*b;
}
printf("%lld",m);
	return 0;
}
