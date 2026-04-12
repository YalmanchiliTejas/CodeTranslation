#include <numeric>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define vi vector<int>
#define vll vector<long long>
#define vld vector<ld>
#define vs vector<string>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>

using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
#define NUM 998244353 // 1000000007
#define pb push_back
#define mp make_pair

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

#define printcase(x) print("Case #" + to_string(test_case_num) + ":",x); return
#define printret(x) {print(x); return;}



template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void DBG() {
	print("]");
}
template<class H, class... T> void DBG(H h, T... t) {
	write(to_string(h));
	if(sizeof...(t))
		write(", ");
	DBG(t...);
}
#ifdef _DEBUG
	#define dbg(...) write("LINE(", __LINE__, ") -> [" , #__VA_ARGS__ ,"]: ["); DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

#define VECTOR_MULT_ll(v) (accumulate(all((v)), (ll)1, multiplies<ll>()))

#define VECTOR_MULT_ll_i(v,i) (accumulate((v).begin(), (v).begin()+(i), (ll)1, multiplies<ll>()))


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long mod_binpow(long long a, long long b, ll p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a) %p;
        b >>= 1;
    }
    return res % p;
}

ll mod_inverse_prime(ll a, ll p){
	return mod_binpow(a,p-2,p) % p;
}

/* Modular inverse not for prime */
ll mod_inverse(ll a, ll b){
 return 1<a ? b - mod_inverse(b%a,a)*b/a : 1;
}

bool ok_indexes(int n,int m,int i,int j){
	return (i>= 0 && i < n && j >= 0 && j < m);
}
bool backtrack(vt<pair<int,int>>& a,int n, int m,int x,int y,int idx, vt<vt<bool>>& vis){
	// print(x+1,y+1);
	a[idx] = mp(x+1,y+1);
	// print(a[idx].fi);
	vis[x][y] = true;
	if (idx == n*m-1){
		return true;
	}
	int di,dj;
	FOR(4){
		tie(di,dj) = mp(d4i[i], d4j[i]);
		// print("yooo",x+di+1,y+dj+1);
		if (ok_indexes(n,m,x+di,y+dj) && !vis[x+di][y+dj]){
			bool good = backtrack(a,n,m,x+di,y+dj, idx+1,vis);
			if (good) return good;
		}
	}
	// print("yooooooooo");
	vis[x][y] = false;
	return false;

}


// vi bfs(int s){
// 	// int n = adj.size();

// 	queue<int> q;
// 	vector<bool> used(n);
// 	vector<int> d(n), p(n);

// 	q.push(s);
// 	used[s] = true;
// 	p[s] = -1;
// 	while (!q.empty()) {
// 	    int v = q.front();
// 	    q.pop();
// 	    for (int u : adj[v]) {
// 	        if (!used[u]) {
// 	            used[u] = true;
// 	            q.push(u);
// 	            d[u] = d[v] + 1;
// 	            p[u] = v;
// 	        }
// 	    }
// 	}
// 	return d;
// }




ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
template <typename T>
T gcd_array (vt<T> & arr) 
{ 
	T n = arr.size();
	T result = arr[0]; 
	for (T i = 1; i < n; i++) 
	{ 
		result = gcd(arr[i], result); 
		if(result == 1) 
		{ 
		return 1; 
		} 
	} 
	return result; 
} 

template <typename T>
T gcd_set (set<T> & arr) 
{ 
	T n = arr.size();
	T result = *arr.begin();
	auto iter = next(arr.begin());
	while(iter != arr.end()){ 
		result = gcd(*iter, result); 
		if(result == 1){ 
			return 1; 
		} 
		iter++;
	} 
	return result; 
} 


ll longlog(ld base, ld x) {
    return (ll)(log(x) / log(base));
}
// int mxN = 10e3;
// int A[mxN][mxN], B[mxN][mxN];
// bool vis[mxN][mxN];
// char output[mxN][mxN];

// ll total = 0;
// void solve_rec(vll & a, ll n, ll spare =0, int start=0){
// 	if(start == n) return;
// 	if (a[start] > 0){
// 		spare+= 
// 	}
// 	solve_rec(a,n, spare + /***x***/, start+1);
// }
class Solution {
public:
   // map <int ,int > l;
   int best;
   int node;
   int dfs(int v, bool* visited, vvi& graph, int c = 0){
      visited[v] = true;
      int ans = 0;
      for(int i = 0; i < graph[v].size(); i++){
         if(!visited[graph[v][i]])ans = max(ans,dfs(graph[v][i], visited, graph, c+1));
      }
      if(c > best){
         best = c;
         node = v ;
      }
      visited[v] = false;
      return max(c,ans);
   }
   int treeDiameter(vvi & graph, int n) {
      bool* visited = new bool[n]();
      best = 0;
      node = 0;
      dfs(0, visited, graph);
      bool* visited2 = new bool[n]();
      return dfs(node, visited2, graph);
   }
};

int dfs2(int v, int parent, int b, int dist, vvi &adj){
	// dbg(v,parent,b,dist);
	fflush(0);
	if(v == b) return dist;
	EACH(u,adj[v]){
		if (u == parent) continue;
		int res = dfs2(u,v,b,dist+1,adj);
		if(res != -1) return res;
	}
	return -1;
}





// int mxN = 3*10e5;
// int a[mxN];
// #define RIA int n; read(n); vi a(n); read(a);
// #define RLA ll n; read(n); vll a(n); read(a);
// vvi adj;
/*
	adj = vi(n);
	FOR(n-1){
		int l,r; read(l,r);
		l--; r--;
		adj[l].pb(r);
		adj[r].pb(l);
	}
*/

void solve(int test_case_num) {
	ll n,x,m; read(n,x,m);
	ll l = x;
	vll last(m,(ll)-1);
	vll by_order; by_order.reserve(m);
	last[x] = 0;
	by_order.pb(x);
	int i = 1;
	while(i < n){
		l = (l*l)%m;
		if(last[l]!=-1){
			break;
		}
		last[l] = i;
		by_order.pb(l);
		i++;
	}
	dbg(by_order);
	if(i==n){
		printret(accumulate(all(by_order), (ll)0));
	}
	i = 0;
	ll one_sum = 0, other_sum=0;
	for(;by_order[i] != l;i++) one_sum+=by_order[i];
	ll one_len = i;
	ll other_len =by_order.size() - one_len;
	for(;i < by_order.size();i++) other_sum+=by_order[i];
	ll res = one_sum; 
	n-=one_len;
	res+=(n/other_len)*other_sum;
	for(i=0; i < n%other_len; i++){
		res+=(by_order[one_len+i]);
	}
	print(res);

	


}


int main() {
	bool real = true;
	#ifdef _DEBUG
		real = false;
		freopen("q1.input", "r", stdin);
	#endif
	if(real){
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
	int t = 1;
	// read(t);
	FOR(t){
		// print("Case #" + to_string(t) + ":",res); THIS GOES IN SOLVE()
		solve(i+1);
	}

	return 0;
}