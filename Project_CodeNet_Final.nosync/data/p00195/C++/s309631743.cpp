#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define ERASE(v,i) (v).erase(remove(all(v),i),(v).end())
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define LINE cerr<<"LINE: "<<__LINE__<<endl;
inline int toInt(string s){int v;istringstream i(s);i>>v;return v;}
template<class T> inline string toString(T x){ostringstream o;o<<x;return o.str();}
template<class T> void pv(T a,T b){for(T it=a;it!=b;++it)cerr<<*it<<" ";cerr<<endl;}
const int INF = 1000000000;
const double PI = acos(-1.0), EPS = 1e-10;

int main() {
	for(int a, m; cin >> a >> m, a || m;) {
		vector<pair<int, char> > v;
		v.push_back(mp(a + m, 'A'));
		for(int i = 1; i <= 4; i++) {
			cin >> a >> m;
			v.push_back(mp(a + m, 'A' + i));
		}
		sort(v.rbegin(), v.rend());
		cout << v[0].second << " " << v[0].first << endl;
	}

	return 0;
}