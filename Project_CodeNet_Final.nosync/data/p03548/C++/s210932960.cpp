#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
using namespace std;
typedef long long ll;

int main() {
	ll x , y, z;
	cin >> x >> y >> z;
	ll l = 0;
	ll r = 1e5;
	ll c = (l+r)/2;
	while(r - l > 1){
		if(y*c + z*(c+1) <= x){
			l = c;
		}else{
			r = c;
		}
		c = (l+r)/2;
	}
	cout << l << endl;
	return 0;
}
