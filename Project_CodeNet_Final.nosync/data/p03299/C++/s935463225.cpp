#include<cstdio>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;

const long long mod = 1000000007;

typedef pair<int, int> P;

map<P, long long> mp;

int a[110];
int N;

int vals[110];

long long mul(long long a, long long b){
	return (a * b) % mod;
}

long long ex(long long a, long long e){
	if(e == 0) return 1;
	long long tmp = ex(a, e / 2);
	tmp = mul(tmp, tmp);
	if(e % 2 == 1) tmp = mul(tmp, a);
	return tmp;
}

long long dp[110];

long long solve(){
	for(int i = 1; i <= N; ++i){
		int ub = a[i];
		for(int j = i; j <= N; ++j){
			ub = min(ub, a[j]);
			int lb = max(a[i - 1], a[j + 1]);
			if(lb == 0) lb = 1;
			if(ub > lb){
				mp[P(i, j)] = ub - lb;
			}
		}
	}
	dp[0] = 1;
	for(int i = 1; i <= N; ++i){
		long long e = 0;
		for(int j = i - 1; j >= 0; --j){
			for(int k = j + 1; k <= i; ++k){
				e += mp[P(j + 1, k)];
			}
			dp[i] += mul(dp[j], ex(2, e));
			dp[i] %= mod;
		}
	}
	long long ans = mul(dp[N], 2);
	ans += mod;
	ans %= mod;
	return ans;
}

void input(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", a + i);
	}
}

int main(){
	input();
	long long ans = solve();
	printf("%lld\n", ans);
	return 0;
}
