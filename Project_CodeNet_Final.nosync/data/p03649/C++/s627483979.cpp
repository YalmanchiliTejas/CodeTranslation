#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vl a(n);
	rep(i,0,n) {
		cin >> a[i];
	}
	ll ret = 0;
	rep(iter,0,10000) {
		vl p(n);
		rep(i,0,n) {
			p[i] = a[i]/n;
			a[i] = a[i]%n;
		}
		ll total = 0;
		rep(i,0,n) {
			total += p[i];
		}
		rep(i,0,n) {
			a[i] += total-p[i];
		}
		ret += total;
	}
	cout << ret << '\n';
	return 0;
}
