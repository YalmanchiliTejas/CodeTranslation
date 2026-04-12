#include <iostream>
#include <string>//
#include <vector>//
#include <map>
#include <cstdlib>
#include <numeric>
#include <algorithm>//ソート等に使用
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <thread>///////////////////
#include <queue>//幅優先等のキュー
#include <stack>
#include <bitset>

#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define mer(i,m,n) for(int i=(m);i>=(n);--i)

#define MOD 1000000007
//#define MOD 998244353
//#define MAX 

using namespace std;

using ll = long long int;
using ld = long double;
using std::swap;

vector<int> v;
vector<long long int> vll;
//vector<vector<int>> vec(50, vector<int>(4, 0));
vector<vector<int>> vv;
vector<char> vc;
vector<string> vs;




int main() {
	int N;
	cin >> N;
	v.resize(N);
	vector<ll> wll(N + 1, 0);
	rep(i, 0, N - 1) {
		cin >> v[i];
		wll[i + 1] = wll[i] + v[i];
	}
	ll ans = 0;
	rep(i, 0, N - 1) {
		ll sum = (wll[N] - wll[i + 1]) % MOD;
		ans += v[i] * sum;
		ans %= MOD;
	}
	cout << ans << '\n';

}