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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

bool gcd(string s, string t) {
	if (s > t)return !gcd(t, s);
	if (s.size() > t.size()) return true;
	int cnt = 0;
	for (int i = 0; i + s.size() <= t.size(); i += s.size()) {
		cnt = i + s.size();
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < t[i + j]) {
				return true;
			}
			if (s[j] > t[i + j]) {
				return false;
			}
		}
	}
	if (t.size() % s.size() == 0)return true;
	return !gcd(t.substr(cnt, t.size() - cnt), s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	string t;
	cin >> N;
	cin >> s >> t;
	if (s > t)swap(s, t);
	bool flag = gcd(s, t);
	if (!flag)swap(s, t);
	for (int i = N; i >= 0; i -= t.size()) {
		if (i%s.size() == 0) {
			for (int j = 0; j < i / s.size(); j++)cout << s;
			for (int j = 0; j < (N - i) / t.size(); j++)cout << t;
			cout << endl;
			return 0;
		}
	}
}