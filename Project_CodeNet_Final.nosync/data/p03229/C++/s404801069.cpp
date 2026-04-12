#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<complex>
#include<functional>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<set>

using namespace std;
#define endl '\n'
#define pb push_back
#define fst first
#define scd second
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i,n) for(int i = 0;i < (n);i++)
#define FOR(i,a,b) for(int i = (a);i <= (b);i++)
#define YES(n) cout << ((n) ? "YES" : "NO" ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No" ) << endl

constexpr int MOD = 1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;

template <class T = int> T in() { T x; cin >> x; return (x); }
template <class T = int> void out(T x) { cout << (x) << endl; }

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// value

void solve() {
	
	int N;
	cin >> N;

	vl A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(ALL(A));

	vl B, C;
	int i;

	for (i = 0; i < N / 2; i++) {
		B.pb(A[i]);
	}
	for (; i < N; i++) {
		C.pb(A[i]);
	}
	sort(ALL(C), greater<ll>());
	vl ANS;
	int x = 0, y = 0;
	ANS.pb(C[y]); y++;
	for (int j = 0; ANS.size() < N; j++) {
		if (j % 2 == 0) {
			if (x < B.size() - 1) {
				if (abs(ANS[0] - B[x]) + abs(ANS.back() - B[x + 1]) > abs(ANS[0] - B[x + 1]) + abs(ANS.back() - B[x])) {
					ANS.insert(ANS.begin(), B[x]);
					ANS.pb(B[x + 1]);
				}
				else {
					ANS.insert(ANS.begin(), B[x + 1]);
					ANS.pb(B[x]);
				}
				x += 2;
			}
			else {
				if (abs(ANS[0] - B[x]) > abs(ANS.back() - B[x])) {
					ANS.insert(ANS.begin(), B[x]);
				}
				else {
					ANS.pb(B[x]);
				}
				x++;
			}
		}
		else {
			if (y < C.size() - 1) {
				if (abs(ANS[0] - C[y]) + abs(ANS.back() - C[y + 1]) > abs(ANS[0] - C[y + 1]) + abs(ANS.back() - C[y])) {
					ANS.insert(ANS.begin(), C[y]);
					ANS.pb(C[y + 1]);
				}
				else {
					ANS.insert(ANS.begin(), C[y + 1]);
					ANS.pb(C[y]);
				}
				y += 2;
			}
			else {
				if (abs(ANS[0] - C[y]) > abs(ANS.back() - C[y])) {
					ANS.insert(ANS.begin(), C[y]);
				}
				else {
					ANS.pb(C[y]);
				}
				y++;
			}
		}
	}
	vl ANS2;
	if (N % 2 == 1) {
		B.pb(C.back());
		C.pop_back();
		x = 0; y = 0;
		ANS2.pb(B[x]); x++;
		for (int j = 0; ANS2.size() < N; j++) {
			if (j % 2 == 1) {
				if (x < B.size() - 1) {
					if (abs(ANS2[0] - B[x]) + abs(ANS2.back() - B[x + 1]) > abs(ANS2[0] - B[x + 1]) + abs(ANS2.back() - B[x])) {
						ANS2.insert(ANS2.begin(), B[x]);
						ANS2.pb(B[x + 1]);
					}
					else {
						ANS2.insert(ANS2.begin(), B[x + 1]);
						ANS2.pb(B[x]);
					}
					x += 2;
				}
				else {
					if (abs(ANS2[0] - B[x]) > abs(ANS2.back() - B[x])) {
						ANS2.insert(ANS2.begin(), B[x]);
					}
					else {
						ANS2.pb(B[x]);
					}
					x++;
				}
			}
			else {
				if (y < C.size() - 1) {
					if (abs(ANS2[0] - C[y]) + abs(ANS2.back() - C[y + 1]) > abs(ANS2[0] - C[y + 1]) + abs(ANS2.back() - C[y])) {
						ANS2.insert(ANS2.begin(), C[y]);
						ANS2.pb(C[y + 1]);
					}
					else {
						ANS2.insert(ANS2.begin(), C[y + 1]);
						ANS2.pb(C[y]);
					}
					y += 2;
				}
				else {
					if (abs(ANS2[0] - C[y]) > abs(ANS2.back() - C[y])) {
						ANS2.insert(ANS2.begin(), C[y]);
					}
					else {
						ANS2.pb(C[y]);
					}
					y++;
				}
			}
		}
	}
	ll sum = 0, sum2 = 0;
	for (int j = 1; j < N; j++) {
		sum += abs(ANS[j] - ANS[j - 1]);
		if (N % 2 == 1) {
			sum2 += abs(ANS2[j] - ANS2[j - 1]);
		}
	}

	cout << max(sum, sum2) << endl;

	return;

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();

	return 0;

}