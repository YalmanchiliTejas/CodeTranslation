#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
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

long long diffSum(list<int>& ls){
	vector<int> v(all(ls));
	long long sum = 0;
	rep(i,v.size() - 1){
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
}

long long solve1(vector<int>& a){
	int size = a.size();
	int l = 0, r = a.size() - 1;

	list<int> ls;
	int i = 0;
	while(size){
		if(i == 0){
			ls.emplace_back(a[l++]);
			size--;
		}else if(i % 2){
			ls.emplace_front(a[r--]);
			size--;
			if(size == 0) continue;
			ls.emplace_back(a[r--]);
			size--;
		}else{
			ls.emplace_front(a[l++]);
			size--;
			if(size == 0) continue;
			ls.emplace_back(a[l++]);
			size--;
		}
		i++;
	}

	return diffSum(ls);
}

long long solve2(vector<int>& a){
	int size = a.size();
	int l = 0, r = a.size() - 1;

	list<int> ls;
	int i = 0;
	while(size){
		if(i == 0){
			ls.emplace_back(a[r--]);
			size--;
		}else if(i % 2 == 0){
			ls.emplace_front(a[r--]);
			size--;
			if(size == 0) continue;
			ls.emplace_back(a[r--]);
			size--;
		}else{
			ls.emplace_front(a[l++]);
			size--;
			if(size == 0) continue;
			ls.emplace_back(a[l++]);
			size--;
		}
		i++;
	}

	return diffSum(ls);
}


int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	sort(all(a));

	cout << max(solve1(a), solve2(a)) << endl;
}
