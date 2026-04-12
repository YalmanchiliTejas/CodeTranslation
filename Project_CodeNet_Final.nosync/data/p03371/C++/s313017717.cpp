#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y,k,m;
	long long sum=0;
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	if(x>y){
		k=1;m=y;
	}else{
		k=2;m=x;
	}
	sum+=m*min(a+b,2*c);
	if(k==1){
		sum+=(x-m)*min(a,c*2);
	}
	else{
		sum+=(y-m)*min(b,c*2);
	}
	printf("%d\n",sum);
	return 0;
} 