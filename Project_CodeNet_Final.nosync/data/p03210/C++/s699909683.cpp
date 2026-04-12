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

#define MOD 1000000007
#define PI acos(-1)
#define pb push_back

#define endl '\n'

#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl

#define pllll pair<ll, ll>
#define plls pair<ll, string>
#define psll pair<string, ll>

#define For(i, n) for(int i = 0; i < n; i++)

#define phoge print("hoge")
#define phugo print("hugo")

#define vll vector<ll>
#define v2ll vec2<ll>
#define v3ll vec3<ll>

#define threeo(terms, iftrue, iffalse) ((terms) ? (iftrue) : (iffalse))

template<typename T>
using vec = vector<T>;

template<typename T>
using vec2 = vector<vector<T>>;

template<typename T>
using vec3 = vector<vector<vector<ll>>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename S>
using umap = unordered_map<T, S>;

bool inRange(ll a, ll x, ll b) {
	if (a > b) {
		swap(a, b);
	}
	return (a <= x && x <= b);
}

bool between(ll a, ll x, ll b) {
	if (a > b) {
		swap(a, b);
	}
	return (a < x && x < b);
}

template<typename T> void sort(T &a, T &b) {
	if(a > b){
		swap(a, b);
	}
}

template<typename T> 
void input(T *data, int n) {
	For(i, n) {
		cin >> data[i];
	}
}

template<typename T, typename S>
void input(T *data1, S *data2, int n){
	For(i, n){
		cin >> data1[i] >> data2[i];
	}
}

template<typename T> 
void input(vector<T> &vec, int n) {
	T temp;
	For(i, n) {
		cin >> temp;
		vec.push_back(temp);
	}
}

template<typename T, typename S> 
void input(vector<T> &vec1, vector<S> &vec2, int n){
	T temp1;
	S temp2;
	For(i, n){
		cin >> temp1 >> temp2;
		vec1.push_back(temp1);
		vec2.push_back(temp2);
	}
}

template<typename T> 
void sort(vector<T> &ary) {
	sort(ary.begin(), ary.end());
}

template<typename T> 
void rsort(vector<T> &ary) {
	sort(ary.rbegin(), ary.rend());
}

void rstring(string &str) {
	string temp = str;

	For(i, (int)str.size()) {
		str[i] = temp[(str.size() - 1) - i];
	}
}

template<typename T>
T print(T x){
	cout << x << endl;
	return x;
}

template<typename T> 
void print(T *x, int n) {
	For(i, n) {
		cout << x[i] << " ";
	}
	cout << endl;
}

template<typename T> 
void print(vector<T> &x) {
	for(auto t : x){
		cout << t << " ";
	}
	cout << endl;
}

template<typename T, typename S> 
void print(pair<T, S> &p){
	out2(p.first, p.second);
}

template<typename T>
T gcd(T n, T m) {
	if (n % m == 0) {
		return m;
	} else {
		return gcd<T>(m, n % m);
	}
}

void lsum(vll &a, vll &sum){
	sum[0] = a[0];
	for (int i = 1; i < (int)a.size() ; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
}

void rsum(vll &a, vll &sum){
	sum[(int)a.size() - 1] = a[(int)a.size() - 1];
	for (int i = (int)a.size() - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + a[i];	
	}
}

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector<int> numc;

	UnionFind(int N) : par(N), numc(N, 1) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
	UnionFind() {}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	bool unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
		numc[ry] = numc[rx] + numc[ry];
		return true;
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

template<class Abel> struct PotentialUnionFind {
	vector<int> par;
	vector<int> rank;
	vector<Abel> diff_weight;
 
	PotentialUnionFind(int n = 1, Abel SUM_UNITY = 0) {
		init(n, SUM_UNITY);
	}
 
	void init(int n = 1, Abel SUM_UNITY = 0) {
		par.resize(n); rank.resize(n); diff_weight.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
	}
 
	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			int r = root(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = r;
		}
	}
 
	Abel weight(int x) {
		root(x);
		return diff_weight[x];
	}
 
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
 
	bool merge(int x, int y, Abel w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = -w;
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}
 
	Abel diff(int x, int y) {
		return weight(y) - weight(x);
	}
};


template<typename T, typename S>
struct _CountMap {
	T data;

	void add(S key, int n) {
		auto itr = data.find(key);
		if (itr == data.end()) {
			data.insert(pair<S, ll>(key, n));
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

	int sub(S key, ll n) {
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

struct Area {
	vector<ll> data;

	Area(ll range): data(range + 1) {}

	void add(pair<ll, ll> newdata) {
		data[newdata.first]++;
		data[newdata.second]--;
	}

	ll num() {
		ll sum = 0;
		ll ret = 0;
		For(i, (int)data.size()) {
			sum += data[i];
			if (sum != 0) {
				ret++;
				for (i++; i < (int)data.size() && (sum += data[i]) != 0; i++);
			}
		}
		return ret;
	}
};

struct Interval{
	vector<pllll> data;

	void add(ll s, ll f){
		data.push_back(pllll(f, s));
	}

	ll num(){
		sort(data);

		ll ret = 0;
		ll lastf = -1;
		for(auto t : data){
			if(t.first == lastf){
				continue;
			}
			if(t.second >= lastf){
				lastf = t.first;
				ret++;
			}
		}

		return ret;
	}
};

template<typename T>
using CountMap = _CountMap<map<T, ll>, T>;

template<typename T>
using CountMapr = _CountMap<multimap<T, ll, greater<T>>, T>;

ll factoring(ll n, CountMap<ll> &p){
	ll sum = 0;
	for(ll i = 2; n != 1; i++){
		while(n % i == 0){
			p.add(i, 1);
			sum++;
			n /= i;
		}
	}
	return sum;
}

template<typename T, typename S>
using rmap = multimap<T, S, greater<T>>;

template<typename T>
using rset = multiset<T, greater<T>>;

vector<ll> fac(1000001); //n!(mod M)
vector<ll> ifac(1000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分


ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % 1000000007;
        x = x*x % 1000000007;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % 1000000007;
    return tmp * fac[a] % 1000000007;
}

ll syakutori(vll &data, ll key){
	ll ans = 0;
	ll sum = 0;
	ll cur = 0;
	For(i, data.size()){

		while(sum <= key){
			if(cur == data.size()){
				break;
			}
			else{
				sum += data[cur];
				cur++;
			}
		}

		ans += cur - i - 1 + ((sum <= key) ? 1 : 0);
		sum -= data[i];

	}

	return ans;
}

ll syakutori(vll &data){
	ll ans = 0;
	ll cur = 1;

	ll sum = data[0];
	ll sumox = data[0];
	For(i, data.size()){

		while(sum == sumox){
			if(cur == data.size()){
				break;
			}
			else{
				sum += data[cur];
				sumox ^= data[cur];
				cur++;
			}
		}

		ans += cur - i - 1 + ((sum == sumox) ? 1 : 0);
		sum -= data[i];
		sumox ^= data[i];

	}

	return ans;
}

int main() {

	ll n, m, k, a, b, c, x, y, z, h, w, sum = 0;
	string s;

		cin >> x;
	if(x == 7 || x == 5 || x == 3) YES;
	else NO;
	return 0;

}