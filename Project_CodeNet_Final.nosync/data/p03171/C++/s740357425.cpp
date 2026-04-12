#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(ll i = 0; i < n; i++)
#define F1(i,n) for(ll i = 1; i <= n; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = b-1; i >= a; i--)
#define FIN ios::sync_with_stdio(false);cin.tie(0);
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define all(v) v.begin(),v.end()
#define modulo(a,b) ((a%b)+b)%b
#define F first
#define S second
#define INF 1000000010
#define INFLL 1000000000000000000
#define eps 0.000000000001
#define mod 1000000007
template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//=======================//
const int maxn = 3002;
ll dp[maxn][maxn];
bool visited[maxn][maxn];
int n;
vll a;

ll hacerDP(int i, int j, int turno) {
	//Turno=0 : quiero maximizar. Turno=1 : quiero minimizar.
	if (i > j) return 0;
	if (visited[i][j]) return dp[i][j];
	ll r1 = hacerDP(i+1, j, 1-turno);
	ll r2 = hacerDP(i, j-1, 1-turno);
	if (turno==0) {r1+=a[i]; r2+=a[j]; dp[i][j] = max(r1,r2);}
	else {r1-=a[i]; r2-=a[j]; dp[i][j] = min(r1, r2);}
	visited[i][j] = true;
	return dp[i][j];
}

int main () {
	//FIN

	cin >> n;
	a = vll(n);
	F0(i,n) cin >>a[i];
	F0(i,n) F0(j,n) visited[i][j] = false;
	cout << hacerDP(0,n-1,0) << "\n";


	return 0;
}








