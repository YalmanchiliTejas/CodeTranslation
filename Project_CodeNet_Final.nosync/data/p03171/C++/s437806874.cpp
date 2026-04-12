#include "bits/stdc++.h"
using namespace std;
/////////////////// TYPES & MACROS ///////////////////////////////
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define vv vector
#define exist(s,e) (s.find(e)!=s.end())
#define sz(x) ((int)(x).size())
#define int ll
#define el '\n'
typedef long long ll; typedef long double ld; typedef double dd;typedef vector<int> vi; typedef pair<int, int> pii;typedef pair<ll,ll> pll;
const ll INFLL=(ll)4e18, MOD=1e9+7; const int INF=0x3f6f6f6f;
//////////////////// DEBUG /////////////////////////////////////////
#define D(x) cerr<<#x<<" is:\t"<<x<<'\n';
#define DD(x,y) cerr<<'('<<#x<<','<<#y<<") are:\t"<<x<<' '<<y<<'\n';
#define DDD(x,y,z) cerr<<'('<<#x<<','<<#y<<','<<#z<<") are:\t"<<x<<' '<<y<<' '<<z<<'\n';
/////////////////// VARIABLES & FUNCTIONS//////////////////////////
vv<vv<int>> adj; vi vis, color, level; int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1},dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};
inline ll mexp(ll x,ll n,ll m=MOD){ll res=1;x%=m;while(n){if(n&1)res=(res*x)%m;n>>=1;x=(x*x)%m;}return res;}
inline ll gcd(ll a, ll b){while (a>0 && b>0){if(a>b)a%=b;else b%=a;}return a+b;}


const int NN=3e3+10;
ll psum[NN], a[NN], memo[NN][NN];
ll dp(int l, int r){
	if(l==r) return a[l];
	else if(memo[l][r]!=-1) return memo[l][r];

	ll& ret=memo[l][r];
	ret=max(a[l]+psum[r+1]-psum[l+1]-dp(l+1, r), a[r]+psum[r]-psum[l]-dp(l,r-1));
	return  ret;
}
///////////////////// MAIN STARTS //////////////////////////////////
int32_t main(void){
ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
cout<<fixed;cerr<<fixed; cout<<setprecision(10); cerr<<setprecision(3);
mt19937 genr(chrono::high_resolution_clock::now().time_since_epoch().count());

memset(memo,-1,sizeof(memo));
int n; cin>>n;
for(int i=0;i<n;++i) cin>>a[i];
psum[0]=0;
for(int i=1;i<=n;++i) psum[i]=psum[i-1]+a[i-1];
cout<<2*dp(0,n-1)-psum[n]<<el;




return 0;
}
