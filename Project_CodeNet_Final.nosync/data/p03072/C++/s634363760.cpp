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
	int n; scanf("%d", &n);
	
	int ans = 1, a; scanf("%d", &a);
	for(int i = 0; i < n - 1; i++) {
		int b; scanf("%d", &b);
		
		ans += (a <= b);
		a = std::max(a, b);
	}

	printf("%d\n", ans);
	return 0;
}
