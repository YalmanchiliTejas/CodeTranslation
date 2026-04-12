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
const double PI = 3.1415926535897932384626433832795;
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
	string s = "aiueo";
	char c;
	cin >> c;
	for (auto x : s) {
		if (c == x) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
}