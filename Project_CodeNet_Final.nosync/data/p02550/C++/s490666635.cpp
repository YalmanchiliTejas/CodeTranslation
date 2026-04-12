#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
//const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N, X, M;
	cin >> N >> X >> M;
	vector<int>v;
	int x = X % M;
	int start;
	map<int, int> m;
	rep(i, N + 5) {
		v.push_back(x);
		m[x]++;
		x = (x * x) % M;
		if (m[x]) {
			for (int j = 0; j < 100005; j++) {
				if (v[j] == x) {
					start = j;
					break;
				}
			}
			break;
		}
	}
	int ans = 0;
	if (N <= start) {
		rep(i, N)ans += v[i];
		cout << ans;
		return 0;
	}
	rep(i, start)ans += v[i];
	N -= start;
	int cycle = v.size() - start;
	int sum = 0;
	rep(i, cycle)sum += v[start + i];
	int loop = N / cycle;
	ans += loop * sum;
	if (N % cycle) {
		rep(i, N% cycle)ans += v[start + i];
	}
	cout << ans;
}