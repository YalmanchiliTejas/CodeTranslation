#include <bits/stdc++.h>
#include <array>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i) 
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i) 
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n);i>0;--i)
#define CI cin>> 
#define CO cout<<
#define EN <<endl 
#define all(x) (x).begin(),(x).end() 
using namespace std;
template <typename T> istream & operator >> (istream & is, vector<T> & vec) { for (T& x : vec) is >> x; 	return is; }
using ll = long long;
using VI = vector<int>;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

int main() {
	int x; CI x;
	if (x == 3 or x == 5 or x == 7) { CO "YES" EN; }
	else CO "NO" EN;
}
