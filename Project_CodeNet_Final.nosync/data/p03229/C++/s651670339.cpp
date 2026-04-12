
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

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
#define INF 999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))

using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };




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

long long nCr(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


const int MOD = 1000000007;


int A[100010];
ll B[100010];
int main() {
	int N; cin >> N;
	REP(i, N) {
		cin >> A[i];
	}
	SORT(A, N);

	int mid = N/ 2;
	B[mid] = A[0];
	if (N % 2 == 1) {
		REP(i, mid) {
			if (i % 2 == 0) {
				B[mid - i - 1] = A[N - i - 1];
				B[mid + i + 1] = A[N - 1 - i - 1];
			}
			if (i % 2 == 1) {
				B[mid - i - 1] = A[i];
				B[mid + i + 1] = A[i+1];
			}
		}
	}
	if (N % 2 == 0) {
		REP(i, mid) {
			if (i % 2 == 0) {
				B[mid - i - 1] = A[N - i - 1];
				B[mid + i + 1] = A[N - 1 - i - 1];
			}
			if (i % 2 == 1) {
				B[mid - i - 1] = A[i];
				B[mid + i + 1] = A[i + 1];
			}
		}
	}

	ll ans1 = 0;
	REP(i, N - 1) {
		ans1 += abs(B[i] - B[i + 1]);
	}

	REVERSE(A, N);
	B[mid] = A[0];
	if (N % 2 == 1) {
		REP(i, mid) {
			if (i % 2 == 0) {
				B[mid - i - 1] = A[N - i - 1];
				B[mid + i + 1] = A[N - 1 - i - 1];
			}
			if (i % 2 == 1) {
				B[mid - i - 1] = A[i];
				B[mid + i + 1] = A[i + 1];
			}
		}
	}
	if (N % 2 == 0) {
		REP(i, mid) {
			if (i % 2 == 0) {
				B[mid - i - 1] = A[N - i - 1];
				B[mid + i + 1] = A[N - 1 - i - 1];
			}
			if (i % 2 == 1) {
				B[mid - i - 1] = A[i];
				B[mid + i + 1] = A[i + 1];
			}
		}
	}


	ll ans2 = 0;
	REP(i, N - 1) {
		ans2 += abs(B[i] - B[i + 1]);
	}
	cout << max(ans1, ans2) << endl;
}


