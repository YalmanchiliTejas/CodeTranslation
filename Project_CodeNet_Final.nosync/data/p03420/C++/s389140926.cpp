#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
long long sum;
int main() {
	scanf("%d %d",&n,&k);
	if(k==0) {
		printf("%lld\n",(long long)n*n);
		return 0;
	}
	for(int b=k+1;b<=n;b++) {
		int a=n%b;
		if(k<=a) sum+=a-k+1;
		sum+=n/b*(b-k);
	}
	printf("%lld\n",sum);
	return 0;
}