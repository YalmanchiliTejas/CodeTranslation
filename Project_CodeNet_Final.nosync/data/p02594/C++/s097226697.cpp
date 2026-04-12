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
#define sz(v) (int)(v).size()
#define vec(x) vector < x >
using vi = vector < int >;
using mii = map <int , int >;
using vvi = vector < vi >;
using pii = pair < int , int >;
using vpii = vector < pii >;
using int64 = long long;
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
const string yo = "Yes\n", no = "No\n";


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ur code

	int x;
	cin >> x;
	if (x < 30) cout << no;
	else cout << yo;

	return 0;
}