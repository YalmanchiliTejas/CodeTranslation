#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>

using namespace std;

#define ll long long
#define f0(i,n)for(i=0;i<n;i++)
#define f1(i,n)for(i=1;i<=n;i++)
#define fc(i,c,n)for(i=c;i<=n;i++)
#define f0r(i,n)for(i=n-1;i>=0;i--)
#define f1r(i,n)for(i=n;i>0;i--)
#define fcr(i,c,n)for(i=n;i>=c;i--)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef list<ll> LST;
typedef vector<ll> VEC;
typedef map<ll, ll> MAP;

ll i, j, q;
ll n, m, p, k, t, s, v;
ll a, b, c, d;
ll x, y, z, l, r;
ll one = 1, zero = 0, ans = 0;
ll mod = 1000000007;
ll ii;
ll INF = 223372036854775807;
ll ln1, ln2, lnc;
ll a1, a2, a3, a4, a5, a6, a7, a8, a9;
string st1, st2, st3;
char ch1, ch2, ch3;



int main() {
	int t;
	ifstream fin("Text.txt");

	cin >> n;
	VEC vc(n),vc2(n);
	f0(i, n) {
		cin >> vc[i];
		vc2[i] = vc[i];
	}
	sort(vc.begin(), vc.end());
	a1 = vc[(n / 2)-1];
	a2 = vc[n/2];

	f0(i, n) {
		if (vc2[i] >= a2) 
			cout << a1 << endl;
		else 
			cout << a2 << endl;
	}
	return 0;
}