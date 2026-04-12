//#include <windows.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define int ll
typedef vector<vector<pair<int, int> > > vvp;
typedef vector<pair<int, int> > vp;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<ll> > vvl;
typedef vector<ll> vl;
typedef vector<vector<double> > vvd;
typedef vector<double> vd;
typedef vector<vector<bool> > vvb;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
//#define unix ((unsigned int)time(NULL))
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define loop while(true)
#define inputv(v) for(int i = 0; i < (v.size()); i++)cin>>v[i];
#define inputvv(v) for(int i = 0; i < (v.size()); i++)for(int j=0;j<(v[0].size());j++)cin>>v[i][j];
#define all(x) (x).begin(), (x).end()
#define yn(f) cout <<(f?"yes":"no")<< endl
#define YN(f) cout <<(f?"YES":"NO")<< endl
#define Yn(f) cout <<(f?"Yes":"No")<< endl
#define POSSIBLE(f) cout << ((f) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(f) cout << ((f) ? "Possible" : "Impossible"  ) << endl
const int inf8 = 1e8;
const int inf = 1e9+7;
const ll inf18 = 1e18;
void puts() {
	cout << endl;
}
template <class T>
void puts(T a) {
	cout << (a) << endl;
}
template <class Head, class... Tail>
void puts(Head&& head, Tail&& ... tail) {
	cout << head;
	if (sizeof...(tail) == 0) {
		puts();
	}
	else {
		cout << " ";
		puts(forward<Tail>(tail)...);
	}

}
void puts(pair<int, int> A) {
	cout << "(" << A.first << "," << A.second << ")" << endl;;
}
void puts(vector<pair<int, int> >& A) {
	for (int i = 0; i < A.size(); i++)
	{
		cout << "(" << A[i].first << "," << A[i].second << ")";
		if (A.size() - 1 == i) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}
void puts(vector<vector<pair<int, int> > >& A) {
	for (int i = 0; i < A.size(); i++)
	{
		puts(A[i]);
	}
}
template <class T>
void puts(vector<T>& A) {
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i];
		if (A.size() - 1 == i) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}
template <class T>
void puts(const vector<T>& A) {
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i];
		if (A.size() - 1 == i) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}
