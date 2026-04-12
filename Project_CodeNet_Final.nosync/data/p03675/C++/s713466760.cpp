// In The Name Of God
#include <bits/stdc++.h>

#define sqr(A) ((A) * (A))
#define X first
#define Y second
#define MP make_pair
#define bsz  __builtin_popcount
#define all(A) A.begin(), A.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 2e5 + 20;
int a[N], n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n % 2 == 0) {
		for (int i = n; i >= 2; i -= 2)
			cout << a[i] << ' ';
		for (int i = 1; i <= n - 1; i += 2)
			cout << a[i] << ' ';
		cout << endl;
	}
	else {
		for (int i = n; i >= 1; i -= 2)
			cout << a[i] << ' ';
		for (int i = 2; i <= n - 1; i += 2)
			cout << a[i] << ' '; 
		cout << endl;
	}
}

































