#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;

const long double PI = acos(-1);
const long long MOD = 1000000000 +7;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}

ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}

ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}

int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}

/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

const int N = 200000+5;

int n;
int a[N];
ll prefix[N];
ll suffix[N];
int prefmin[N];
int suffmin[N];
ll memo[N][3][3];
bool vis[N][3][3];

ll DP(int pos, int used, int last){
	if(pos >= n+1) return used? 0LL : -1LL<<50;
	if(vis[pos][used][last]) return memo[pos][used][last];
	ll ans = LLONG_MIN;
	if(used){
		if(last) ans = a[pos+1] + DP(pos+2, used, 1);
		else ans = max(a[pos] + DP(pos+2, used, 0), a[pos+1] + DP(pos+2, used, 1));
	}
	else{
		if(last){
			ans = max(ans, a[pos+1] + DP(pos+2, used, 1));
			ans = max(ans, DP(pos + 1, 1, 0));
		}
		else{
			ans = max(a[pos] + DP(pos+2, used, 0), a[pos+1] + DP(pos+2, used, 1));
			ans = max(ans, DP(pos + 1, 1, 0));
		}
	}
	vis[pos][used][last] = true;
	return memo[pos][used][last] = ans;
}

int main(){
	ri(n);
	for(int i=1; i<=n; i++){
		ri(a[i]);
	}
	ll ans = LLONG_MIN;
	if(n & 1){
		ans = DP(1,0,0);
	}
	else{
		ans = max(a[1] + DP(3, 1, 0), a[2] + DP(3, 1, 1));
	}
	cout << ans << endl;
	return 0;
}
