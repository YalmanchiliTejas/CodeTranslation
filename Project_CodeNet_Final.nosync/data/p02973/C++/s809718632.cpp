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
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	vector<int>A(N);
	rep(i, N)cin >> A[i];
	deque<int>v;
	rep(i, N) {
		if (!i) {
			v.push_back(A[i]);
		}
		else {
			if (v[0] >= A[i]) {
				v.push_front(A[i]);
			}
			else {
				int a = lower_bound(v.begin(), v.end(), A[i]) - v.begin() - 1;
				v[a] = A[i];
			}
		}
	}
	int ans = v.size();
	cout << ans << endl;
}