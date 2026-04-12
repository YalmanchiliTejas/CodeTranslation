#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

int dp[2][2][333333]; //# of sols to a_1+b_1+...+a_n=K in restricted range
int S[2][2][2][333333];
const int INF = int(1e9);

int ss(int parity, int id, int lascolor, int pos)
{
	while(pos>=0&&((pos+parity)%2!=0)) pos--;
	if(pos<0) return 0;
	return S[parity][id][lascolor][pos];
}


int sum(int id, int lascolor, int parity, int l, int r)
{
	return add(ss(parity,id,lascolor,r),MOD-ss(parity,id,lascolor,l-1));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(234567);
	int n,m; cin>>n;
	int mx[2] = {INF,INF};
	int pr[2] = {1,1};
	//cin>>mx[0];
	
	cin>>m;
	string s; cin>>s;
	vector<int> runs;
	int currun=1;
	for(int i=1;i<m;i++)
	{
		if(s[i]==s[i-1]) currun++;
		else
		{
			runs.pb(currun); currun=1;
		}
	}
	runs.pb(currun);
	for(int i=0;i+1<runs.size();i++)
	{
		if(i==0||runs[i]%2==1) mx[i%2]=min(mx[i%2],runs[i]+1); 
		pr[i%2]=0;
	}
	
	//cerr<<mx[0]<<' '<<mx[1]<<' '<<pr[0]<<' '<<pr[1]<<'\n';
	//mono color
	int ans=0;
	if(mx[0]==INF&&mx[1]==INF){ans++;}
	mx[1]=1;
	//exist at least 2 colors
	/*
	{
		int cnt=0;
		for(int i=1;i+1<(1<<n);i++)
		{
			int M[2]={0,0};
			int exeven[2]={0,0};
			for(int j=0;j<n;j++)
			{
				int cur=j;
				int vv=0;
				if(i&(1<<j)) vv=1;
				int r=1;
				while(1)
				{
					if(r>=n){break;}
					cur++;
					cur%=n;
					int v=0;
					if(i&(1<<cur)) v=1;
					if(vv==v) r++;
					else break;
				}
				M[vv]=max(M[vv],r);
				bool isrun=false;
				int tmp = (j+n-1)%n;
				int xx=0;
				if(i&(1<<tmp)) xx=1;
				if(xx!=vv){isrun=1;}
				if(r%2==0&&isrun) exeven[vv]=1;
			}
			if(M[0]>mx[0]||M[1]>mx[1]) continue;
			if(exeven[0])
			{
				if(!pr[0]) continue;
			}
			if(exeven[1])
			{
				if(!pr[1]) continue;
			}
			//cerr<<M[0]<<' '<<M[1]<<' '<<exeven[0]<<' '<<exeven[1]<<'\n';
			cnt++;
		}
		cerr<<"CNT : "<<cnt<<'\n';
	}
	*/
	for(int i=0;i<2;i++)
	{
		//start with color i
		for(int j=1;j<=min(n,mx[i]);j++)
		{
			if(j%2==0)
			{
				if(!pr[i]) continue;
			}
			dp[i][i][j]=1;
		}
		for(int j=1;j<=n;j++)
		{
			//push dp
			for(int k=0;k<2;k++)
			{
				dp[i][k][j] = add(dp[i][k][j], sum(i,k^1,(j+1)&1,j-mx[k],j-1));
				if(pr[k]) dp[i][k][j] = add(dp[i][k][j], sum(i,k^1,j&1,j-mx[k],j-1));
				//cerr<<i<<' '<<k<<' '<<j<<' '<<dp[i][k][j]<<'\n';
			}
			for(int k=0;k<2;k++)
			{
				S[j%2][i][k][j]=dp[i][k][j];
				if(j-2>=0) S[j%2][i][k][j]=add(S[j%2][i][k][j],S[j%2][i][k][j-2]);
			}
		}
	}
	for(int c=0;c<2;c++)
	{
		for(int run=1;run<=min(n,mx[c]);run++)
		{
			if(run%2==0)
			{
				if(!pr[c]) continue;
			}
			int val = dp[c^1][c^1][n-run];
			//cerr<<c<<' '<<run<<' '<<val<<'\n';
			ans=add(ans,mult(run,val));
		}
	}
	cout<<ans<<'\n';
}
