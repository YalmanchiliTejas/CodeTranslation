#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <limits>
#include <iomanip>
#include <ctype.h>
#include <unordered_map>
#include <random>
#include <bitset>

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <complex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, double> pld;
typedef pair<double, double> pdd;
typedef pair<double, ll> pdl;
typedef pair<int, char> pic;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef priority_queue<ll, vector<ll>, greater<ll>> llgreaterq;
typedef priority_queue<pll, vector<pll>, greater<pll>> pllgreaterq;
typedef priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> plpllgreaterq;
typedef priority_queue<vi, vector<vi>, greater<vi>> vigreaterq;
typedef priority_queue<vl, vector<vl>, greater<vl >> vlgreaterq;
#define bit(x,v) ((ll)x << v)
#define rep(x,v) for(ll x=0;x<v;x++)
#define rep2(x,f,v) for(ll x=f;x<v;x++)
// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (std::abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define all(a) a.begin(),a.end()
#define all0(a) memset(a,0,sizeof(a))
const ll INF = 1000000007;
const int MAX = 2000010;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[200010];
int lank[200010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

int same(int x, int y) {
	return parent(x) == parent(y);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (lank[px] < lank[py]) {
		pr[py] = px;
		lank[px] += lank[py] + 1;
	}
	else {
		pr[px] = py;
		lank[py] += lank[px] + 1;
	}
	return true;
}

ll bit[200010];
int max_n = 200000;
int pm = 0;
void add(int x) {

	while (max_n >= x)
	{
		bit[x]++;
		x += x & -x;
	}
}
void sub(int x) {
	while (max_n >= x)
	{
		bit[x]--;
		x += x & -x;
	}
}
ll merge(ll* a, int left, int mid, int right) {
	ll n1 = mid - left;
	ll n2 = right - mid;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	for (size_t i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = a[mid + i];
	}

	L[n1] = INF;
	R[n2] = INF;
	ll i = 0;
	ll j = 0;
	ll r = 0;
	for (size_t k = left; k < right; k++)
	{
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			r += n1 - i;
			j++;
		}
	}
	return r;
}
ll merge2(pair<int, char>* a, int left, int mid, int right) {
	ll n1 = mid - left;
	ll n2 = right - mid;
	vector<pair<int, char>> L(n1 + 1);
	vector<pair<int, char>> R(n2 + 1);
	for (size_t i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = a[mid + i];
	}

	L[n1] = make_pair(INF, ' ');
	R[n2] = make_pair(INF, ' ');
	ll i = 0;
	ll j = 0;
	ll r = 0;
	for (size_t k = left; k < right; k++)
	{
		if (L[i].first <= R[j].first) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			r += n1 - i;
			j++;
		}
	}
	return r;
}
ll mergeSort2(pair<int, char>* a, int left, int right) {
	ll res = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		res = mergeSort2(a, left, mid);
		res += mergeSort2(a, mid, right);
		res += merge2(a, left, mid, right);
	}
	return res;
}
ll mergeSort(ll* a, int left, int right) {
	ll res = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		res = mergeSort(a, left, mid);
		res += mergeSort(a, mid, right);
		res += merge(a, left, mid, right);
	}
	return res;
}
int partition(pair<int, char>* a, int p, int r) {
	pair<int, char> x = a[r];
	int i = p - 1;
	for (size_t j = p; j < r; j++)
	{
		if (a[j].first <= x.first) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void quick(pair<int, char>* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quick(a, p, q - 1);
		quick(a, q + 1, r);
	}
}

ll n;
int ci = 0;
ll P[1000010];
struct Node {
	int key;
	int priority;
	Node* parent, * left, * right;
	Node(int key, int priority);
	Node() {}
};
Node NIL;
Node::Node(int key, int priority) : key(key), priority(priority) {
	left = &NIL;
	right = &NIL;
}
Node* root = new Node();
void cenrec(Node* k) {
	if (k->key == NIL.key) return;
	cenrec(k->left);
	cout << " " << k->key;
	cenrec(k->right);
}
void fastrec(Node* k)
{
	if (k->key == NIL.key) return;
	cout << " " << k->key;
	fastrec(k->left);
	fastrec(k->right);
}
void insert(Node* v) {
	Node* y = &NIL;
	Node* x = root;
	while (x->key != NIL.key)
	{
		y = x;
		if (v->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	v->parent = y;
	if (y->key == NIL.key) {
		root = v;
	}
	else if (v->key < y->key) {
		y->left = v;
	}
	else {
		y->right = v;
	}

}

Node* find(Node* k, ll v)
{
	if (k->key == NIL.key) return &NIL;
	if (k->key == v) return k;
	if (v < k->key) return find(k->left, v);
	return find(k->right, v);
}
void delp12(Node* x) {
	if (x->key == NIL.key)  return;
	Node* l = x->left;
	Node* r = x->right;
	Node* pr = x->parent;

	if (l->key == NIL.key
		&& r->key == NIL.key) {
		if (pr->left == x) {
			pr->left = &NIL;
		}
		else pr->right = &NIL;
	}
	else if (l->key != NIL.key) {
		if (pr->left == x) {
			pr->left = l;
		}
		else pr->right = l;
		l->parent = pr;
	}
	else if (r->key != NIL.key) {
		if (pr->left == x) {
			pr->left = r;
		}
		else pr->right = r;
		r->parent = pr;
	}
}
Node* get_next(Node* k) {
	if (k->key == NIL.key) return &NIL;
	Node* res = get_next(k->left);
	if (res->key != NIL.key) return res;
	return k;
}
void del(Node* x) {

	if (x->key == NIL.key) return;
	Node* l = x->left;
	Node* r = x->right;
	Node* pr = x->parent;

	if (l->key != NIL.key && r->key != NIL.key) {
		Node* nex = get_next(r);
		x->key = nex->key;
		delp12(nex);
	}
	else {
		delp12(x);
	}
}
Node* rightRotate(Node* t) {
	Node* s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}
Node* leftRotate(Node* t) {
	Node* s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}
Node* _insert(Node* t, int key, int priority) {
	if (t->key == NIL.key) {
		return new Node(key, priority);
	}
	if (key == t->key) {
		return t;
	}

	if (key < t->key) {
		t->left = _insert(t->left, key, priority);
		if (t->priority < t->left->priority) {
			t = rightRotate(t);
		}
	}
	else {
		t->right = _insert(t->right, key, priority);
		if (t->priority < t->right->priority) {
			t = leftRotate(t);
		}
	}
	return t;
}
Node* delete1(Node* t, int key);
Node* _delete(Node* t, int key) {
	if (t->left->key == NIL.key && t->right->key == NIL.key) {
		return &NIL;
	}
	else if (t->left->key == NIL.key) {
		t = leftRotate(t);
	}
	else if (t->right->key == NIL.key) {
		t = rightRotate(t);
	}
	else
	{
		if (t->left->priority > t->right->priority) {
			t = rightRotate(t);
		}
		else
			t = leftRotate(t);
	}
	return delete1(t, key);
}
Node* delete1(Node* t, int key) {
	if (t->key == NIL.key) {
		return &NIL;
	}
	if (key < t->key) {
		t->left = delete1(t->left, key);
	}
	else if (key > t->key) {
		t->right = delete1(t->right, key);
	}
	else return _delete(t, key);
	return t;
}
int H;
int left(int i) {
	return i * 2 + 1;
}
int right(int i) {
	return i * 2 + 2;
}


ll heap[2000010];
void maxHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l < H && heap[l] > heap[i])
		largest = l;
	else
		largest = i;
	if (r < H && heap[r] > heap[largest])
		largest = r;

	if (largest != i) {
		swap(heap[i], heap[largest]);
		maxHeapify(largest);
	}
}
int pare(int i) {
	return (i - 1) / 2;
}
void raise(int i) {
	int l = pare(i);
	if (l < 0) return;

	if (heap[l] < heap[i]) {
		swap(heap[i], heap[l]);
		raise(l);
	}
}
void minHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int minimam = 0;
	if (l < H && heap[l] < heap[i])
		minimam = l;
	else
		minimam = i;
	if (r < H && heap[r] < heap[minimam])
		minimam = r;

	if (minimam != i) {
		swap(heap[i], heap[minimam]);
		minHeapify(minimam);
	}
}
void buildMaxHeap() {
	for (int i = H / 2; i >= 0; i--)
	{
		maxHeapify(i);
	}
}

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
std::vector<int> find_all(const std::string str, const std::string subStr) {
	std::vector<int> result;

	int subStrSize = subStr.size();
	int pos = str.find(subStr);

	while (pos != std::string::npos) {
		result.push_back(pos);
		pos = str.find(subStr, pos + 1);
	}

	return result;
}
//ll memo[100010];
//ll next[100010];
//ll dm[100010];
//int f[100010];
//ll rec(int x) {
//
//	if (~memo[x]) return memo[x];
//	if (x == n) { 
//		dm[n] = 1;
//		return 1; 
//	}
//	ll *res = &memo[x];
//	*res = 0;
//	set<int> st;
//	st.insert(f[x]);
//	for (int i = x + 1; i <= n; i++)
//	{
//		if (~memo[i]) {
//			*res += memo[i] + 1;
//			*res %= INF;
//			break;
//		}
//
//		*res += rec(i);
//		*res %= INF;
//		if (st.find(f[i]) != st.end()) {break; }
//		st.insert(f[i]);
//	}
//
//	return *res;
//}
#define bit(x,v) ((ll)x << v)

