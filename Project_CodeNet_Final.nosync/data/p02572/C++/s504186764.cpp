#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	ll sum = 0;
	vector<ll> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum += a[i];
		sum %= MOD;
	}

	ll ans = 0;
	for(int i = 0;i < n-1;i++){
		sum = (sum - a[i] + MOD) % MOD;
		ans += (a[i] * sum) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}
