#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <utility>

using namespace std;

#define ll long long

#define in(x) cin >> x
#define out(x) cout << x << endl

#define PI acos(-1)
#define pp push_back

#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl

#define vec2(type) vector<vector<type>>
#define vec3(type) vector<vector<vector<type>>>

#define For(i, n) for(int i = 0; i < n; i++)

bool inRange(ll a, ll x, ll b){
	if(a > b){
		swap(a, b);
	}
	return (a <= x && x <= b);
}

bool between(ll a, ll x, ll b){
	if(a > b){
		swap(a, b);
	}
	return (a < x && x < b);
}

template<typename T> void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> void input(T *data, int n) {
	For(i, n) {
		cin >> data[i];
	}
}

template<typename T> void input(vector<T> &vec, int n) {
	T temp;
	For(i, n) {
		cin >> temp;
		vec.push_back(temp);
	}
}

template<typename T> void sort(vector<T> &ary) {
	sort(ary.begin(), ary.end());
}

template<typename T> void rsort(vector<T> &ary) {
	sort(ary.rbegin(), ary.rend());
}

void rstring(string &str) {
	string temp = str;

	For(i, (int)str.size()) {
		str[i] = temp[(str.size() - 1) - i];
	}
}

struct Vec {
	int x, y;
	Vec():
		x(0), y(0) {}
	Vec(int _x, int _y):
		x(_x), y(_y) {}
};

template<typename T> void print(T *x, int n) {
	For(i, n) {
		cout << x[i] << " ";
	}
	cout << endl;
}

template<typename T> void print(vector<T> &x) {
	For(i, (int)x.size()) {
		cout << x[i] << " ";
	}
	cout << endl;
}

template<typename T>
T gcd(T n, T m) {
	if (n % m == 0) {
		return m;
	} else {
		return gcd<T>(m, n % m);
	}
}

template<typename T> T binarySearch(vector<T> &a, T target) {
	int cur = (int)a.size() / 2;
	int upper = (int)a.size() - 1;
	int buttom = 0;
	while (1) {
		if (a[cur] == target) {
			return a[cur];
		} else if (a[cur] > target) {
			upper = cur;
			cur = (buttom + cur) / 2;
		} else {
			buttom = cur;
			cur = (cur + upper) / 2;
		}
	}
}

template<typename T> T binarySearch(vector<T> &a, T func(T), T target) {
	int cur = (int)a.size() / 2;
	int upper = (int)a.size() - 1;
	int buttom = 0;
	while (1) {
		int value = func(a[cur]);
		if (value == target) {
			return a[cur];
		} else if (value > target) {
			upper = cur;
			cur = (buttom + cur) / 2;
		} else {
			buttom = cur;
			cur = (cur + upper) / 2;
		}
	}
}

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
	UnionFind() {}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}

	int size() {
		int count = 0;
		for (int i = 0; i < (int)par.size(); i++) {
			if (par[i] == i) {
				count++;
			}
		}
		return count;
	}
};

template<typename T, typename S>
struct _CountMap {
	T data;

	void add(S key, int n) {
		auto itr = data.find(key);
		if (itr == data.end()) {
			data.insert(pair<S, int>(key, n));
		} else {
			itr->second += n;
		}
	}

	auto top() {
		return data.begin();
	}

	int val(S key) {
		return data[key];
	}

	int size() {
		return data.size();
	}

	int sub(S key, int n) {
		auto elm = data.find(key);
		int ret = min(elm->second, n);
		if (ret == elm->second) {
			data.erase(elm);
		}
		elm->second -= ret;
		return ret;
	}

	int& operator [](S key) {
		auto itr = data.find(key);
		if (itr == data.end()) {
			data.insert(pair<S, int>(key, 0));
		}
		return itr->second;
	}
};

struct Area{
	vector<ll> data;
	
	Area(ll range):data(range + 1){}

	void add(pair<ll, ll> newdata){
		data[newdata.first]++;
		data[newdata.second]--;
	}

	ll num(){
		ll sum = 0;
		ll ret = 0;
		For(i, (int)data.size()){
			sum += data[i];
			if(sum != 0){
				ret++;
				for(i++; i < (int)data.size() && (sum += data[i]) != 0; i++);
			}
		}
		return ret;
	}
};

template<typename T>
using CountMap = _CountMap<map<T, int>, T>;

template<typename T>
using CountMapr = _CountMap<multimap<T, int, greater<T>>, T>;

template<typename T, typename S>
using rmap = multimap<T, S, greater<T>>;

template<typename T>
using rset = multiset<T, greater<T>>;

bool func(char col1, char col2, int index, int max){
	if(index == 0 && (col1 != 'R' || col2 == 'B'))return false;
	if(index == max - 2 && (col1 == 'R' || col2 != 'B'))return false; 

	if(col1 == 'R'){
		if(col2 != 'B'){
			return true;
		}
		return false;
	}
	if(col1 == 'G'){
		if(col2 == 'G'){
			return false;
		}
	}
	return true;
}

int main() {
 
	ll n, m, k, a, b, c, x, y, z, h, w;
	string s;
 
	cin >> n >> s >> k;
 
	For(i, n){
		if(s[i] != s[k - 1])s[i] = '*';
	}
 
	out(s);
 
	return 0;
 
}