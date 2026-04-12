#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <memory.h>
#include <cassert>

using namespace std;


#define all(c) ((c).begin()), ((c).end())
#define debug(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

#define mp make_pair
#define fst first
#define snd second
#define pb push_back


const double EPS = 1e-10;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> P;


int main() {
	for(int p[6]; ; ) {
		bool end = true;
		rep(i, 6) {
			cin >> p[i];
			end &= p[i] == 0;
		}
		if (end) break;
		
		int a[3];
		rep(i, 3) a[i] = p[i] + p[i + 3];
		
		int mi = min(min(a[0], a[1]), a[2]);
		int ans = 0;
		REP(i, max(0, mi - 10), mi) {
			int t = i;
			rep(j, 3) t += (a[j] - i) / 3;
			ans = max(ans, t);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}