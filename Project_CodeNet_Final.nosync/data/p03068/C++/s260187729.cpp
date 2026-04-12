#include <stdio.h>
#include <sstream>
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
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, char> pic;
#define bit(x,v) ((ll)x << v)

const ll INF = 1000000007;
const int MAX = 210000;
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
int pr[100010];
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

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
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
ll merge(ll *a, int left, int mid, int right) {
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
ll merge2(pair<int, char> *a, int left, int mid, int right) {
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
ll mergeSort2(pair<int, char> *a, int left, int right) {
	ll res = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		res = mergeSort2(a, left, mid);
		res += mergeSort2(a, mid, right);
		res += merge2(a, left, mid, right);
	}
	return res;
}
ll mergeSort(ll *a, int left, int right) {
	ll res = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		res = mergeSort(a, left, mid);
		res += mergeSort(a, mid, right);
		res += merge(a, left, mid, right);
	}
	return res;
}
int partition(pair<int, char> *a, int p, int r) {
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
void quick(pair<int, char> *a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quick(a, p, q - 1);
		quick(a, q + 1, r);
	}
}

int n;
vector<pii> es[100010];
int ci = 0;
ll P[1000010];
struct Node {
	int key;
	int priority;
	Node *parent, *left, *right;
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
Node* rightRotate(Node *t) {
	Node* s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}
Node* leftRotate(Node *t) {
	Node* s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}
Node* _insert(Node *t, int key, int priority) {
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
Node* _delete(Node *t, int key) {
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

	if (heap[l] < heap[i]){
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
	for (int i = H/2; i >= 0; i--)
	{
		maxHeapify(i);
	}
}
ll lcs(string s1, string s2) {
	ll dp[1010][1010];
	memset(dp, 0, sizeof(dp));
	int s1l = s1.size();
	int s2l = s2.size();
	for (size_t i = 1; i <= s1l; i++)
	{
		for (size_t j = 1; j <= s2l; j++)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			}
		}
	}
	return dp[s1l][s2l];
}
struct edge {
	ll to, cap, rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev){}
};
vector<edge> ed[100010];
void addedge(int f, int t, int c) {
	ed[f].push_back(edge(t, c, ed[t].size()));
	ed[t].push_back(edge(f, 0, ed[f].size() - 1));
}
vector<int> es2[100010];

ll d[100010];
void dij(int x) {

	d[x] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll(0, x));
	while (!q.empty())
	{
		pll p = q.top();
		q.pop();
		if (d[p.second] < p.first) continue;
		for (auto v : ed[p.second]) {
			if (d[v.to] > d[p.second] + v.cap) {
				d[v.to] = d[p.second] + v.cap;
				q.push(pll(d[v.to], v.to));
			}
		}
	}
}


int tb[5][5];
int ex[5][5];
pair<int, int> mdv[16];
int check() {
	int p = 1;
	int wc = 0;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (tb[i][j] != p) wc++;
			p++;
			p %= 16;
		}
	}
	return wc;
}

int lim = 45;
int md = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int res = INF;
int calcMd(int x, int y, int v) {

	return abs(mdv[v].first - x) + abs(mdv[v].second - y);
}
void rec(int x, int y, int deep) {

	if (deep >= res) return;
	if (deep > lim) return ;
	if (check() == 0) {
		res = deep;
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (deep >= res) return;
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= 4 || ty >= 4) continue;
		int bef = calcMd(tx, ty, tb[tx][ty]);
		swap(tb[tx][ty], tb[x][y]);
		int af = calcMd(x, y, tb[x][y]);
		if (deep + md - bef + af <= lim) {
			md -= bef;
			md += af;
			rec(tx, ty, deep + 1);
			md += bef;
			md -= af;
			for (size_t j = 0; j < 4; j++)
			{
				for (size_t k = 0; k < 4; k++)
				{
					
					cout << " " << tb[j][k];
				}
				cout << endl;
			}
		}
		swap(tb[tx][ty], tb[x][y]);

	}
}


void solv() {

	//int sx, sy;
	//int c = 1;
	//for (size_t i = 0; i < 4; i++)
	//{	
	//	for (size_t j = 0; j < 4; j++)
	//	{
	//		ex[i][j] = c % 16;
	//		mdv[c].first = i;
	//		mdv[c].second = j;
	//		c++;
	//	}
	//}
	//for (size_t i = 0; i < 4; i++)
	//{
	//	for (size_t j = 0; j < 4; j++)
	//	{
	//		cin >> tb[i][j];
	//		md += calcMd(i, j, tb[i][j]);
	//		if (tb[i][j] == 0) {
	//			sx = i;
	//			sy = j;
	//		}
	//	}
	//}
	//lim = md;
	//while (res == INF)
	//{
	//	rec(sx, sy, 0);
	//	lim += 2;
	//}
	//cout << res << endl;
	int n,k;
	cin >> n;
	string s;
	cin >> s;
	cin >> k;

	char c = s[k - 1];
	for (size_t i = 0; i < n; i++)
	{
		if (s[i] != c) s[i] = '*';
	}
	cout << s << endl;
}

int main() {
	//	COMinit();
	solv();
	return 0;
}
