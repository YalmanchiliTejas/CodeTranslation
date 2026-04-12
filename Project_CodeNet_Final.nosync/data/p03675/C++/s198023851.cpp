#include <iostream>
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
#define bucnt(x)	__buildin__popcount(x)
#define debug(x)	cout<<"debug: "<<x<<endl

const ll inf = (ll)1e9;
const ll mod = (ll)1e9 + 7;
const ld eps = 1e-9;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int main() {
	int n;	cin >> n;
	vint a(n);
	rep(i, n)	cin >> a[i];
	vint b(n);
	int left = 0, right = n - 1;
	rep(i, n) {
		if (i & 1)	b[right--] = a[n - i - 1];
		else	b[left++] = a[n - i - 1];
	}
	rep(i, n){
		cout << (i ? " " : "") << b[i];
	}
	cout << endl;
	return 0;
}