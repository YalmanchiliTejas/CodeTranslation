#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
#include <tuple>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (ll i=0;i<N;i++)
#define loop(i,N,M) for(ll i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)

template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

ll N;
vector<ll> vec;

void solve() {
	cin >> N;
	vec.resize(N);
	rep(i, N) cin >> vec[i];

	vector<ll> color(N,-1);

	for (ll i = 0; i < N; i++) {

		//binary search
		//最終的にL=Rはtrueの左端で止まる
		//←false→LR←true→
		ll L = 0, R = color.size();
		//全てtrueのときは普通に0が返る
		//全てfalseのとき，sizeが返る
		while (L != R) {
			ll F = (L + R) / 2;
			bool judge;

			if (vec[i] <= color[F]) {
				judge = false;
			}
			else {
				judge = true;
			}

			if (judge) { R = F; }
			else { L = F + 1; }

		}

		color[L] = vec[i];

	}
	ll ans = 0;
	rep(i, N) {
		if (color[i] != -1) ans++;
	}

	cout << ans;

}

int main() {
	solve();
	cout << endl;
	return 0;
}