class BIT {

	static const int MAX_N = 1000010;
public:
	BIT() { memset(bit, 0, sizeof(bit)); }
	int bit[MAX_N + 1], n;
	int sum(int i) {
		int s = 0;
		while (i > 0)
		{
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, int x) {
		while (i <= n)
		{
			bit[i] += x;
			i += i & -i;
		}
	}
	void clear() {
		memset(bit, 0, sizeof(bit));
	}
	int a[MAX_N];
	void bable_swap_count() {
		ll ans = 0;
		for (size_t j = 0; j < n; j++)
		{
			ans += j - sum(a[j]);
			add(a[j], 1);
		}
		printf("%lld\n", ans);
	}

	int search(int s, int x) {

		ll half = (s + x) / 2;
		ll sh = sum(x);

		ll sl = sum(half);

		ll st = sum(s);
		if (sh - sl == 0) {
			return x;
		}
		if (sh - sl < x - half) {
			return search(half, x);
		}

		if (sl - st == 0) {
			return half;
		}

		if (sl - st < half - s) {
			return search(s, half);
		}
		return -1;
	}

	int lankSearch(int lank) {
		return lankSearch(lank, 0, MAX_N);
	}
	int lankSearch(int lank, int s, int t) {

		ll half = (s + t) / 2;

		ll v = sum(half);
		ll v1 = sum(t);
		ll v2 = sum(s);
		if (lank == 1) {
			if (s + 1 >= t) return t;
			else if (v - v2 > 0) {
				return lankSearch(lank, s, half);
			}
			else return lankSearch(lank, half, t);
		}

		if ((v - v2) < lank) {
			return lankSearch(lank - (v - v2), half, t);
		}
		if ((v - v2) >= lank) {
			return lankSearch(lank, s, half);
		}

		return -1;
	}
};

class BIT2 {

