#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	std::string s; cin >> s;
	int K; scanf("%d", &K);
	
	const int MOD = 1e9 + 7;
	
	auto dp = make_v<i64>(s.size() + 1, K, 2); dp[0][0][1] = 1;
	for(int i = 0; i < s.size(); i++) {
		int D = s[i] - '0';
		
		for(int k = 0; k < K; k++) {
			for(int j = 0; j < 2; j++) {
				int lim = (j ? D + 1 : 10);
				for(int d = 0; d < lim; d++) {
					(dp[i + 1][(k + d) % K][j && (d == D)] += dp[i][k][j]) %= MOD;
				}
			}
		}
	}
	
	printf("%lld\n", ((dp[s.size()][0][0] + dp[s.size()][0][1]) % MOD + MOD - 1) % MOD);
	return 0;
}
