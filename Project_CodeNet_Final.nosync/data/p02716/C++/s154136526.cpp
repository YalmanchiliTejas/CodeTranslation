#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
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

	auto dp = make_v<i64>(n / 2 + 1, 4);
	for(int i = 0; i < (int)dp.size(); i++) for(int j = 0; j < (int)dp[i].size(); j++) dp[i][j] = -(1LL << 60);

	dp[0][0] = dp[0][1] = 0;
	for(int i = 0; i < n / 2; i++) {
		dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][0] + a[i * 2]);
		dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][0] + a[i * 2 + 1]);
		dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][1] + a[i * 2 + 1]);

		dp[i + 1][2] = std::max(dp[i + 1][2], dp[i][2] + a[i * 2]);
		dp[i + 1][3] = std::max(dp[i + 1][3], dp[i][2] + a[i * 2 + 1]);
		dp[i + 1][3] = std::max(dp[i + 1][3], dp[i][3] + a[i * 2 + 1]);

		dp[i + 1][2] = std::max({dp[i + 1][2], dp[i][0], dp[i][1]});
		dp[i + 1][3] = std::max({dp[i + 1][3], dp[i][0], dp[i][1]});
	}
	
	i64 ans = -(1LL << 60);
	if(n % 2) {
		ans = std::max({dp.back()[0], dp.back()[1], dp.back()[2] + a.back()});
	} else {
		ans = std::max(dp.back()[0], dp.back()[1]);
	}
	printf("%lld\n", ans);
	return 0;
}