	static const int MAX_N = 1000010;
public:
	BIT2() { memset(bit, 0, sizeof(bit)); }
	ll bit[MAX_N + 1], n;
	ll gmax(int i) {
		ll s = 0;
		while (i > 0)
		{
			s = max(bit[i], s);
			i -= i & -i;
		}
		return s;
	}

	void add(int i, ll x) {
		while (i <= n)
		{
			bit[i] = max(bit[i], x);
			i += i & -i;
		}
	}
	void clear() {
		memset(bit, 0, sizeof(bit));
	}

};
vector<ll> getp(ll n) {

	vector<ll> res;
	ll a = 2;
	if (n % 2 == 0) {
		res.push_back(2);
		while (n % 2 == 0)n /= 2;
	}

	for (ll i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0) {
			res.push_back(i);
			while (n % i == 0)n /= i;
		}
	}
	if (n != 1) res.push_back(n);
	return res;
}
vector<ll> getp2(ll n) {

	vector<ll> res;
	ll a = 2;
	if (n % 2 == 0) {

		while (n % 2 == 0) { n /= 2; res.push_back(2); }
	}

	for (ll i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0) {

			while (n % i == 0) { n /= i; res.push_back(i); }
		}
	}
	if (n != 1) res.push_back(n);
	return res;
}
vector<pll> getp3(ll n) {

	vector<pll> res;
	ll a = 2;
	int cnt = 0;
	if (n % 2 == 0) {
		res.push_back(make_pair(2, 0));
		while (n % 2 == 0) { n /= 2; res[cnt].second++; }
		cnt++;
	}

	for (ll i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0) {
			res.push_back(make_pair(i, 0));
			while (n % i == 0) { n /= i; res[cnt].second++; }
			cnt++;
		}
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}
vector<ll> getDivisors(ll n) {

	vector<ll> res;
	ll a = 2;
	res.push_back(1);
	for (ll i = 2; i * i <= n; i++)
	{

		if (n % i == 0) {
			res.push_back(i);
			if (n / i != i)
				res.push_back(n / i);
		}
	}
	return res;
}

