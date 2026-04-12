#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define repLL(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define perLL(i,a,b) for(LL i=(LL)a;i>(LL)b;i--)
#define debug5(a,b,c,d,e) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<" "<<#d<<": "<<d<<" "<<#e<<": "<<e<<endl;
#define debug4(a,b,c,d)  cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<" "<<#d<<": "<<d<<endl;
#define debug3(a,b,c) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<" "<<#c<<": "<<c<<endl;
#define debug2(a,b) cerr<<#a<<": "<<a<<" "<<#b<<": "<<b<<endl;
#define debug(a) cerr<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define fi first
#define se second
#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long double LD;
typedef pair<LD,LD> PLD;
typedef vector<LD> VLD;
typedef vector<PLD> VPLD;

template<typename T>
void dbg(T a)
{
      #ifdef LOCAL
            cerr<<a<<"\n";
      #endif
}

template<typename T, typename ...Arg>
void dbg(T a,Arg ...arg)
{
      #ifdef LOCAL
            cerr<<a<<" ";
            dbg(arg...);
      #endif
}

const int maxn=(1e6)+7;
const int inf=(1e9)+7;
const LL LLinf=(1e18)+7;
const LD eps=1e-9;
const LL mod=1e9+7;

// ***************************** CODE ***************************** //


LL moz[maxn][4];
LL odl[maxn][4];

vector<pair<int, LL> > wek[maxn];

vector<pair<int , pair<int ,int > > > kraw, krawedzie;
VI wierz;

int n, m;

priority_queue<pair<LL, int> > q;

inline void dij(int st, int mask)
{
	for(int i = 0 ;i <= n;i++)
		odl[i][mask] = LLinf;
	odl[st][mask] = 0;
	moz[st][mask] = 1;
	q.push({0, st});
	while(q.size())
	{
		int a = q.top().se;
		if(odl[a][mask] != -q.top().fi)
		{
			q.pop();
			continue;
		}
		// cout<<a<<" "<<odl[a][mask]<<" ";
		q.pop();
		for(auto s : wek[a])
		{
			if(odl[s.fi][mask] > odl[a][mask] + s.se)
			{
				odl[s.fi][mask] = odl[a][mask] + s.se;
				q.push({-odl[s.fi][mask], s.fi});
			}
			else
				if(odl[s.fi][mask] == odl[a][mask] - s.se)
				{
					moz[a][mask] += moz[s.fi][mask];
					moz[a][mask] %= mod;
				}
		}
		// cout<<moz[a][mask]<<endl;
	}
}

int main()
{
      _upgrade
	cin>>n>>m;
	int start, meta;
	cin>>start>>meta;
	for(int i = 0 ;i < m;i++)
	{
		int a, b;
		LL c;
		cin>>a>>b>>c;
		wek[a].pb({b, c});
		wek[b].pb({a, c});
		krawedzie.pb({c,{a, b}});
		krawedzie.pb({c,{b, a}});
	}
	dij(start, 0);
	dij(meta, 1);
	LL dlu = odl[meta][0];
	if(dlu % 2 == 0)
	{
		for(int i = 1; i <= n;i++)
			if(odl[i][0] == odl[i][1] && 2 * odl[i][1] == dlu)
				wierz.pb(i);
	}
	for(auto s : krawedzie)
		if(s.fi + odl[s.se.fi][0] + odl[s.se.se][1] == dlu && odl[s.se.fi][0] * 2LL < dlu && odl[s.se.se][1] * 2LL < dlu)
			kraw.pb(s);
	LL res = 0LL;
	LL lscie = 0LL;
	for(auto s : wierz)
	{
		// dbg(s);
		LL cnt = (moz[s][0] * moz[s][1]) % mod;
		lscie += cnt;
		lscie %= mod;
		res -= (cnt * cnt) % mod;
		res %= mod;
	}

	for(auto s : kraw)
	{
		// dbg(s.se.fi, s.se.se);
		LL cnt = (moz[s.se.fi][0] * moz[s.se.se][1]) % mod;
		lscie += cnt;
		lscie %= mod;
		res -= (cnt * cnt ) % mod;
		res = (res % mod + mod ) % mod;
	}


	// dbg(lscie);
	lscie %= mod;
	lscie *= lscie;
	lscie %= mod;
	res %= mod;
	res += lscie;
	res %= mod;
	res += mod;
	res %= mod;
	res = (res % mod + mod ) % mod;
	cout<<res;
      return 0;
}
