#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>

using ll = long long;
typedef unsigned long long ull;
typedef std::pair<ll, ll>p;
struct edge { int to, cost; };
std::vector<int>G[100000];
std::vector<int>I[100000];

ll min(ll a, ll b) {
	if (a >= b)return b;
	else return a;
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll Z = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
bool flag = true;
bool fl = false;
bool f = false;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
std::string abc = "abcdefghijklmnopqrstuvwxyz";

int main() {
	int n, a[50][26] = { 0 };
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::string s;
		std::cin >> s;
		for (int j = 0;j < s.size();j++) {
			a[i][s[j] - 'a']++;
		}
	}
	int b[26];
	for (int i = 0;i < 26;i++)b[i] = 100000;
	for (int i = 0;i < 26;i++) {
		for (int j = 0;j < n;j++) {
			b[i] = min(a[j][i], b[i]);
		}
	}
	for (int c = 0;c < 26;c++) {
		while (b[c] > 0) {
			std::cout << abc[c];
			b[c]--;
		}
	}
	std::cout << std::endl;
	}