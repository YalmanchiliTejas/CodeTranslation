#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

struct ans {
	int from, to; string cost;
};
vector<ans> v;
bool exi[301][301];
void solve() {

	int a, b; cin >> a >> b;
	int d[11][11];
	rep1(i, a) {
		rep1(j, b) {
			cin >> d[i][j];
		}
	}
	bool valid = true;
	int s = 1, t = 202, cur = 3;
	Rep1(i, 2, 101) {
		v.push_back({ i - 1,i,"X" });
	}
	Rep1(i, 102, 201) {
		v.push_back({ i,i + 1,"Y" });
	}
	rep1(i, a) {
		rep1(j, b) {
			bool ansed = false;
			rep(l, 101) {
				rep(r, 101) {
					int z = d[i][j] - l * i - r * j;
					if (z < 0)continue;
					bool f = true;
					rep1(i_, a) {
						rep1(j_, b) {
							int sum = i_ * l + j_ * r + z;
							if (sum < d[i_][j_])f = false;
						}
					}
					if (f) {
						int sta = 1 + l;
						int goa = 202 - r;
						if (!exi[sta][goa])v.push_back({ sta,goa,to_string(z) });
						exi[sta][goa] = true;
						ansed = true;
						break;
					}
				}
				if (ansed)break;
			}
			if (!ansed)valid = false;
		}
	}
	if (!valid) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" << endl;
		cout << 202 << " " << v.size() << endl;
		rep(i, v.size()) {
			cout << v[i].from << " " << v[i].to << " " << v[i].cost << endl;
		}
		cout << "1 202" << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}