#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, m, y, k, z, N;
string s, t, d, c;


// <------------- Implement Functions Here ----------> //

vector<string> transpose(vector<string> a) {
	vector<string> b;
	for(ll i=0;i<m;i++) {
		c="";
		for(ll j=0;j<a.size();j++) {
			c+=a[j][i];
		}
		if(c != t) b.pb(c);
	}
	return b;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> m ;
	s = string(m,'.');

	vector<string> a,b;
	for(ll i=0;i<n;i++) {
		cin >> d;
		if(d != s) a.pb(d);
	}
	t = string(a.size(),'.');
	b = transpose(a);

	for(ll i=0;i<b[0].size();i++) {
		for(ll j=0;j<b.size();j++) {
			cout<<b[j][i];
		}
		newl;
	}
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
