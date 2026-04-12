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
			if(size == 1){
				if(abs(ls.front() - a[r]) < abs(ls.back() - a[r])){
					ls.emplace_back(a[r]);
				}else{
					ls.emplace_front(a[r]);
				}
				size--;
			}else{
				if(
						abs(ls.front() - a[r]) + abs(ls.back() - a[r - 1]) < 
						abs(ls.front() - a[r - 1]) + abs(ls.back() - a[r])){
					ls.emplace_back(a[r--]);
					ls.emplace_front(a[r--]);
				}else{
					ls.emplace_front(a[r--]);
					ls.emplace_back(a[r--]);
				}
				size-=2;
			}
		}else{
			if(size == 1){
				if(abs(ls.front() - a[l]) < abs(ls.back() - a[l])){
					ls.emplace_back(a[l]);
				}else{
					ls.emplace_front(a[l]);
				}
				size--;
			}else{
				if(
						abs(ls.front() - a[l]) + abs(ls.back() - a[l + 1]) < 
						abs(ls.front() - a[l + 1]) + abs(ls.back() - a[l])){
					ls.emplace_back(a[l++]);
					ls.emplace_front(a[l++]);
				}else{
					ls.emplace_front(a[l++]);
					ls.emplace_back(a[l++]);
				}
				size-=2;
			}
		}
		i++;
	}

	vector<int> v(all(ls));

	long long sum = 0;
	//cout << v << endl;
	rep(i,v.size() - 1){
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
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
			if(size == 1){
				if(abs(ls.front() - a[r]) < abs(ls.back() - a[r])){
					ls.emplace_back(a[r]);
				}else{
					ls.emplace_front(a[r]);
				}
				size--;
			}else{
				if(
						abs(ls.front() - a[r]) + abs(ls.back() - a[r - 1]) < 
						abs(ls.front() - a[r - 1]) + abs(ls.back() - a[r])){
					ls.emplace_back(a[r--]);
					ls.emplace_front(a[r--]);
				}else{
					ls.emplace_front(a[r--]);
					ls.emplace_back(a[r--]);
				}
				size-=2;
			}
		}else{
			if(size == 1){
				if(abs(ls.front() - a[l]) < abs(ls.back() - a[l])){
					ls.emplace_back(a[l]);
				}else{
					ls.emplace_front(a[l]);
				}
				size--;
			}else{
				if(
						abs(ls.front() - a[l]) + abs(ls.back() - a[l + 1]) < 
						abs(ls.front() - a[l + 1]) + abs(ls.back() - a[l])){
					ls.emplace_back(a[l++]);
					ls.emplace_front(a[l++]);
				}else{
					ls.emplace_front(a[l++]);
					ls.emplace_back(a[l++]);
				}
				size-=2;
			}
		}
		i++;
	}

	vector<int> v(all(ls));

	long long sum = 0;
	//cout << v << endl;
	rep(i,v.size() - 1){
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
}
int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	sort(all(a));

	cout << max(solve1(a), solve2(a)) << endl;
}
