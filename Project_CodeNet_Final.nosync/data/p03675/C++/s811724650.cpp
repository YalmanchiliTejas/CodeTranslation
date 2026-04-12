#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int main(){
	long n;
	long long a[200000];
	long long b[200000];

	scanf("%ld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}

	if(n%2==0){
		for(int i=0;i<=n/2;i++){
			b[i] = a[n-1-2*i];
		}
		for(int i=0;i<n/2;i++){
			b[n/2+i] = a[2*i];
		}
	}
	if(n%2==1){
		for(int i=0;i<(n+1)/2;i++){
			b[i] = a[n-1-2*i];
		}
		for(int i=1;i<(n+1)/2;i++){
			b[(n-1)/2+i] = a[2*i-1];
		}
	}

	for(int i=0;i<n;i++){
		printf("%lld ",b[i]);
	}
	printf("\n");

	return 0;
}
