
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
#define N 1000000007 // prime modulo value 

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	5e5;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

vll adj[MAXN];ll vis[MAXN]={};
/*
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};
*/
// <------------- Declare Variables Here ------------> //



ll T = 1;
ll n, x, k, m, r, sum = 0;
string s;
ll lvl[MAXN],par[MAXN];
ll dp[MAXN];
ll maxl;

struct Comparator
{
    bool operator() (const std::pair<ll, ll>& lhs,
                     const std::pair<ll, ll>& rhs) const
    {
      if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
      else
        return lhs.first > rhs.first;
    }
};

set<pll,Comparator> val;

// <------------- Implement Functions Here ----------> //

void dfs(ll p=1, ll lv = 0,ll pp=1) {
	vis[p] = 1;
	par[p] = pp;
	lvl[lv]++;
	val.insert({lv,p});
	maxl = max(maxl,lv);
	ll cnt = 0;
	for(auto it : adj[p]) {
		if(!vis[it]) {
			cnt = 1;
			dfs(it,lv+1,p);
		}
	}
	if(cnt == 0) lvl[lv]--;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> s;
	if(s[0]!=s[1] | s[1] != s[2]) cout<<"Yes\n";
	else cout<<"No\n";
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
