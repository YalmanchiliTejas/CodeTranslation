#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
const int MAX_N = 110000; 
constexpr double EPS = 1E-11;

using namespace std;

//fixed << setprecision(10)

int main() {
	int n; cin >> n;
	
	vector<int>ans(26, 100000);
	
	rep(i, n) {
		vector<int>count(26);
		string s; cin >> s;
		rep(j, s.length()) {
			rep(c, 26) {
				if (s[j] == 'a' + c) {
					count[c]++;
				}
			}
		}
		rep(k, 26) {
				ans[k] = min(ans[k], count[k]);
			}
	}
	rep(i, 26) {
		rep(j, ans[i]) {
			cout << char('a' + i);
		}
	}
}