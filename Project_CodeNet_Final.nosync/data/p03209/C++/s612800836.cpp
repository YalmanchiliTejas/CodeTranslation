
#include <bits/stdc++.h> 
#define FOR(i,a,b) for(int i=(a);i<=(b);++i) 
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i) 
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n);i>0;--i)
#define CI cin>> 
#define CO cout<<
#define EN <<endl 
#define all(x) (x).begin(),(x).end() 
#define asn ans
using namespace std;
template <typename T> istream& operator >> (istream& is, vector<T>& vec) { for (T& x : vec) is >> x; 	return is; }
using ll = long long;

long long p[1000] = {1};
long long a[1000] = {1};

long long makeB(long long n,long long x) {
	if (n == 0) {
		if (x <= 0)return 0;
		else return 1;
	}
	else if (x <= 1 + a[n - 1]) {
		return makeB(n - 1, x - 1);
	}
	else {
		return p[n - 1] + 1+makeB(n-1,x-2-a[n-1]);
	}
}

int main() {
	long long n,x; CI n>>x;

	for(int i=1;i<n;i++) {
		a[i] = a[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}

	CO makeB(n, x) EN;

	return 0;
}