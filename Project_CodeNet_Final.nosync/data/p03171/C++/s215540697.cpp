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
	int n; scanf("%d", &n); std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	auto dp = make_v<i64>(n + 1, n + 1);
	auto used = make_v<bool>(n + 1, n + 1);
	for(int i = 0; i < n + 1; i++) for(int j = 0; j < n + 1; j++) used[i][j] = dp[i][j] = 0;
	std::function<i64 (int, int)> solve = [&](int L, int R) {
		if(R < 0 or L > n) return 0LL;
		if(R - L + 1 == 0) return 0LL;
		if(used[L][R]) return dp[L][R];
		
		bool turn = ((R - L + 1) % 2 == n % 2);
		if(turn) {
			if(!used[L][R]) dp[L][R] = -(1LL << 60);
			
			dp[L][R] = std::max({dp[L][R], solve(L + 1, R) + a[L], solve(L, R - 1) + a[R]});
		} else {
			if(!used[L][R]) dp[L][R] = (1LL << 60);
	
			dp[L][R] = std::min({dp[L][R], solve(L + 1, R) - a[L], solve(L, R - 1) - a[R]});
		}
		used[L][R] = true;
		return dp[L][R];
	};
	solve(0, n - 1);
	if(n == 1) dp[0][n - 1] = a[0];
	
	printf("%lld\n", dp[0][n - 1]);
	return 0;
}
