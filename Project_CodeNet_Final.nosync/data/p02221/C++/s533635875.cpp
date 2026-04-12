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
	int n; scanf("%d", &n);
	int N = 1 << n;
	static std::string s; cin >> s; std::vector<int> p(N);
	for(int i = 0; i < N; i++) scanf("%d", &p[i]);
	
	struct node {
		int id;

		node(int id = -1): id(id) {}
		node operator+(node r) const {
			if(id == -1) return r;
			if(r.id == -1) return (*this);
			
			if(id < r.id) return (s[r.id - id - 1] == '0' ? (*this) : r);
			return (s[id - r.id - 1] == '0' ? r : (*this));
		};
	};

	auto dp = make_v<node>(n + 1, 2 * N);
	for(int i = 0; i < N; i++) dp[0][i] = dp[0][i + N] = node(p[i]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j + (1 << i) < 2 * N; j++) {
			dp[i + 1][j] = dp[i][j] + dp[i][j + (1 << i)];
		}
	}

	for(int i = 0; i < N; i++) printf("%d\n", dp[n][i].id);
	return 0;
}

