//Optional FAST

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")

//Required Libraries

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

//Required namespaces

using namespace std;
using namespace __gnu_pbds;

//Required defines

#define endl '\n'

#define READ(X) cin>>X;
#define READV(X) long long X; cin>>X;
#define READAR(A,N) long long A[N]; for(long long i=0;i<N;i++) {cin>>A[i];}
#define rz(A,N) A.resize(N);
#define sz(X) (long long)(X.size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define trav(x,A) for(auto &x:A)
#define FORI(a,b,c) for(long long a=b;a<c;a++)
#define FORD(a,b,c) for(long long a=b;a>c;a--)

//Required typedefs

typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> veci;
typedef vector<long long> vecl;

//Required Constants

const long long inf=(long long)1e18;
const long long MOD=(long long)(998244353);
const long long INIT=(long long)(1e6+1);

//Required Functions

ll power(ll x,ll y) 
{ 
	if (y == 0) 
		return 1; 
	ll p = power(x, y/2) % MOD; 
	p = (p * p) % MOD; 
  
	return (y%2 == 0)? p : (x * p) % MOD; 
}
ll modInverse(ll a) 
{ 
   return power(a,MOD-2); 
   
}

//Work

int main()
{
	#ifndef ONLINE_JUDGE
	if (fopen("INPUT.txt", "r"))
	{
		freopen ("INPUT.txt" , "r" , stdin);
		//freopen ("OUTPUT.txt" , "w" , stdout);
	}
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	clock_t clk;
	clk = clock();
//-----------------------------------------------------------------------------------------------------------//

	READV(N);
	READV(S);
	pll F[3001];
	FORI(j,0,3001)
	{
		F[j].fi=0;
		F[j].se=0;
	}
	FORI(i,1,N+1)
	{
		READV(x);
		pll F1[3001];
		FORI(j,0,3001)
		{
			F1[j]={0,0};
			F1[j]=F[j];
			F1[j].fi=(F1[j].fi+F1[j].se)%MOD;
		}
		FORI(j,1,3001)
		{
			if(j+x<=3000)
			{
				F1[j+x].fi=(F1[j+x].fi+F[j].se)%MOD;
				F1[j+x].se=(F1[j+x].se+F[j].se)%MOD;
			}
		}
		F1[x].fi=(F1[x].fi+i)%MOD;
		F1[x].se=(F1[x].se+i)%MOD;
		FORI(j,0,3001)
		{
			F[j]=F1[j];
		}
	}
	cout<<F[S].fi<<endl;

//-----------------------------------------------------------------------------------------------------------//


	clk = clock() - clk;
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << endl;

	return 0;
}