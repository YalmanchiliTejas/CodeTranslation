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
	std::string s; cin >> s;
	int K; scanf("%d", &K);

	auto dp = make_v<int>(s.size() + 1, 2, K + 2); dp[0][0][0] = 1;
	for(int i = 0; i < s.size(); i++) {
		const int D = s[i] - '0';

		for(int j = 0; j < 2; j++) {
			for(int d = 0; d <= (j ? 9 : D); d++) {
				for(int k = 0; k < K + 1; k++) {
					dp[i + 1][j | (d < D)][k + !!d] += dp[i][j][k];
				}
			}
		}
	}
	
	printf("%lld\n", dp[s.size()][0][K] + dp[s.size()][1][K]);
	return 0;
}
