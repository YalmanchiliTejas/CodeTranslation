#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi; 
typedef vector<pi> vpi;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rsz resize
#define bk back()
#define pb push_back
#define ins insert
#define del erase
#define inf INT_MAX

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);
mt19937 rng; // or mt19937_64
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << h; if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a = 1 ;
	while(a--)
	{
		ll n;
		cin >> n;
		ll arr[n];
		F0R(i,n)
		{
			cin >>  arr[i];
			arr[i] = arr[i]%MOD ;
		}
		ll pre[n];
		pre[0]=arr[0]%MOD;
		ll ans = 0 ;
		FOR(i,1,n)
		{
			pre[i]=(pre[i-1]+arr[i])%MOD;
			ans+=(arr[i]*pre[i-1])%MOD;
			ans%=MOD;
		}
		cout << ans << endl;
		
		
			
		
	}	
}
