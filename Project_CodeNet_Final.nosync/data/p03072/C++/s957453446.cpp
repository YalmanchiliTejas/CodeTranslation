#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include <set>
#include <cassert>
#include<cmath>
#include<climits>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
const long long INF = 1LL << 60;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

class UnionFind {
	vector<int> data;
public:
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int find(vector<long long> &arr, long long obj) {
	if (arr[arr.size() - 1] < obj)return arr.size()-1;
	if (arr[0] > obj)return -1;

	int min = 0; int max = arr.size() - 1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[min+(max-min) / 2] > obj) {
			max = min + (max - min) / 2;
		}
		else {
			min = min + (max - min) / 2;
		}
		if (max - min == 1) {
			return min;
		}
	}


}

//約数求める //約数
void divisor(ll n,vector<ll> &ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	
}
//階乗
long long factorial(long long n, long long mod) {
	long long ret = 1;
	for (long long i = 1; i <= n; i++) {
		ret = (ret * i) % mod;
	}
	return ret;
}
//モジュラ逆数
long long inv_mod(long long n, long long mod) {
	long long a = n % mod, b = mod - 2, ret = 1;
	while (b > 0) {
		if (b & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

long long nPr(long long n, long long r, long long mod) {
	long long ret = 1;
	for (long long i = n; i >= n - r + 1; i--) {
		ret = ret * (i % mod) % mod;
	}
	return ret;
}

long long nCr(long long n, long long r, long long mod) {
	return nPr(n, r, mod) * inv_mod(factorial(r, mod), mod) % mod;
}

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {//降順second
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

bool compare_by_a(pair<ll, ll> a, pair<ll, ll> b) {//降順first
	if (a.first != b.first) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}
}

ll gcd(ll m, ll n){
	if (n == 0)return m;
	return gcd(n, m%n);
}//gcd


int main() {
	ll n;
	cin >> n;
	vector<ll> h(n);
	rep(i, n)cin >> h[i];
	ll max = 0;
	ll cnt = 0;
	rep(i, n) {
		if (max <= h[i]) {
			max = h[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
