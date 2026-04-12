#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define int long long
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

string make(string a){
	return "." + a + "P" + a + ".";
}

int x;
vector<int> size, p;

void make(){
	size.emplace_back(1);
	p.emplace_back(1);
	rep(i,50){
		size.emplace_back(size.back() * 2 + 3);
		p.emplace_back(p.back() * 2 + 1);
	}
	//cout << size << endl;
	//cout << p << endl;
}

int dfs(int left, int level){
	int right = left + size[level];
	if(right <= x){ // x contain left-right range
		return p[level];
	}else if(left < x and x < right){
		return dfs(left + 1, level - 1) +
			dfs(left + size[level - 1] + 1, 0) +
			dfs(left + size[level - 1] + 2, level - 1);
	}else{
		return 0;
	}
}

signed main(){
	make();

	int n;
	cin >> n >> x;
	cout << dfs(0, n) << endl;
}
