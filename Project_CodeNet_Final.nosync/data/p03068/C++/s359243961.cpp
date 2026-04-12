#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<iomanip>
#include<map>

#define rep(i, n) for (ll i = 0; i < n; i++) 
#define rrep(i, n) for(ll i = n-1; i>=0; i--)
#define range(i, n, m) for (ll i = n; i < m; i++) 
#define rrange(i, n, m) for (ll i = n - 1; i => m; i--) 
#define MOD 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M, K;
	string S;

	cin >> N >> S >> K;



	rep(i, N) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}


	cout << S << endl;



	
	return 0;
}
