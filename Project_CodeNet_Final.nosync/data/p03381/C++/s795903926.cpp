#include <bits/stdc++.h>
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define MOD 1000000007
#define DOMOD(d) if ((d) >= MOD) d %= MOD;
#define DONEGMOD(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
 
#define inp(a) scanf("%d", &a)
#define inp2(a,b) scanf("%d %d", &a, &b)
#define inp3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define inp4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
 
#define inpl(a) scanf("%lld", &a)
#define inpl2(a,b) scanf("%lld %lld", &a, &b)
#define inpl3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define inpl4(a,b,c,d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define mset(a,val) memset(a,val,sizeof(a))
#define printv(v) for (int i=0;i<(int) v.size(); i++) cout<<v[i]<<" " 
#define MAX 100005
using namespace std ;
typedef long long int ll ;
typedef pair<int,int> pii ;
typedef pair<long long , long long > pll ;
typedef pair<int,pii> pipi ;
typedef pair<int,pair<int,string>> piis ;
typedef pair<ll,string> pls ;
typedef pair<ll,pll> plpl ;



int main()
{
	#ifdef DIRI
		//freopen("inp.txt","r",stdin) ;
	#endif
	
	time_t start = clock() ;
	
	int n ; cin>>n ;
	
	int arr[n+1] ;
	
	vector<int> v ; v.pb(-1) ;
	
	for (int i=1;i<=n;i++)
	{
		cin>>arr[i] ;
		v.pb(arr[i]) ;
	}
	
	sort(all(v)) ;
	
	map<int,int> d ;
	
	for (int i=1;i<(int) v.size() ; i++)
	{
		d[v[i]] = i ;
	}
	
	int pos, pos2 ;
	
	for (int i=1;i<=n;i++)
	{
		pos = d[arr[i]] ;
		pos2 = (n/2) ;
		
		if (pos > pos2)
		{
			cout<<v[pos2]<<endl ;
		}else 
		{
			cout<<v[pos2 + 1]<<endl ;
		}
		
	}
		
	time_t end = clock() ;
	
	double tt = (end - start) / CLOCKS_PER_SEC ;
	cerr<<fixed<<setprecision(5)<<tt<<endl ;
	
    return 0 ;
}
