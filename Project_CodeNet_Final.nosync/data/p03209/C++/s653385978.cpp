#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

void Search(int n, long long int k,vector<long long int>&a,vector<long long int>&p,long long int &ans) {
	for (int i = n; i >= 0; i--) {
		if (a[i] == k) {
			ans += p[i];
			k = 0;
		}
		else if (a[i] / 2 + 1 <= k) {
			ans += p[i] / 2 + 1;
			k -= a[i] / 2 + 1;
		}
		else if (a[i] / 2 == k) {
			ans += p[i] / 2;
			k = 0;
		}
		else {
			k--;
		}
	//	cout << i << " " << ans << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>a(N + 1, 1);
	vector<long long int>p(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		p[i] = p[i - 1] * 2 + 1;
		a[i] = a[i - 1] * 2 + 3;
	//	cout << i << " " << p[i] << " " << a[i] << endl;
	}
	long long int ans = 0;
	Search(N, M, a, p, ans);
	cout << ans << endl;
}