#include <bits/stdc++.h>
using namespace std;


#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
ll mod = 1e9 + 7;
ld eps = 1e-6;

ll dp[107][10007][2];

string k;
int d;


ll solve(ll m, int index, bool greater) {
	if (index == (int)k.size()) {
		return m == 0;
	}
	if (dp[m][index][greater] != -1)
		return dp[m][index][greater];

	ll sum = 0;
	if (greater) {
		for (int i = 0; i < 10; i++) {
			sum += solve((m+i) % d, index+1, 1) % mod;
			sum %= mod;
		}
	}
	else {
		for (int i = 0; i < k[index] - '0'; i++) {
			sum += solve((m+i) % d, index+1, 1) % mod;
			sum %= mod;
		}
		sum += solve((m+k[index] - '0') % d, index+1, 0) % mod;
		sum %= mod;
	}

	return dp[m][index][greater] = sum;

}


int main() {
	fastIO;
	cin >> k >> d;
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 0, 0) - 1 + mod) % mod;
}
