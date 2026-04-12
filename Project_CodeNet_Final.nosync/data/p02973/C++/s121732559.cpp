#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define debug(v) {for (auto x : v) cerr << x << ' '; cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n; scanf("%d", &n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		x = -x;
		auto it = s.upper_bound(x);
		if (it != s.end()) s.erase(it);
		s.insert(x);
	}
	printf("%lu\n", s.size());
}
