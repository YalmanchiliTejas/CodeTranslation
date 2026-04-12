#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x,y) (lower_bound(all(x),y)-x.begin())
#define ubd(x,y) (upper_bound(all(x),y)-x.begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

typedef unsigned long long ll; 
typedef long double ld;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
typedef pair<ll,ll>pi; typedef pair<ll,pi>spi; typedef pair<pi,pi>dpi;

#define LLINF ((long long)1e18)
#define INF int(1e9+1e6)
#define MAXN (506)
ll n;
ll S[MAXN], T[MAXN], U[MAXN], V[MAXN], UU[MAXN], VV[MAXN], ans[MAXN][MAXN];
bool grid[MAXN][MAXN];
bool or1[MAXN], and0[MAXN];
bool chk(ll j,string x){
	if(x=="and0") return T[j] == 0 && V[j] == 0;
	if(x=="and1") return T[j] == 0 && V[j] == 1;
	if(x=="or0") return T[j] == 1 && V[j] == 0;
	if(x=="or1") return T[j] == 1 && V[j] == 1;
	assert(0);
}
void solve(){
	bool ga1=0, go0=0;
	FOR(j,0,n-1) ga1 |= chk(j, "and1"), go0 |= chk(j, "or0"), or1[j] = chk(j, "or1"), and0[j] = chk(j, "and0");
	FOR(i,0,n-1) {
		if(S[i]==0&&U[i]==0) { // AND 0
			bool can = 0;
			FOR(j,0,n-1) if(!chk(j,"and1")) can=1;
			if(!can) {
				cout<<"-1\n";
				exit(0);
			}
			ll fix = -1;
			FOR(j,0,n-1) if(!or1[j] && !chk(j, "and1")) {
				fix = j;
			}
			if(fix == -1) FOR(j,0,n-1) if(or1[j]) fix=j;
			assert(~fix);
			FOR(j,0,n-1) if(j==fix || chk(j,"or0") || and0[j]) {
				if(and0[j]) and0[j]=0;
			}else{
				grid[i][j]=1;
				if(or1[j]) or1[j]=0;
			}
		}else if(S[i]==0&&U[i]==1){ // AND 1
			if(go0){
				cout<<"-1\n";
				exit(0);
			}
			FOR(j,0,n-1) grid[i][j]=1, or1[j]=0;
		}else if(S[i]==1&&U[i]==0) { // OR 0
			if(ga1){
				cout<<"-1\n";
				exit(0);
			}
			// all 0
			FOR(j,0,n-1) and0[j]=0;
		}else if(S[i]==1&&U[i]==1) { // OR 1
			bool can=0;
			FOR(j,0,n-1) if(!chk(j, "or0")) can=1;
			if(!can) {
				cout<<"-1\n";
				exit(0);
			}
			ll fix = -1;
			FOR(j,0,n-1) if(!and0[j] && !chk(j, "or0")) {
				fix = j;
			}
			if(fix == -1) FOR(j,0,n-1) if(and0[j]) fix=j;
			assert(~fix);
			FOR(j,0,n-1) if(j == fix || or1[j] || chk(j, "and1")) {
				if(or1[j]) or1[j]=0;
				grid[i][j]=1;
			}else {
				if(and0[j]) and0[j]=0;
			}
		} else exit(0);
	}
	FOR(j,0,n-1) if(and0[j] || or1[j]) {
		cout<<"-1\n";
		exit(0);
	}
}
int main(){
	FAST
	cin>>n;
	FOR(i,0,n-1) cin>>S[i]; FOR(i,0,n-1) cin>>T[i]; FOR(i,0,n-1) cin>>UU[i]; FOR(i,0,n-1) cin>>VV[i];
	FOR(i,0,63){
		mmst(grid,0), mmst(or1,0), mmst(and0,0);
		FOR(j,0,n-1) U[j] = ((1ll<<i)&UU[j]) ? 1 : 0;
		FOR(j,0,n-1) V[j] = ((1ll<<i)&VV[j]) ? 1 : 0;
		solve();
		FOR(j,0,n-1) FOR(k,0,n-1) if(grid[j][k]) ans[j][k]|=1ll<<i;
	}
	FOR(i,0,n-1) FOR(j,0,n-1) cout<<ans[i][j]<<" \n"[j==n-1];
}
