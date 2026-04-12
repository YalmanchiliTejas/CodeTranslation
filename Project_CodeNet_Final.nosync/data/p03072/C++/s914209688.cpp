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

#define rep(i, n) for (int i = 0; i < n; i++) 
#define rrep(i, n) for(int i = n-1; i>=0; i--)
#define range(i, n, m) for (int i = n; i < m; i++) 
#define rrange(i, n, m) for (int i = n - 1; i => m; i--) 
#define MOD 1000000007
#define MAX 20000000000

typedef long long int ll;
typedef unsigned long long int ull;


using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M;

	cin >> N;
	vector<ll> H(150, 0);

	rep(i, N) {
		cin >> H[i];
	}


	ll count = 0;
	bool flg = false;
	rep(i, N) {
		flg = true;
		rep(k, i) {
			if (H[k] > H[i]) {
				flg = false;
			}
		}
		if (flg)count++;
	}


	cout << count << endl;

	
	return 0;
}
