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
	
	i64 ans = 0;
	for(int d = 1; d < n; d++) {
		i64 sum = 0, tmp = 0, count = 1;
		std::set<int> st;
		for(int i = 0, j = n - 1; i < n and j > 0; i += d, j -= d) {
			sum += a[i];
			tmp += a[j];
			count += 2;
			
			if(st.count(i) or st.count(j) or i == j) break;
			st.insert(i); st.insert(j);
			
			i64 A = n - i - 1;
			i64 B = A - d;
			if(B <= 0) continue;
			ans = std::max(ans, sum + tmp);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
