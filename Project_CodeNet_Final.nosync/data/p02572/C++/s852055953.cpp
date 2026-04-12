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
typedef pair<ll ,ll> 			pll;
typedef pair<ld,ld> 			pld;
typedef unordered_map<ll,ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5+7;
const ll 	MAX7 	= 	1e+7+7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const ll  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1000000007;

/*vll adj[MAXN];ll visit[MAXN]={};
ll dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};
*/
// <------------- Declare Variables Here ------------> //

ll T=1;
ll n,x,y,m,k,d,w,summ;
string s,t;
vll a,b;

// <------------- Implement Functions Here ----------> //

// <------------- Start of main() -------------------> //

void MAIN(ll _) {
	cin >> n;
	a = vll(n);
	b = vll(n);
	
	for(ll i=0;i<n;i++) cin>>a[i];
	
	b[n-1] = a[n-1];
	for(ll i=n-2;i>=0;i--) b[i]+=b[i+1]+a[i], b[i]%=MOD;

	ll ans = 0;
	for(ll i=0;i<n-1;i++) {
		ans += ((a[i])*(b[i+1]));
		ans%=MOD;
	}

	cout<<ans;newl;
}	

int main() {
	fastio;randomINT;
	//freopen("out_hc.txt","w+",stdout);
	//cin>>T;
	for(ll i=1;i<=T;i++) {
		MAIN(i);
	}
	return 0;
}

