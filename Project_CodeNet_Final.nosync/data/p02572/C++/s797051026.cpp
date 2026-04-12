//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define sci(n)	     scanf("%d",&n)
#define scii(n,m)    scanf("%d%d",&n,&m)
#define scl(n)       scanf("%lld",&n)
#define scll(n,m)    scanf("%lld%lld",&n,&m)
#define pii          pair<int,int>
#define pll 	     pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1e9+7
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case		 int t,cas=1;cin>>t;while(t--)
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define rev(i,n,a)   for(int i=n;i>=a;i--)

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

template<class T> void ckmin(T& a, const T& b) {
    a= b < a? b:a;
}
template<class T> void ckmax(T& a, const T& b) {
    a= b > a? b:a;
}

template<class T> void read(T& a) {
    std::cin>>a;
}

template<class T> void read(T& a, T& b) {
    std::cin>>a>>b;
}
template<class T> void read(T& a,T& b, T& c) {
    std::cin>>a>>b>>c;
}

template<class T> void read(T& ara, int sidx,  int eidx) {
    for(int i=sidx; i<eidx; i++)
        std::cin>>ara[i];
}




using namespace std;
using namespace __gnu_pbds;

const int maxn=500;
const int inf = INT_MAX;


void solve()
{
	ll n;
	cin>>n;
    vector<ll>v(n),pr(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
    
    pr[n-1]=v[n-1];
    ll mod=1e9+7;
    for(int i=n-2;i>=0;i--)
    {
		pr[i]=v[i]+pr[i+1];
		pr[i]%=mod;
	}
	
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{
		ans+=(v[i]*pr[i+1])%mod;
		ans%=mod;
	}
	
	cout<<ans<<endl;
	
}



int main()
{
	fast_cin;
	//case
	{
		solve();
		
	}
   
    return 0;
}
