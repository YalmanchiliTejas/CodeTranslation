#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
constexpr int MAX = 2000200;
constexpr double EPS = 1E-11;

using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;

	char x = s[k - 1];
	rep(i, n) {
		if (s[i] != x) {
			s[i] = '*';
		}
	}
	cout << s << endl;
}


