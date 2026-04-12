#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;






int main() {
	vector<pii> v(5, pii(0, 0));
	int a, b;
	while (1) {
		for (int i = 0; i < 5; i++) {
			cin >> a >> b;
			v[i].second = i;
			v[i].first = a + b;
		}
		if (cin.eof())break;
		sort(all(v));
		cout << (char)('A' + v[4].second) << " " << v[4].first << endl;
	}
}