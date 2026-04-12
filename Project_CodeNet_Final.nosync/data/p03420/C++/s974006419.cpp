#include<cstdio>
#include<algorithm>

using namespace std;

int N, K;

long long solve(){
	long long ans = 0;
	for(int b = 1; b <= N; ++b){
		int t = N / b;
		int r = N % b;
		int tmp = t * (max(0, b - K));
		tmp += max(0, r - K + 1);
		if(K == 0) tmp--;
		ans += tmp;
	}
	return ans;
}

int main(){
	scanf("%d%d", &N, &K);
	long long ans = solve();
	printf("%lld\n", ans);
	return 0;
}
