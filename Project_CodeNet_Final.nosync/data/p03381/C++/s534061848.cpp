#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 100000000000LL
using namespace std;

int main()
{
	int n;
	long long int x[200000], x1[200000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &x[i]);
		x1[i]=x[i];
	}
	sort(x1, x1+n);
	for(int i=0; i<n; i++){
		if(x[i]<=x1[n/2-1]){
			printf("%lld\n", x1[n/2]);
		}else{
			printf("%lld\n", x1[n/2-1]);
		}
	}
	return 0;
}