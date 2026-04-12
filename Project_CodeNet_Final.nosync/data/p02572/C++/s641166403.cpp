#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define F first
#define S second
//#define biGinf 9e+18
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inpv(v) for(auto &x:v) cin>>x
#define otpv(v) for(auto &x:v) cout<<x<<nwl
#define otpv2(v) for(auto &x:v) cout<<x<<" "
#define CASES int tt;cin>>tt; while(tt--)
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,r,n) for(int i=r; i<=n; i++)
#define forj(j,n) for(int j=n; j>=0; j--)
#define forx(x,v) for(auto &x:v)
#define sz(v) (int)(v).size()
#define rz(n) resize(n)
#define vec(x) vector < x >
using int64 = long long;
using vi = vector < int >;
using vi64 = vector < int64 >;
using mii = map <int , int >;
using vvi = vector < vi >;
using pii = pair < int , int >;
using vpii = vector < pii >;
const int inf = 2e9 + 7;
const char nwl = '\n';
const int mxx = 1e6 + 3;
int64 sumV(vi &v) {
	int64 s = 0;
	for (int x : v) {
		s += (int64)x;
	}
	return s;
}
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
//const int64 biGinf = 9e+18;
//const string yo = "Yes\n", no = "No\n";
int64 mod = (int64)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ur code
	int64 n;
	cin >> n;
	vec(int64) v(n);
	inpv(v);
	int64 s = 0;
	vec(int64) sm(n);
	sm[0] = v[0] % mod;
	for1(i, n - 1) {
		sm[i] = (sm[i - 1] + v[i]) % mod;
	}
	for1(i, n - 1) {
		s = (s + (sm[i - 1] % mod * v[i] % mod) % mod) % mod;
	}
	cout << s;






	return 0;
}
