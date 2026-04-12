#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include<functional>
#include<queue>
#include<regex>
#include<time.h>
#include <iterator>

/*
#include <thread>
#include <exception>
*/

using namespace std;

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl

#define Tof(x) (x) ? Yes : No
#define TOF(x) (x) ? YES : NO
#define tof(x) (x) ? yes : no

using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll INF = 1050000000;



/*for文でx,yを上下左右確認するやつだよ。正直使いづらいよ。

int dx[] = { 1,-1, 1,-1,0,1,-1, 0 };
int dy[] = { 1,-1,-1, 1,1,0, 0,-1 };


for (int i = 0; i < 4; i++) {
	int ny = y + dy[i];
	int nx = x + dx[i];
}

*/

/*繰り返し二乗法だよ。modもとってくれるよ。n^kをmodで割った余りでやってくれるよ。

ll POW_MOD(ll n, ll k, ll mod) {
	ll r = 1;

	for (; k > 0; k >>= 1) {
		if (k & 1) {
			r = (r * n) % mod;
		}
		n = (n * n) % mod;
	}
	return r;
}

*/

/*2重for文書くのめんどくなった時用だよ。

for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {

	}
}

*/
#define index_of(as, x) distance(as.begin(), upper_bound(as.begin(), as.end(), x))

vector<int> lis_fast(const vector<int>& a) {
	const int n = a.size();
	vector<int> A(n, INF);
	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = index_of(A, a[i]);
		A[id[i]] = a[i];
	}
	int m = *max_element(id.begin(), id.end());
	vector<int> b(m + 1);
	for (int i = n - 1; i >= 0; --i)
		if (id[i] == m) b[m--] = a[i];
	//cout << lower_bound(b.begin(),b.end(), INF) - b.begin() << endl;
	return b;
}

int main() {
	int n; cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());

	cout << lis_fast(a).size() << endl;



	return 0;
}
