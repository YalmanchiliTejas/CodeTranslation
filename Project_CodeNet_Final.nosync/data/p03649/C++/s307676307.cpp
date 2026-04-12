#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 60) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

ll k, a[100];
ll n;
ll buf[100];

int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = 0;
	while (1) {
		bool f = 0;
		rep(i, n) {
			if (a[i] >= n)f = 1;
		}
		if (!f)break;
		rep(i, n)buf[i] = a[i];
		rep(i, n) {
			ll num = a[i] / n;
			//cout << num << endl;
			rep(j, n) {
				if (i != j)buf[j] += num;
				else buf[j] -= num * n;
			}
			ans += num;
		}
		//rep(i, n) {
		//	cout << buf[i] << endl;
		//}
		rep(i, n)a[i] = buf[i];
	}
	cout << ans << endl;
}