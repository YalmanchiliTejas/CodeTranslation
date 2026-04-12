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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
ll v[1 << 17];
bool used[5000][5000];
int main() {
	int n; cin >> n;
	rep(i, n) {
		cin >> v[i];
	}
	sort(v, v + n);
	int out = 1;
	rep(i, n) {
		Rep(j, i + 1, n) {
			if (used[i][j])continue;
			vector<int> s;
			int dif = v[j] - v[i];
			s.push_back(i); s.push_back(j);
			int now = v[j] + dif;
			while (true) {
				int id = lower_bound(v, v + n, now) - v;
				if (id < n&&v[id] == now) {
					s.push_back(id); now += dif;
				}
				else break;
			}
			out = max(out, (int)s.size());
			rep(k, s.size()-1) {
				used[s[k]][s[k + 1]] = true;
			}
		}
	}
	cout << out << endl;
	return 0;
}
