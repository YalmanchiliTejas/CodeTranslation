#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
int main(){
	ll k,a,b,ans=0x7fffffffffffffff;
	scanf("%lld%lld%lld",&k,&a,&b);
	if(a>=k){
		printf("1\n");
		return 0;
	}
	if(a-b<=0){
		printf("%d\n",-1);
		return 0;
	}
	printf("%.0Lf\n",ceil((long double)(k-a)/(a-b))*2+1);
	return 0;	
}