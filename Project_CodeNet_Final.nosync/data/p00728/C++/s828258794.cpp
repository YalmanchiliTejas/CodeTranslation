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
#include <functional>
#include <queue>
#include <regex>
#include<time.h>

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


/*vectorの要素を全部確認するやつだよ。普通に拡張for文したほうがいいよ。

for (vector<int>::iterator itr = ans.begin(); itr != ans.end(); ++itr) {
	cout << *itr << " ";
}

*/


/*for文でx,yを上下左右確認するやつだよ。正直使いづらいよ。

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };


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


/*実行開始からの経過時間を表すよ。

while (clock() < 1900000) {  }

*/


/*まだ使えないテクニックのメモだよ。

for (int bit = 0; bit < (1<<n); ++bit)//bit全探索用のfor文だよ

*/


/*2重for文書くのめんどくなった時用だよ。

for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {

	}
}

*/



int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == 0) { break; }


		int a[105];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		int k = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += a[i];
			k++;
		}
		cout << ans / k << endl;
	}


	return 0;
}

