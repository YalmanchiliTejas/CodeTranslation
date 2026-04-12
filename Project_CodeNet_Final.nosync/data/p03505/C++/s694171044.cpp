#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	ll n,a,b;
	scanf("%lld%lld%lld",&n,&b,&a);
	n-=b;
	if(n<=0){
		printf("1");
		return 0;
 	}
	if(a>=b){
		printf("-1");
		return 0;
	}
	ll bb=(b-a);ll nn=n/bb;
	if(bb*nn<n)
		printf("%lld",(nn+1)*2+1);
	else printf("%lld",nn*2+1);
	return 0;
}
