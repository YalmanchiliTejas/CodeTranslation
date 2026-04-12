
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
#define rep(i,N) for (int i=0;i<N;i++)
#define loop(i,N,M) for(int i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)

//変数
ll N, X, ans=0;
vector<ll> level(55);
vector<ll> dan(55);
bool is_end = false;

//解法
void solve() {

	rep(i, 55) {
		if (i == 0) {
			level[i] = 1;
			dan[i] = 1;
		}
		else {
			level[i] = level[i - 1] * 2 + 1;
			dan[i] = dan[i - 1] * 2 + 3;
		}
	}

	ll L = N;
	while (1) {
		if (L == 0) {
			if (X == 1) ans++;
			break;
		}

		if (X == 0) {
			break;
		}
		else if (X <= dan[L - 1]) {
			X--;
			L--;
			continue;
		}
		else if (X == dan[L - 1] + 1) {
			ans += level[L - 1];
			break;
		}
		else if (X == dan[L - 1] + 2) {
			ans += level[L - 1] + 1;
			break;
		}
		else if (X<dan[L-1]*2+2) {
			ans += level[L - 1] + 1;
			X -= dan[L - 1] + 2;
			L--;
			continue;
		}
		else {
			ans += level[L - 1] * 2+1;
			break;
		}

	}

	cout << ans;


	return;
}

int main() {
	//入力

	cin >> N >> X;

	solve();
	cout << endl;
	return 0;
}