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

int main() {
	int n; string s; int k; CI n >> s >> k;

	REP(i, n) {
		if (s[i] != s[k-1]) s[i] = '*';
	}

	CO s EN;

	return 0;
}