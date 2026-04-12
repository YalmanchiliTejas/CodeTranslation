#include<cstdio>

using namespace std;
long long a[51],p[51];

long long f(int n,long long int x){
	if(n == 0){
		return x<=0?0:1;
	}
	if(x == 1)
		return 0;
	if(x <= 1 + a[n-1])
		return f(n-1,x-1);
	else if(x == 2 + a[n-1])
		return 1 + p[n-1];
	else if(x <= 2 + 2 * a[n-1])
		return p[n-1] + 1 + f(n-1,x-2-a[n-1]);
	else if(x == 3 + 2*a[n-1])
		return 1 + 2*p[n-1];
}
int main(){
	int n;
	long long x;
	scanf("%d %lld",&n,&x);
	a[0] = 1;
	p[0] = 1;
	for(int i = 1;i<n;i++){
		a[i] = 2*a[i-1] + 3;
		p[i] = 2*p[i-1] + 1;
//		printf("[%d]:%lld\n",i,a[i]);
	}
	printf("%lld\n",f(n,x));
}
