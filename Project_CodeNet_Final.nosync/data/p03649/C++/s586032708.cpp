#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define rep(i,n)	for(int i=0;i<n;i++)
#define srep(i,a,n)	for(int i=a;i<n;i++)
#define REP(i,n)	for(int i=0;i<=n;i++)
#define SREP(i,a,n)	for(int i=a;i<=n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define fst	first
#define scn second
#define bicnt(x)	__buildin__popcount(x)
#define debug(x)	cout<<"debug: "<<x<<endl
#define DEBUG 0

const ll inf = (ll)1e16;
const ll mod = (ll)1e9 + 7;
const ld eps = 1e-18;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int main() {
	int n;	cin >> n;
	vector<ll> a(n);
	rep(i, n)	cin >> a[i];
	ll ret = 0;
	while (true) {
		bool flag = true;
		rep(i, n)	flag &= (a[i] < n);
		if (flag)	break;
		vector<ll> cnt(n + 1, 0);
		rep(i, n)	cnt[i + 1] = max(0LL, (ll)ceill(((ld)(a[i] - n + 1) / n)));
		rep(i, n)	cnt[i + 1] += cnt[i];
		ret += cnt[n];
		rep(i, n) {
			a[i] -= (cnt[i + 1] - cnt[i])*(n + 1) - cnt[n];
		}
	}
	cout << ret << endl;
	return 0;
}