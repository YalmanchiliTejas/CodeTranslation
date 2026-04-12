#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

ll com(int r, int c) {
	if(c == 0) return 1ll;
	if(r < c) return 0ll;
	ll ret = 1ll;
	for(int i = 1; i <= c; i++) {
		ret *= r - i + 1;
	}
	for(int i = 1; i <= c; i++) {
		ret /= i;
	}
	return ret;
}

int main() {
	string n;
	cin >> n;
	int k;
	cin >> k;
	int count = 0;
	rep(i, n.size()) if(n[i] != '0') count++;
	if(n.size() < 4) {
		int n2 = stoi(n);
		if(n2 <= 110 && k == 3) {
			cout << 0 << endl;
			return 0;
		}
		else if(n2 <= 10 && k >= 2) {
			cout << 0 << endl;
			return 0;
		}
	}
	int remain_n = n.size();
	int remain_k = k;
	ll ans = 0;
	rep(i, n.size()) {
		if(n[i] != '0') {
			ans += (n[i] - '1') * com(remain_n - 1, remain_k - 1) * pow(9, remain_k - 1);
			ans += com(remain_n - 1, remain_k) * pow(9, remain_k);
			remain_k--;
		}
		if(remain_k == 0) break;
		remain_n--;
	}
	if(count >= k) ans++;
	cout << ans << endl;
}
