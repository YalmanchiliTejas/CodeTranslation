
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include <numeric>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 9999999

using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };


ll m = 1000000007;

ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}
char maze[200][200];
char gyo[100];
int main() {
	int  H, W;
	cin >> H >> W;
	int h = H, w = W;
	int cnt = 0;
	REP(i,H) {
		REP(j, W) {
			cin >> gyo[j];
		}
		bool white = true;
		REP(j, W) {
			if (gyo[j] == '#')white = false;
		}
		if (white) {
			h--;
			continue;
		}
		else {
			REP(j, W) {
				maze[cnt][j] = gyo[j];
			}
			cnt++;
		}
	}

	int c = 0;
	int cntt = 0;
	REP(i, W) {
		bool white = true;
		REP(j, h) {
			if (maze[j][c] == '#')white = false;
		}
		if (white) {
			REP(l, h) {
				for (int k = c; k < w-1; k++) {
					maze[l][k] = maze[l][k + 1];
				}
			}
			w--;
		}
		else c++;
		cntt++;
		if (cntt >= W)break;
	}
	REP(i, h) {
		REP(j, w) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}
