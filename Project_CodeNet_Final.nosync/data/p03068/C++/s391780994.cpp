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
	int n, k; scanf("%d", &n);
	std::string s; cin >> s;
	scanf("%d", &k);
	
	for(auto v: s) {
		if(v == s[k - 1]) printf("%c", v);
		else printf("*");
	}
	printf("\n");
	return 0;
}
