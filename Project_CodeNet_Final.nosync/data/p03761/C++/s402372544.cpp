#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = (1<<30);
ll inf = (1LL<<60);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n;
	cin >> n;
	int i;
	vector<int> ans(27, Inf);
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<int> ch(27, 0);
		for (int j = 0; j < s.size(); j++) {
			ch[s[j] - 'a']++;
		}
		for (int j = 0; j <= 25; j++) {
			ans[j] = min(ans[j], ch[j]);
		}
	}
	for (i = 0; i <= 25; i++) {
		for (int j = 0; j < ans[i]; j++) {
			char C = 'a' + i;
			cout << C;
		}
	}
	return 0;
}