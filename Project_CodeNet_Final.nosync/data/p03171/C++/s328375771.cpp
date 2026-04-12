#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int ll;
static const int MAX_N = 3000;

int N;
ll a[MAX_N];
ll memo[MAX_N][MAX_N];

ll memoize(int left, int right){
	int itv = right - left + 1;
	if(left == right){
		if(N % 2 == 1) return memo[left][right] = a[left];
		else return memo[left][right] = -a[left];
	}
	if(memo[left][right] != -1) return memo[left][right];
	if((N - itv) % 2 == 0){
		return memo[left][right] = max(memoize(left + 1, right) + a[left], memoize(left, right - 1) + a[right]);
	}else{
		return memo[left][right] = min(memoize(left + 1, right) - a[left], memoize(left, right - 1) - a[right]);
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%lld", &a[i]);
	fill(memo[0], memo[N], -1);
	printf("%lld\n", memoize(0, N - 1));
	return 0;
}
