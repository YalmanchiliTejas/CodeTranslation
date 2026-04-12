#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef pair<int, pair<int, pair<int, int>>> PP;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const long long INF = 1LL << 60;
const int inf = 1e9;
const long long MOD = 1e9+7;

int dp[100005] = {};

int main() {
	ll n, x, m;
	ll MEMORY=-1;
	cin >> n >> x >> m;
	dp[x] = 1;
	vector<ll> v;
	v.push_back(x);
	ll memo = x;
	bool flg = true;
	rep(i,n-1) {
		memo = (memo * memo) % m;
		if (dp[memo]) { 
			rep(j, v.size()) {
				if (v[j] == memo) {
					MEMORY = j;
					break;
				}
			}
			break; 
		}
		dp[memo] = 1;
		v.push_back(memo);
	}
	if (MEMORY != -1) {
		ll total = 0;
		ll cnt = v.size() - MEMORY;
		rep(i, cnt) {
			total += v[i + MEMORY];
		}
		ll T = 0;
		rep(i, MEMORY) {
			T += v[i];
		}
		n -= MEMORY;
		ll t = n / cnt;
		ll s = n - t * cnt;
		ll TOTAL = 0;
		rep(i, s) {
			TOTAL += v[i + MEMORY];
		}
		ll ans = T + total * t + TOTAL;
		cout << ans << endl;
	}
	else {
		ll ans = 0;
		rep(i,v.size())ans += v[i];
		cout << ans << endl;
	}
	return 0;
}