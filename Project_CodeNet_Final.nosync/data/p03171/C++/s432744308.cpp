// Charan Sriramula

#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

const ll lg=14;
const ll N=3e3+1;
const ll INF=1e9;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define ints(n) scanf("%d",&n)
#define intp(n) printf("%d\n",n)
#define longs(n) scanf("%lld",&n)
#define longp(n) printf("%lld\n",n)

#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcount(x)
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define ms(dp,val) memset(dp,val,sizeof(dp))
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
template<typename T> T power(T x,T y,ll m){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

ll n,a[N],dp[N][N][2];

ll F(ll i,ll j,ll turn)
{
	if(i>j){return 0;}
	if(dp[i][j][turn]!=-1){return dp[i][j][turn];}
	if(turn){return dp[i][j][turn]=max(a[i]+F(i+1,j,turn^1),a[j]+F(i,j-1,turn^1));}
	else{return dp[i][j][turn]=min(-a[i]+F(i+1,j,turn^1),-a[j]+F(i,j-1,turn^1));}
}

int main()
{
	cin>>n;
	ms(dp,-1);
	for(ll i=1;i<=n;i++){cin>>a[i];}
	cout<<F(1,n,1)<<endl;
}
