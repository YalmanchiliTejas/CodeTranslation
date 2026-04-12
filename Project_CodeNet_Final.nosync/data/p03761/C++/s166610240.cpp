#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;
#define ll long long
#define cpp mp::cpp_int
#define dequeue deque
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = 1; i <= n; i++)
#define drep(i, n) for(int i = n-1; i >= 0; i--)
#define srep(i, s, t) for (int i = s; i < t; i++)
#define vi vector<int>
#define P pair<ll, ll>
int mod = 1'000'000'000 + 7;
struct edge {
	int to;
	ll cost;
};

void COME_LET_THE_GAMES_BEGIN() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(20);
}
void reverse(string* s) {
	reverse((*s).begin(), (*s).end());
}
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main() {
	COME_LET_THE_GAMES_BEGIN();
	vector<int> v(26, 10000);
	int n;
	cin >> n;
	rep(i, n) {
		string s;
		cin >> s;
		vector<int> o(26, 0);
		for (auto x : s) {
			o[x - 'a']++;
		}
		rep(j, 26) {
			v[j] = min(v[j], o[j]);
		}
	}
	string ans = "";
	rep(i, 26) {
		string s(v[i], 'a' + i);
		ans += s;
	}
	cout << ans << endl;
}