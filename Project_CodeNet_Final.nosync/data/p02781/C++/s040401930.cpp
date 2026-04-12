#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
typedef short int sint;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) {
	*this << ((it != d.b) ? ", " : "") << *it;
  }
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string x;
int n;
int res;

int npo2(int q, int ileCyfr) {
	if (ileCyfr == 0) {
		return 1;
	} else if (ileCyfr == 1) {
		return q;
	} else if (ileCyfr == 2) {
		return (q * (q - 1)) / 2;
	} else {
		return (q * (q - 1) * (q - 2)) / 6;
	}
}


int fullRes(int ilePozycji, int ileCyfr) {
	int pom = npo2(ilePozycji, ileCyfr);
	while (ileCyfr > 0) {
		pom *= 9;
		--ileCyfr;
	}
	return pom;
}

int compute(int position, int ileCyfr) {
	if (position == n) {
		return ileCyfr == 0;
	}
	if (ileCyfr == 0) {
		return 1;
	}
	// moge tutaj co zrobic.
	bool isZero = (x[position] == '0');
	if (isZero) {
		return compute(position + 1, ileCyfr);
	}
	// moge dac zero i juz potem dowolnie
	int r = fullRes(n - position -1, ileCyfr);
	r += (x[position] - '0' - 1) * fullRes(n - position - 1, ileCyfr - 1);
	r += compute(position + 1, ileCyfr - 1);
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	// n;
	// string x;
	cin >> x;
	n = x.size();
	int pom;
	cin >> pom;
	cout << compute(0, pom) << endl;
}