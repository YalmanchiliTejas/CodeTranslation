#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
const int INF = 1000000009;

long n, k;

int main(){
	scanf("%ld%ld", &n, &k);
	if(k == 0){
		printf("%ld\n", n*n);
		return 0;
	}
	long ans = 0;
	for(long i = k+1; i <= n; i++){
		ans += n / i * (i-k);
		ans += std::max((long)0, n%i - k + 1);
	}
	printf("%ld\n", ans);
	return 0;
}
