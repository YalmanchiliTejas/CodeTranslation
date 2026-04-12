#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int main(void)
{
	long long i,j,n,a[200000],m,k=1000000000+7,w;
	scanf("%lld",&n);
	m=0; w=0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		w+=a[i];
		w%=k;
	}
	for(i=0;i<n;i++){
		w-=a[i];
		if(w<0){
			w+=k;
		}
		m+=a[i]*w;
		m%=k;
	}
	printf("%d\n",m);
	return 0;
}