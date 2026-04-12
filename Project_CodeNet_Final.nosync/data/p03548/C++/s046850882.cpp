#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i = m; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PI 3.14159265359
typedef long long LL;

template<class T> inline void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> inline void chmin(T& a, T b) { if (a > b) { a = b; } }
template<class T> void print_vector(vector<T> vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}
template<class T> void print_pair_vector(vector<pair<T, T> > vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << "(" << vec[i].first << "," << vec[i].second << ") ";
	}
	cout << "]" << endl;
}

int calculate_digits_total(int x) {
	int digits_total = 0;
	while (x) {
		digits_total += x % 10;
		x /= 10;
	}

	return digits_total;
}


int main(void) {
	LL X, Y, Z;
	cin >> X >> Y >> Z;

	LL ans = 1;
	for (LL i = 2; i <= 100000; i++) {
		if (i*Y+(i+1)*Z <= X) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}