struct ve {
public:
	vector<ve> child;
	int _t = INF;
	ve(int t) :_t(t) {}
	ve(ve _left, ve _right) {
		_t = _left._t + _right._t;
		child.push_back(_left);
		child.push_back(_right);
	}
	bool operator<(const ve& t) const {
		return _t > t._t;
	}
};

vector<bool> elas(ll n) {
	vector<bool> r(n);
	for (ll i = 3; i < n; i += 2)
	{
		r[i] = 1;
	}
	r[0] = 0;
	r[1] = 0;
	r[2] = 1;
	for (ll i = 3; i * i < n; i += 2)
	{
		if (!r[i]) continue;
		ll ti = i * 2;
		while (ti < n)
		{
			r[ti] = false;
			ti += i;
		}
	}
	return r;
}
bool isprime(ll v) {
	for (ll i = 2; i * i <= v; i++)
	{
		if (v % i == 0) return false;
	}
	return true;
}

ll lcm(vector<ll> v) {
	if (v.size() == 0) return 0;
	ll t = v[0];
	for (size_t i = 1; i < v.size(); i++)
	{
		t = v[i] * t / gcd(v[i], t);
	}
	return t;
}
ll eulerphi(ll n) {
	auto p = getp(n);
	double u = n;
	for (auto v : p) {
		u *= (double)(v - 1) / (double)v;
	}
	return u;
}

