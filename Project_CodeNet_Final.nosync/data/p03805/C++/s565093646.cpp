#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define UB upper_bound
#define LB lower_bound
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int n, m;
bool e[8][8];

#define F(i) for(c[i] = 0; c[i] < n; c[i]++)

int main() {
	cin >> n >> m;
	inc(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a][b] = true;
		e[b][a] = true;
	}
	
	int ans = 0;
	
	int c[8];
	F(0) {
	F(1) {
	F(2) {
	F(3) {
	F(4) {
	F(5) {
	F(6) {
	F(7) {
		bool flag = (c[0] == 0);
		inc(i, 8) {
			if(i < n) { flag &= (inID(c[i], 0, n)); }
			else { flag &= (c[i] == 0); }
		}
		inc(i, n) {
		inc(j, i) {
			if(c[i] == c[j]) { flag = false; }
		}
		}
		if(! flag) { continue; }
		
		flag = true;
		inc(i, n - 1) {
			flag &= e[ c[i] ][ c[i + 1] ];
		}
		if(flag) { ans++; }
	}}}}}}}}
	
	cout << ans << endl;
	
	return 0;
}
