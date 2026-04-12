//inlclude before define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
#include<assert.h>
#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef pair<int, int> P1;
typedef long long int ll;

//define
#define INF 1e9
#define NUM 1000000007
#define all(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))

//function

/*ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}*/

/*ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a * (b / g);
}*/

int main() {
	int n;
	string s,ans;
	bool flag = true;
	VI rec(27), mem(27),fir(27);
	cin >> n;
	rep(i, n) {
		cin >> s;
		rep(i, 27) mem[i] = 0;
		if (i == 0) {
			rep(j, s.size()) rec[s[j] - 'a']++;
		} else {
			rep(j, s.size()) mem[s[j] - 'a']++;
			rep(j, 27) {
				if (rec[j] > 0 && mem[j] == 0) {
					rec[j] = 0;
				} else {
					rec[j] = min(rec[j], mem[j]);
				}
			}
			/*rep(i, 27) {
				cout << rec[i] << " " << mem[i] << "\n";
			}*/
		}
	}
	//rep(i, 27) cout << rec[i] << "\n";
	//cout << "\n";

	rep(i, 27) {
		rep(j, rec[i]) {
			ans += 'a' + i;
		}
	}
	sort(all(ans));
	cout << ans << endl;
}

