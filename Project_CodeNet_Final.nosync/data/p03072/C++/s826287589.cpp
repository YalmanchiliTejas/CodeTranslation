
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

int main() {
	int n;
	CI n;
	vector<int> a(n);
	CI a;
	int ans = 1;
	int max = a[0];

	FOR(i,1, n-1) {
		if (max <= a[i]) {
			ans++;
			max = a[i];
		}
	}

	CO ans EN;
	return 0;
}