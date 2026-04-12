#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <istream>
#include <ostream>
#include <deque>

#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,n) for(ll i=0; i < (n); ++i)
#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)

#define OPLT(T) bool operator<(const T & lop_, const T & rop_)
#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

int main() {
	deque<int> b;
	int n; cin >> n;
	rep(i,n) {
		int a; cin >> a;
		if(i % 2) b.push_back(a);
		else b.push_front(a);
	}
	vector<int> vb;
	if(n % 2)
		vb = vector<int>(b.begin(), b.end());
	else
		vb = vector<int>(b.rbegin(), b.rend());
	rep(i,n) {
		if(i) cout << " ";
		cout << vb[i];
	}
	cout << endl;

	return 0;
}
