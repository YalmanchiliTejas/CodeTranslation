#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
	EACH(x,vec) is >> x;
	return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
	REP(i,vec.size()) {
		if (i) os << " ";
		os << vec[i];
	}
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
	REP(i,vec.size()) {
		if (i) os << endl;
		os << vec[i];
	}
	return os;
}

ll L(string s) {
	int N = s.size();
	ll res = s[0]-'0';
	for (int i = 2; i < N; i += 2) {
		int v = s[i]-'0';
		if (s[i-1] == '+') {
			res += v;
		}
		else {
			res *= v;
		}
		res = min(res, (ll)inf);
	}
	return res;
}
ll M(string s) {
	int N = s.size();
	ll res = 0, p = s[0]-'0';
	for (int i = 2; i < N; i += 2) {
		int v = s[i]-'0';
		if (s[i-1] == '+') {
			res += p;
			p = v;
		}
		else {
			p *= v;
		}
		p = min(p, (ll)p);
		res = min(res, (ll)inf);
	}
	res += p;
	res = min(res, (ll)inf);
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s; cin >> s;
	ll a; cin >> a;
//	cout << M(s) << " " << L(s) << endl;
	if ( M(s) == a && L(s) == a ) {
		cout << "U" << endl;
	}
	else if ( M(s) == a ) {
		cout << "M" << endl;
	}
	else if ( L(s) == a ) {
		cout << "L" << endl;
	}
	else {
		cout << "I" << endl;
	}
}