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
typedef std::pair<ll, ll>P;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll mod = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
bool fl = true;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
std::string abc = "abcdefghijklmnopqrstuvwxyz";
struct edge { ll to, cost; };
struct edge1 { ll from, to, cost; };
double pai = 3.141592653589793;
std::vector<P>v[100010];

int main() {
	int n;
	std::cin >> n;
	std::cout << n * 800 - 200 * (n / 15) << std::endl;
}