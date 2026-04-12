#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef long double td;
typedef vector<td> vd;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = ll(a); i < (ll)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
int MAXN = 500005;
int INF = (int)(1e9+7);
ll m = (ll)(1000000007);

ll dp[10005][105][2];
string pal;

ll funcion(int pos, int resto, int caso, int modu)
{	
	if(pos==-1 && resto == 0) return 1;
	else if(pos==-1) return 0;
	
	//DBG(pos); DBG(resto); DBG(caso); DBG(modu);
	
	if(dp[pos][resto][caso]!=-1) return dp[pos][resto][caso];
	
	dp[pos][resto][caso]=0;	
	int cota = (int)(pal[pos]-'0');
	
	//DBG(cota); RAYA;
	
	if(caso == 0)
	{
		// caso = 0 significa imponer limites
		forn(i,cota)
		{
			dp[pos][resto][caso]+=funcion(pos-1,(resto+modu-i%modu)%modu,1,modu);
			//DBG(pos-1); DBG((resto+modu-i)%modu); RAYA;
			dp[pos][resto][caso]%=m;
		}
		dp[pos][resto][caso]+=funcion(pos-1,(resto+modu-cota%modu)%modu,0,modu);
		dp[pos][resto][caso]%=m;
	}
	else
	{
		forn(i,10)
		{
			dp[pos][resto][caso]+=funcion(pos-1,(resto+modu-i%modu)%modu,1,modu);
			dp[pos][resto][caso]%=m;
		}
	}
	
	return dp[pos][resto][caso];
	
}
 
int main()
{ 	
	FIN;
	#ifdef input
		//freopen("T1.txt", "r", stdin);
	#endif
	
	int k;
	cin >> pal >> k;
	reverse(all(pal));
	forn(i,10005) forn(j,105) forn(t,2) dp[i][j][t]=-1;
	ll ans = funcion((int)(pal.size()-1),0,0,k); 
	ans+=m-1;
	cout << ans%m << "\n";
	
    return 0;
}

