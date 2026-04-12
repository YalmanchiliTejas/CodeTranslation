#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD 1000000007
#define PI 3.1415926535897932384

template <class T>ostream &operator<<(std::ostream &o, const vector<T> &v)
{
	rep(i, v.size()) {
		o << (i > 0 ? " " : "") << v[i];
	}
	return o;
}

int main() {
	int n;
	ll in, sum = 0, ans = 0;
	vector<ll> v;
	cin >> n;
	rep(i, n) {
		cin >> in;
		v.push_back(in);
	}
	while (1) {
		sum = 0;
		vector<ll> vv;
		rep(i, n) {
			sum += ((v[i] + n) / n - 1 );
			vv.push_back((v[i] + n) / n - 1);
			v[i] %= n;
		}
		rep(i, n) {
			v[i] += (sum-(vv[i]));
		}
		if (sum == 0) {
			cout << ans << endl;
			return 0;
		}
		ans += sum;
	}
}