double revs(double x) {
	ll dig = 0;
	stringstream st;
	st << std::fixed << setprecision(0) << x;
	string v = st.str();
	reverse(v.begin(), v.end());
	return stod(v);
}
bool chkparindrome(double x) {
	stringstream st;
	st << std::fixed << setprecision(0) << x;
	string p = st.str();
	for (size_t i = 0; i < p.size() / 2; i++)
	{
		if (p[i] != p[p.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
ll digitC(double x) {
	stringstream st;
	st << fixed << setprecision(0) << x;
	return st.str().size();
}
ll digitSum(double x) {
	stringstream st;
	st << std::fixed << x;
	string p = st.str();
	ll rs = 0;
	for (size_t i = 0; i < p.size(); i++)
	{
		if (p[i] == '.') break;
		rs += p[i] - '0';
	}
	return rs;
}
pdd recs(int x) {

	if (x == 0) return make_pair(1, 2);
	pdd d = recs(x - 1);
	auto nu = d.second * 2.0 + d.first;
	auto de = d.second;
	return make_pair(de, nu);
}
ll caldig(ll a) {
	ll r = 0;
	while (a > 0) { a /= 10; r++; }
	return r;
}
int chav(char v) {
	if (v <= 'Z') return v - 'A';
	return v - 'a' + 26;
}
char itoch(int i) {
	if (i < 26) return i + 'A';
	return (i - 26) + 'a';
}
int crmp[1000][1000];
int countR(ll base, ll x, ll y, int deep) {

	if (~crmp[x][y]) {
		return deep - crmp[x][y];
	}
	crmp[x][y] = deep;
	double nu = sqrt(base) + x;
	double de = (base - (x * x)) / y;
	ll u = nu / de;
	ll nx = x - (u * de);
	return countR(base, -nx, de, deep + 1);
}

bool isPermutation(ll x, ll y) {
	int c1[10];
	int c2[10];
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	while (x > 0)
	{
		c1[x % 10]++;
		x /= 10;
	}
	while (y > 0)
	{
		c2[y % 10]++;
		y /= 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (c1[i] != c2[i]) return false;
	}
	return true;
}

double heron(ll a, ll b, ll c) {
	double s = (double)(a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double calcThreePS(double x1, double y1, double x2, double y2, double x3, double y3) {
	return abs((x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.0);
}
typedef vector<vl> mat;
class Matrix1 {

public:
	static const int M = INF;
	int n;
	mat mul(mat& A, mat& B) {
		mat C(A.size(), vl(B[0].size()));
		for (size_t i = 0; i < A.size(); i++)
		{
			for (size_t k = 0; k < B.size(); k++)
			{
				for (size_t j = 0; j < B[0].size(); j++)
				{
					C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
				}
			}
		}
		return C;
	}

	mat pow(mat A, ll n) {
		mat B(A.size(), vl(A.size()));
		for (size_t i = 0; i < A.size(); i++)
		{
			B[i][i] = 1;
		}
		while (n > 0) {
			if (n & 1) B = mul(B, A);
			A = mul(A, A);
			n >>= 1;
		}


		return B;
	}

};
ll m;
ll stringDivRm(string s, ll k) {

	ll v = 0;
	
	for (size_t i = 0; i < s.size(); i++)
	{
		v *= 10;
		v += s[i] - '0';
		v %= k;
	}
	return v;
}

ll repPow(ll b, ll x,ll md) {
	ll res = 1;
	ll v = b;

	while (x > 0)
	{
		if (x & 1) {
			res *= v;
			res %= md;
		}
		v *= v;
		v %= md;
		x >>= 1;
	}

	return res;
}
ll repPow(ll b, ll x) {
	return repPow(b, x, INF);
}
ll uar[1000010];
ll upr(ll u, ll r) {
	return (fac[u] * finv[u-r]) % INF;
}
ll partitionMemo[20010][110];
ll partitionNum(ll v, ll k) {
	if (k == 1) return 1;
	if (v <= 1) return 1;
	if (~partitionMemo[v][k]) return partitionMemo[v][k];
	ll r = 0;
	if (v < k) {
		r = partitionNum(v,v);
	}
	else
		r = partitionNum(v, k - 1) + partitionNum(v - k, k);
	r %= INF;

	return partitionMemo[v][k] = r;
}

class SetTree1 {

public:
	static const int MAX_N = 100000;
	static const int MAX_Q = 100000;
	int N, Q;
	static const int DAT_SIZE = (1 << 18) - 1;
	int A[MAX_N];
	char T[MAX_Q];

	ll data[DAT_SIZE];
	void init(int _n) {
		memset(data, 0, sizeof(data));
		int p = 1;
		while (p < _n)
		{
			p <<= 1;
		}
		N = p;
		Q = N - 1;
	}
	void update(int a, int b) {

		for (size_t i = a; i <= b; i++)
		{
			update(Q + i);
		}
	}
	void update(int a) {

		int x = data[a];
		while (a > 0)
		{
			if (a % 2 == 0)a--;
			a >>= 1;
			data[a] += x;
		}
	}
	void add(int a, int b, int x) {
		add(a, b + 1, x, 0,0,N);
	}
	void add(int a, int b, int x, int k, int l, int r) {
		if (a <= l && r <= b) {
			data[k] += x;
		}
		else if (l < b && a < r) {
			data[k] += (min(b, r) - max(a, l)) * x;
			add(a, b, x, k * 2 + 1, l, (l + r) / 2);
			add(a, b, x, k * 2 + 2, (l + r) / 2, r);
		}
	}
	ll sum(int a, int b) {
		return sum(a, b + 1, 0, 0, N);
	}
	ll sum(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) return 0;
		else if (a <= l && r <= b) {
			return data[k];
		}
		else {
			ll res = 0;
			res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
			res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
			return res;
		}
	}

};
class Segment;
class Point {
public:
	double x, y;

	Point(double x = 0, double y = 0) :x(x), y(y) {}

	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator * (double a) { return Point(a * x, a * y); }
	Point operator / (double a) { return Point(x / a, y / a); }

	double abs() { return sqrt(norm()); }
	double norm() { return x * x + y * y; }

	bool operator < (const Point& p)const {
		return x != p.x ? x < p.x : y < p.y;
	}
	bool operator == (const Point& p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
	static double dot(Point a, Point b) {
		return a.x * b.x + a.y * b.y;
	}
	static double cross(Point a, Point b) {
		return a.x * b.y - a.y * b.x;
	}
	static bool isOrthogonal(Point a, Point b) {
		return EQ(dot(a, b), 0.0);
	}
	static bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
		return isOrthogonal(a1 - a2, b1 - b2);
	}
	static bool isOrthogonal(Segment s1, Segment s2);

	static bool isPalallel(Point a, Point b) {
		return EQ(cross(a, b), 0.0);
	}
	static bool isPalallel(Point a1, Point a2, Point b1, Point b2) {
		return isPalallel(a1 - a2, b1 - b2);
	}
	static bool isPalallel(Segment s1, Segment s2);

	static const int COUNTER_CLOCKWISE = 1;
	static const int CLOCKWISE = -1;
	static const int ONLINE_BACK = 2;
	static const int ONLINE_FRONT = -2;
	static const int ON_SEGMENT = 0;
	static int ccw(Point p0, Point p1, Point p2) {
		Point a = p1 - p0;
		Point b = p2 - p0;
		if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
		if (cross(a, b) < -EPS) return CLOCKWISE;
		if (dot(a, b) < -EPS) return ONLINE_BACK;
		if (a.norm() < b.norm()) return ONLINE_FRONT;
		return ON_SEGMENT;
	}

	static bool intersect(Point p1, Point p2, Point p3, Point p4) {
		return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0
			&& ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
	}
	static bool intersect(Segment s1, Segment s2);
	static Point project(Segment s, Point p);

	static Point reflect(Segment s, Point p);

	static Point getDistance(Point a, Point b) {
		return (a - b).abs();
	}

	static double getDistanceLP(Segment s, Point p);

	static double getDistanceSP(Segment s, Point p);

	static double getDistance(Segment s1, Segment s2);

	static Point getIntersection(Segment s1, Segment s2);

	static double getArea(vector<Point> g) {
		double res = 0;
		rep(i, n) {
			int ne = (i + 1) % n;
			res += cross(g[i], g[ne]);
		}
		return res / 2.0;
	}
};

class Segment {
public:
	Point p1, p2;
	Segment() {}
	Segment(Point p1, Point p2) :p1(p1), p2(p2) {}
	double norm() {
		return (p2 - p1).norm();
	}
};

bool Point::isOrthogonal(Segment s1, Segment s2) {
	return EQ(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}
bool Point::isPalallel(Segment s1, Segment s2) {
	return EQ(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}
bool Point::intersect(Segment s1, Segment s2) {
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
Point Point::project(Segment s, Point p) {
	Point base = s.p2 - s.p1;
	double r = Point::dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}
Point Point::reflect(Segment s, Point p) {
	return (project(s, p) * 2) - p;
}
double Point::getDistanceLP(Segment s, Point p) {
	return std::abs(cross(s.p2 - s.p1, p - s.p1) / (s.p2 - s.p1).abs());
}
double Point::getDistanceSP(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return (p - s.p1).abs();
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return (p - s.p2).abs();
	return getDistanceLP(s, p);
}
double Point::getDistance(Segment s1, Segment s2) {
	if (intersect(s1, s2)) return 0.0;
	return min({ getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)
		,getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2) });
}
Point Point::getIntersection(Segment s1, Segment s2) {
	// (s1.p1 - s2.p1).norm()
	auto bs = s1.p2 - s1.p1;
	auto n1 = s2.p1 - s1.p1;
	auto n2 = s2.p2 - s1.p1;
	auto c1 = std::abs(cross(n1, bs)) / bs.norm();
	auto c2 = std::abs(cross(n2, bs)) / bs.norm();
	return s2.p1 + (s2.p2 - s2.p1) * (c1 / (c1 + c2));
	// c1:c2=t:1-t
	// c2t=(1-t)c1
	// t/(1-t)=c1/(c1+c2)
	// 
}

ll count(vector<ll> ve, ll x) {
	ll cnt = 0;

	// 膨らむ数を数える
	rep(i, ve.size()) {
		ll v = (x / ve[i])+ (x % ve[i] > 0);
		auto p = lower_bound(all(ve), v) - ve.begin();

		cnt += ve.size() - max(i + 1,(ll)p);
	}
	return cnt;
}
bool ck(vector<int> &u, vector<char> t) {
	bool ok = true;
	map<char, int> mp;
	rep(i, t.size()) mp[t[i]]++;
	for(auto v:mp) {
		if (u[v.first] < v.second) ok = false;
	}
	if (!ok) return false;
	for (auto v : mp) u[v.first] -= v.second;
	return true;
}
void solv() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	c <<= 1;
	ll res = max(x, y) * c;
	res = min(res, min(x, y) * c + ((x > y) ? (x - y) * a : (y - x) * b));
	res = min(res, x * a + y * b);
	cout << res << endl;
}

int main() {
	//COMinit();
	solv();
	return 0;
}
 