#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include<functional>
#include<queue>
#include<regex>
#include<time.h>
#include<type_traits>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll INF = 1050000000;
constexpr ll LONGINF = 1050000000000000000;

struct all_init { all_init() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(15); }; }ALL_INIT;
struct edge { ll from, to, cost; bool operator < (const edge& x) const { return cost < x.cost; } };

#define CIN(vector_array_etc,n) for(int loop=0;loop<n;loop++){cin>>vector_array_etc[loop];};
#define COUT(vector_array_etc,n) for(int LOOP=0;LOOP<n;LOOP++){cout<<vector_array_etc[LOOP]<<(LOOP == n-1 ?'\n':' ');};
#define VC(Type_name) vector<Type_name>//1次元ならあまり意味ないかも
#define VCVC(Type_name) vector<vector<Type_name>>//2次元配列定義怠過ぎ問題
#define SORT(vector_etc) sort(vector_etc.begin(),vector_etc.end());

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }//aに最大値が入る
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }//aに最小値が入る
template<class T>void swap(T &a, const T &b) { T tmp = a; a = b; b = a; return; }//aとbを入れ替える

template<typename T>
istream& operator >> (istream& is, vector<T>& Vec) { for (T& x : Vec) { is >> x; }return is; }

template<typename V, typename H>
void resize(vector<V>& vec, const H head) { vec.resize(head); }

template<typename V, typename H, typename ... T>
void resize(vector<V>& vec, const H& head, const T ... tail) { vec.resize(head); for (auto& v : vec) { resize(v, tail...); } }

int dx[] = { 0,1,-1, 0,1,-1, 1,-1 };    //i<4:4way i<8:8way
int dy[] = { 1,0, 0,-1,1,-1,-1, 1 };

class UnionFind {
private:
	std::vector<int> parent;
	std::vector<int> height;
	std::vector<int> m_size;

public:
	UnionFind(int size_) : parent(size_), height(size_, 0), m_size(size_, 1) {
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	void init(int size_) {
		parent.resize(size_);
		height.resize(size_, 0);
		m_size.resize(size_, 1);
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		int t = size(x) + size(y);
		m_size[x] = m_size[y] = t;
		if (height[x] < height[y]) parent[x] = y;
		else parent[y] = x;
		if (height[x] == height[y]) ++height[x];
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		if (parent[x] == x) return m_size[x];
		return size(parent[x] = find(parent[x]));
	}
};

//#define INF 1050000000
#define index_of(as, x) distance(as.begin(), upper_bound(as.begin(), as.end(), x))

vector<int> lis_fast(const vector<int>& a) {
	const int n = a.size();
	vector<int> A(n, INF);
	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = index_of(A, a[i]);
		A[id[i]] = a[i];
	}
	int m = *max_element(id.begin(), id.end());
	vector<int> b(m + 1);
	for (int i = n - 1; i >= 0; --i)
		if (id[i] == m) b[m--] = a[i];
	//cout << lower_bound(b.begin(),b.end(), INF) - b.begin() << endl;
	return b;
}

int main() {
	int n; cin >> n;
	VC(int) v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] *= -1;
	}

	cout << lis_fast(v).size() << endl;


	return 0;
}