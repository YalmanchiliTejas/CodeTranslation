//libraries
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

//namespace
using namespace std;
using namespace __gnu_pbds;

//typedef
//typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<long long> vll;

//define
#define i(X) cin>>X;
#define ol(X) cout<<X<<endl;
#define os(X) cout<<X<<" ";
#define inpv(a,n) vector<ll> a(n); for(ll i=0;i<n;i++){cin>>a[i];}
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define line cout<<"\n";
#define pbp(a,b) push_back(make_pair(a,b));
#define iniv(A,n,p) vector<ll> A(n,p);
#define vst(A) sort(A.begin(),A.end());
#define rvst(A) sort(A.rbegin(),A.rend());
#define forin(i,a,b) for(ll i=a;i<=b;i++)
#define forde(i,a,b) for(ll i=a;i>=b;i--)
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long long inf=(long long)1e18;
long long MOD=(long long)(1e9+7);
ll mod=MOD;

ll power(ll x,ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % MOD;
    p = (p * p) % MOD;

    return (y%2 == 0)? p : (x * p) % MOD;
}

int main() 
{
	// #ifndef ONLINE_JUDGE
    //    freopen ("input.txt" , "r" , stdin);
	// 	// freopen ("OUTPUT.txt" , "w" , stdout);
	// #endif
	fio;
	ll testcase=1;
	//cin>>testcase;
	while(testcase--)
	{
		// string s,t;
		// cin>>s>>t;
		// ll len=0;
		// forde(j,t.length()-1,0)
		// {
		// 	if(s.find(t.substr(0,j))!=-1)
		// 	{
		// 		len=max(len,j);
		// 		//cout<<len<<" ";
		// 		break;
		// 	}
		// }
		// ll ans=t.length()-len;
		// cout<<ans<<endl;
		ll n;
		cin>>n;
		vector<ll> a(n);
		vector<ll> pre(n+1,0);
		ll s=0;
		forin(i,0,n-1)
		{
			cin>>a[i];
		}
		forde(i,n-1,0)
		{
			s=(a[i]+s)%mod;
			pre[i]=s;
		}
		ll ans=0;
		forin(i,0,n-2)
		{
			ans=(ans+(a[i]*pre[i+1])%mod)%mod;
		}
		cout<<ans<<endl;
	}
}