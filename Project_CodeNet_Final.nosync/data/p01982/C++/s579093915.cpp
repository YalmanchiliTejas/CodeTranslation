#include<bits/stdc++.h>
#define range(i,a,b) for(long long i = (a); i < (b); i++)
#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;
 
template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}
template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}
template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

bool isUru(vector<int>& a, int x, int n){
	rep(i,a.size()){
		if(x % a[i] == 0){
			return i % 2 == 0;
		}
	}
	return n % 2 == 0;
}

int main(){
	int n, l, r;
	while(cin >> n >> l >> r, n){
		vector<int> a(n);
		rep(i,n){
			cin >> a[i];
		}

		int ans = 0;
		range(i,l,r+1){
			ans += isUru(a, i, n);
		}
		cout << ans << endl;
	}
}

