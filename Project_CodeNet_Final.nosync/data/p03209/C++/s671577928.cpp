
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <functional>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <deque>
#include <list>
#include <sys/timeb.h>
#include <fstream>
#include <set>

using namespace std;

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFL 1100000000000000000LL
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> Pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<Pi> > vvPi;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi> > pqlP;
struct Edge {
	int from, to, cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
template <class T>
using vec = vector<T>;
template<class T>
using pql = priority_queue<T, vector<T>, greater<T>>;
string debug_show(Pi a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}

template<class T>
struct augEdge {
	T from, to;
	int cost;
	bool operator<(augEdge e) { return cost < e.cost; }
	bool operator>(augEdge e) { return cost > e.cost; }
};
template<class T>
using augGraph = vector<augEdge<T>>;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, x;
	cin >> n >> x;
	vll a(51), p(51);
	p[0] = 1;
	a[0] = 1;
	repr(i, 1, 51) {
		p[i] = p[i - 1] + p[i - 1] + 1;
		a[i] = a[i - 1] + a[i - 1] + 3;
		// cout << a[i] << " " << p[i] << endl;
	}

	ll ans = 0;

	if (n == 1) {
		if (x == 5) {
			ans += 3;
			x = 0;
		}
		else if (x == 4) {
			ans += 3;
			x = 0;
		}
		else if (x == 3) {
			ans += 2;
			x = 0;
		}
		else if (x == 2) {
			ans += 1;
			x = 0;
		}
		else {
			x = 0;
		}
	}

	if (x < n + 3) {
		ans += max((ll)0, x - n);
		x = 0;
	}

	while (x > 0) {
		if (x == a[n]) {
			ans += p[n];
			x = 0;
		}
		if (x == a[n] / 2 + 1) {
			ans += p[n - 1] + 1;
			x -= a[n] / 2 + 1;
			n--;
		}
		else if (x > a[n] / 2 + 1) {
			ans += p[n - 1] + 1;
			x -= a[n] / 2 + 1;
			n--;
		}
		else {
			x--;
			n--;
		}

		if (x < n + 3) {
			ans += max((ll)0, x - n);
			x = 0;
		}

		if (x <= 5) {
			if (x == 5) {
				ans += 3;
				x = 0;
			}
			else if (x == 4) {
				ans += 3;
				x = 0;
			}
			else if (x == 3) {
				ans += 2;
				x = 0;
			}
			else if (x == 2) {
				ans += 1;
				x = 0;
			}
			else {
				x = 0;
			}
		}
		// cout << "x: " << x << endl;
		// cout << ans << endl;
	}

	cout << ans << endl;

	return 0;
}

