#include<bits/stdc++.h>
#define fi        first
#define se        second
#define pb        push_back
#define PI        acos(-1)
#define LC(a)     ((a<<1))
#define RC(a)     ((a<<1)+1)
#define MID(a,b)  ((a+b)>>1)
#define mem(a, b) memset(a, b, sizeof(a))
#define IOS()     std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<ll,ll>   PLL;
const int INF = 0X3F3F3F3F;
const int MIN = -(1<<30);
const ll N = 2e5+7;
const ll mod = 1e9+7;
ll a[N];
ll b[N];
inline void solve()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	b[n-1] = a[n-1];
	for(int i=n-2; i>=0; i--)
		b[i] = (b[i+1]+a[i])%mod;
	ll ans = 0;
	for(int i=0;i<n-1;i++)
	ans = (ans + a[i]*b[i+1]%mod)%mod;
	cout<<ans<<endl;

}
int main()
{
	IOS();
	solve();
	return 0;
}