template<class T>
void puts(vector<vector<T> >& A) {
	for (int i = 0; i < A.size(); i++)
	{
		puts(A[i]);
	}
}
template<class T>
void puts(const vector<vector<T> >& A) {
	for (int i = 0; i < A.size(); i++)
	{
		puts(A[i]);
	}
}
template <class T>
vector<T> ruisekiwa(vector<T>& A) {
	vector<T> R(A.size()+1);
	for (int i = 0; i < A.size(); i++)
	{
		R[i + 1] = R[i] + A[i];
	}
	return R;
}
class disjoint_set {
public:
	vi p, rank;
	disjoint_set(int size) {
		p.resize(size, 0);
		rank.resize(size, 0);
		for (int i = 0; i < size; i++)makeSet(i);
	}
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y) {
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] < rank[y]) {
			p[x] = y;
		}
		else {
			p[y] = x;
			if (rank[x] == rank[y]) {
				rank[x]++;
			}
		}
	}
	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);
		}
		return p[x];
	}
};
class rmq {
public:
	int n, inf_, max_n;
	vi A;
	rmq(int n_) {
		n = 1;
		inf_ = INT_MAX;
		max_n = (1 << 18);
		while (n < n_)n *= 2;
		A.resize(max_n * 2 - 1);
		for (int i = 0; i < n * 2 - 1; i++)A[i] = inf_;
	}
	void update(int i, int x) {
		i += n - 1;
		A[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			A[i] = min(A[i * 2 + 1], A[i * 2 + 2]);
		}
	}
	int query(int left, int right, int i = 0, int left2 = 0, int right2 = -1) {
		if (right2 == -1)right2 = n;
		if (right2 <= left || right <= left2) {
			return inf_;
		}
		if (left <= left2 && right2 <= right) {
			return A[i];
		}
		else {
			int mid = (left2 + right2) / 2;
			return min(query(left, right, i * 2 + 1, left2, mid), query(left, right, i * 2 + 2, mid, right2));
		}
	}
};
class rsq {//遅延セグ木
public:
	int n, max_n;
	vl A, Lazy;
	rsq(int n_) {
		n = 1;
		max_n = (1 << 18);
		while (n < n_)n *= 2;
		A.resize(max_n * 2 - 1);
		Lazy.resize(max_n * 2 - 1);
	}
	void propagate(int i, int left, int right) {
		if (Lazy[i] != 0) {
			A[i] += Lazy[i];
			if (right - left > 1) {
				Lazy[i * 2 + 1] += Lazy[i] / 2;
				Lazy[i * 2 + 2] += Lazy[i] / 2;
			}
			Lazy[i] = 0;
		}
	}
	void add(int left, int right, int x, int i = 0, int left2 = 0, int right2 = -1) {
		if (right2 == -1)right2 = n;
		propagate(i, left2, right2);
		if (right <= left2 || right2 <= left) return;

		if (left <= left2 && right2 <= right) {
			Lazy[i] += (right2 - left2) * x;
			propagate(i, left2, right2);

		}
		else {
			int mid = (left2 + right2) / 2;
			add(left, right, x, i * 2 + 1, left2, mid);
			add(left, right, x, i * 2 + 2, mid, right2);
			A[i] = A[i * 2 + 1] + A[i * 2 + 2];
		}

	}
	ll sum(int left, int right, int i = 0, int left2 = 0, int right2 = -1) {
		if (right2 == -1)right2 = n;
		if (right2 <= left || right <= left2) return 0;
		propagate(i, left2, right2);
		if (left <= left2 && right2 <= right) {
			return A[i];
		}
		else {
			int mid = (left2 + right2) / 2;
			ll res = 0;
			res += sum(left, right, i * 2 + 1, left2, mid);
			res += sum(left, right, i * 2 + 2, mid, right2);
			return res;
		}
	}
};
class binary_indexed_tree {//1-indexed
public:
	int n;
	vl A;
	binary_indexed_tree(int n_) {
		n = n_;
		A.resize(n + 1);//1-indexed
	}
	ll sum(int i) {//[0,i]の和を返す
		ll res = 0;
		while (i > 0) {
			res += A[i];
			i -= i & -i;
		}
		return res;
	}
	void add(int i, int x) {
		while (0 < i && i <= n) {
			A[i] += x;
			i += i & -i;
		}
	}
};
void dedupe(vi& A) {
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
}
int gcd(int a, int b) {//log N
	return (b == 0) ? a : gcd(b, a % b);
}
ll gcd(ll a, ll b) {//log N
	return (b == 0) ? a : gcd(b, a % b);
}
int lcm(int a, int b) {//log N
	return (a * b) / gcd(a, b);
}
ll lcm(ll a, ll b) {//log N
	return (a * b) / gcd(a, b);
}
int extgcd(int a, int b, int& x, int& y) {// log N
	int d = a;
	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return d;
}
vi get_primes(int limit) {//N log N
	vb A(limit + 1, true);
	for (int i = 2; i < A.size(); i++) {
		if (!A[i])continue;
		for (int j = i * 2; j < A.size(); j += i)A[j] = false;
	}
	vi B;
	for (int i = 2; i < A.size(); i++)
	{
		if (A[i])B.push_back(i);
	}
	return B;
}
template <class T>
bool is_prime(T num) {// sqrt(N)
	if (num < 2)return false;
	for (ll i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
ll merge_count(vi & A) {//N log N
	const int inf = 1000000007;
	int n = A.size();
	if (n <= 1)return 0;
	long long count = 0;
	int mid = n / 2;
	vector<int> B(A.begin(), A.begin() + mid);
	vector<int> C(A.begin() + mid, A.end());
	count += merge_count(B);
	count += merge_count(C);
	B.push_back(inf);
	C.push_back(inf);
	int B_i = 0;
	int C_i = 0;
	for (int i = 0; i < n; i++) {
		if (B[B_i] <= C[C_i]) {
			A[i] = B[B_i++];
		}
		else {
			count += (n / 2) - B_i;
			A[i] = C[C_i++];
		}
	}
	return count;
}
ll perm(int n) {
	ll ret = 1;
	for (int i = 2; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}
ll comb(int left, int right) {
	ll N = 1;
	ll D = perm(right);
	for (int i = left; i>left-right; i--)
	{
		N *= i;
	}
	
	return N / D;
}
vi bit(int num, int size) {
	vi A;
	for (int j = 0; j < size; j++)
	{
		if ((num & (1 << (size - j - 1))) > 0) {
			A.push_back(1);
		}
		else {
			A.push_back(0);
		}
	}
	return A;
}
vvi bit_z(int size) {//2**N
	vvi A;
	for (int i = 0; i < (1 << size); i++)
	{
		vi temp = bit(i, size);
		A.push_back(temp);
	}
	return A;
}
vvi bit_z(int size, int n) {
	vvi A;
	int s = (1 << n) - 1;
	A.push_back(bit(s, size));
	while (true) {
		int x = s & (-s);
		int y = s + x;
		int z = s & (~y);

		z /= x;
		z = z >> 1;
		s = (y | z);
		if (s >= (1 << size))break;
		A.push_back(bit(s, size));
	}
	return A;
}
vvi bit_z(int size, int min, int max) {
	vvi A;
	for (int i = min; i <= max; i++)
	{
		vvi B = bit_z(size, i);
		A.insert(A.end(), B.begin(), B.end());
	}
	return A;
}
int random(int min, int max) {
	int r = rand() % (max + 1 - min) + min;
	return r;
}
vector< pair < ll, int > > factorize(ll n) {
	ll count = 0;
	vector< pair< ll, int > > res;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i)continue;
		res.push_back(make_pair(i, 0));
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.push_back(make_pair(n, 1));
	return res;
}
vl dijkstra_am(int start,vvl& G) {//隣接行列
	int n = G.size();
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll>>  > Q;
	vl cost(n,inf18);
	cost[start] = 0;
	Q.push(make_pair(cost[start],start));
	while (!Q.empty()) {
		ll min_ = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (cost[v] <min_)continue;
		for (int i = 0; i < n; i++)
		{
			if (min_ + G[v][i] < cost[i]) {
				cost[i] = min_ + G[v][i];
				Q.push(make_pair(min(inf18, min_ + G[v][i]), i));
			}
		}
	}
	return cost;
}
vl dijkstra_al(int start, vector<vector<pair<ll, ll> > >& G) {//隣接リスト
	int n = G.size();
	priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, greater<pair<ll, ll>>  > Q;
	vl cost(n, inf18);
	cost[start] = 0;
	Q.push(make_pair(cost[start], start));
	while (!Q.empty()) {
		ll min_ = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (cost[v] < min_)continue;
		for (int i = 0; i < G[v].size(); i++)
		{
			int u = G[v][i].first;
			if (min_ + G[v][i].second < cost[u]) {
				cost[u] = min_ + G[v][i].second;
				Q.push(make_pair(min(inf18, min_ + G[v][i].second), u));
			}
		}
	}
	return cost;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
	ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	ll min_ab = min(a+b,c*2);
	ll min_a = min(a, c*2);
	ll min_b = min(b,c*2);
	ll min_ = min(x,y);
	ll d = abs(x - y);
	if (x > y) puts(min_ab*min_+d*min_a);
	else puts(min_ab * min_ + d * min_b);

}

signed main() {
	solve();
}