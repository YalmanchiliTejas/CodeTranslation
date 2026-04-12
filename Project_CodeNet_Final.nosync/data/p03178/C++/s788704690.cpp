#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mat vector<vector<int>>
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<n;i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll


auto max(auto a){auto ans=a[0];for(auto i:a)if(i>ans)ans=i;return ans;}
auto min(auto a){auto ans=a[0];for(auto i:a)if(i<ans)ans=i;return ans;}
void print(auto a){for(auto i:a)cerr<<i<<' ';cerr<<'\n';}

string k;
int d,n;
int f[10001][100],g[10001][100];

int fdp(int ind,int r)
{
	if(ind==n)
	{
		if(r==0)
			return 1;
		return 0;
	}
	if(f[ind][r]!=-1)
		return f[ind][r];
	f[ind][r]=0;
	fo(i,10)
	{
		f[ind][r]=(f[ind][r] + fdp(ind+1,((r-i)%d+d)%d))%mod;
	}
	return f[ind][r];
}

int gdp(int ind,int r)
{
	if(ind==n)
	{
		if(r==0)
			return 1;
		return 0;
	}
	if(g[ind][r]!=-1)
		return g[ind][r];
	g[ind][r]=0;
	fo(i,k[ind]-'0')
	{
		g[ind][r]=(g[ind][r] + fdp(ind+1,((r-i)%d+d)%d))%mod;
	}
	g[ind][r]=(g[ind][r] + gdp(ind+1,((r-k[ind]+'0')%d+d)%d))%mod;
	return g[ind][r];
}


signed main()
{
	fio
	cin>>k>>d;
	n=k.size();
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	cout<<((gdp(0,0)-1)%mod+mod)%mod<<'\n';
	printclock;
}