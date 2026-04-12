#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
// const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	const vector<char> A = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
    while (1) {
		string S; cin >> S;
		if (S == "#") break;
		int N = S.size();
		vector<bool> B(N);
		rep(i,N) {
			for (auto j : A) {
				if (S[i] == j) B[i] = true;
			}
		}
		int cnt = 0;
		rep(i,N-1) {
			if (B[i] != B[i+1]) cnt++;
		}
		cout << cnt << endl;
	}
}
