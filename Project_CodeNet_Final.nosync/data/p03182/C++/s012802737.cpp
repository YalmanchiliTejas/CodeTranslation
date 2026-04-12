//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T1> bool chmax(T1 &a, const T1 &b) { if (a < b) { a = b; return true; } return false; }
template<class T1> bool chmin(T1 &a, const T1 &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

template <typename T1, typename T2>
struct LST {	
	function<T1(T1,T1)> f;
	function<T1(T1,T2)> g;
	function<T2(T2,T2)> h;
	function<T2(T2,int)> p;
	T1 d1; T2 d0;
	int n;
	vector<T1> dat;
	vector<T2> lazy;

	LST(){}
	LST(int n, function<T1(T1,T2)> f, function<T1(T1,T2)> g, function<T2(T2,T2)> h, T1 d1, T2 d0, function<T2(T2,int)> p=[](T2 a, int b){return a;}): f(f), g(g), h(h), p(p), d1(d1), d0(d0) 
	{
    	this->n = 1; while(this->n < n) this->n *= 2;
    	dat.assign(this->n*2-1, d1);
    	lazy.assign(this->n*2-1, d0);
	}
	void build(vector<T1> v) {
    	rep(i,0,v.size()) dat[i+n-1] = v[i];
    	for(int i=n-2; i>=0; --i) dat[i] = f(dat[i*2+1], dat[i*2+2]);
	}

	// 区間の幅がlenの節点kについて遅延評価
	inline void eval(int len, int k) {
    	if(lazy[k] == d0) return;
    	if(k*2+1 < n*2-1) {
      		lazy[2*k+1] = h(lazy[k*2+1], lazy[k]);
      		lazy[2*k+2] = h(lazy[k*2+2], lazy[k]);
    	}
    	dat[k] = g(dat[k],p(lazy[k],len));
    	lazy[k] = d0;
	}

	// [a, b)
	T1 update(int a, int b, T2 x, int k, int l, int r) {
    	eval(r-l, k);
    	if(b <= l || r <= a) return dat[k];
    	if(a <= l && r <= b) {
      		lazy[k] = h(lazy[k], x);
      		return g(dat[k], p(lazy[k],r-l));
    	}
    	return dat[k] = f(update(a, b, x, 2*k+1, l, (l+r)/2),update(a, b, x, 2*k+2, (l+r)/2, r));
	}
  	T1 update(int a, int b, T2 x) { return update(a, b, x, 0, 0, n); }

  	// [a, b)
  	T1 query(int a, int b, int k, int l, int r) {
    	eval(r-l, k);
    	if(a <= l && r <= b) return dat[k];
    	bool left = !((l+r)/2 <= a || b <= l), right = !(r <= 1 || b <= (l+r)/2);
    	if(left&&right) return f(query(a, b, 2*k+1, l, (l+r)/2), query(a, b, 2*k+2, (l+r)/2, r));
    	if(left) return query(a, b, 2*k+1, l, (l+r)/2);
    	return query(a, b, 2*k+2, (l+r)/2, r);
  	}
  	T1 query(int a, int b) { return query(a, b, 0, 0, n); }

  	void debug() {
    	cout << "---------------------" << endl;
    	int cnt = 0;
    	for(int i=1; i<=n; i*=2) {
      		rep(j,0,i) {
        		cout << "(" << dat[cnt] << "," << lazy[cnt] << ") "; 
        		cnt++;
      		}
      		cout << endl;
   		}
    	cout << "---------------------" << endl;
  	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;
	int l,r,a;
	vector<vector<pii>> IV(200010);
	rep(i,0,M)
	{
		cin>>l>>r>>a;
		IV[r].push_back(mp(l,a));
	}

	auto f=[](int a,int b){return max(a,b);};
	auto g=[](int a,int b){return a+b;};
	LST<int,int> st(N+2,f,g,g,0,0);

	rep(i,1,N+1)
	{
		st.update(i,i+1,st.query(0,i));
		for(auto p:IV[i])
		{
			st.update(p.first,i+1,p.second);
		}
	}

	cout<<st.query(0,N+1)<<endl;

	return 0;
}