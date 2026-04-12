#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <tuple>
#include <cctype>
#include <ctype.h>
#include <set>
#include <sstream>
#include <time.h>
using namespace std;
//#define int long long
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
typedef long long ll;
typedef pair<int, int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint, int> P1;
typedef pair<int, pint> P2;
typedef pair<pint, pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD = 1000000007;
const ll INF = 1e18;
const double PI = 3.14159265;
int ca[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


vector<ll>pa(51,0), ba(51,0);
ll n, x;


ll func(ll n, ll x) {

	if (n == 0) {
		return 1;
	}
	else if (x == 1) {
		return 0;
	}
	else if (x>1 && x <= ba[n-1] + 1) {
		return func(n - 1, x  - 1);
	}
	else if (x == ba[n-1]+2) {
		return pa[n - 1] + 1;
	}
	else if (x > ba[n - 1] + 2 && x < ba[n] ) {
		return pa[n-1] + 1 + func(n - 1, x - ba[n - 1] - 2);
	}
	else if (x == ba[n]) {
		return pa[n];
	}

	return 0;
}


signed main() {
	int i, j;

	cin >> n >> x;

	pa[0] = 1;
	ba[0] = 1;

	for (i = 1; i <= n; i++) {
		pa[i] = pa[i - 1] * 2 + 1;
	}

	for (i = 1; i <= n; i++) {
		ba[i] = ba[i - 1] * 2 + 3;
	}

	cout << func(n, x) << endl;




	getchar();
	getchar();
	return 0;
}