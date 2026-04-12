#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 998244353
#define inf 1000000000000000007
#define eps 0.0000000001
#define pi acosl(-1)
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll n;
ll a[66][509][509];
ll s[509];
ll t[509];
ll u[66][509];
ll v[66][509];
void print(ll x)
{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<a[x][i][j]<<' ';
		}
		cout<<endl;
	}
}
bool check(ll x)
{
	for(ll i=0;i<n;i++)
	{
		if(s[i]==0)
		{
			ll q=1;
			for(ll j=0;j<n;j++)
				q&=a[x][i][j];
			if(q!=u[x][i])
				return 1;
		}
		if(s[i]==1)
		{
			ll q=0;
			for(ll j=0;j<n;j++)
				q|=a[x][i][j];
			if(q!=u[x][i])
				return 1;
		}
		if(t[i]==0)
		{
			ll q=1;
			for(ll j=0;j<n;j++)
				q&=a[x][j][i];
			if(q!=v[x][i])
				return 1;
		}
		if(t[i]==1)
		{
			ll q=0;
			for(ll j=0;j<n;j++)
				q|=a[x][j][i];
			if(q!=v[x][i])
				return 1;
		}
	}
	return 0;
}
void fill_row(ll x)
{
	ll cnt[n];
	for(ll i=0;i<n;i++)
	{
		cnt[i]=0;
		if(t[i]==0)
		{
			for(ll j=0;j<n;j++)
			{
				if(a[x][j][i]==0)
					cnt[i]++;
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		if(u[x][i]==1)
		{
			ll f=0;
			for(ll j=0;j<n;j++)
			{
				f|=a[x][i][j];
			}
			if(f==0)
			{
				for(ll j=0;j<n;j++)
				{
					if(a[x][i][j]==0&&cnt[j]>1)
					{
						cnt[j]--;
						a[x][i][j]=1;
						break;
					}
				}
			}
		}
	}
}
void transpose(ll x)
{
	for(ll i=0;i<n;i++)
	{
		swap(s[i],t[i]);
		swap(u[x][i],v[x][i]);
		for(ll j=0;j<i;j++)
		{
			swap(a[x][i][j],a[x][j][i]);
		}
	}
}
void fill(ll x)
{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if((s[i]^u[x][i])==1)
				a[x][i][j]=u[x][i];
			if((t[j]^v[x][j])==1)
				a[x][i][j]=v[x][j];
			if(u[x][i]==v[x][j])
				a[x][i][j]=u[x][i];
		}
	}
	fill_row(x);
	transpose(x);
	fill_row(x);
	transpose(x);
}
void solve()
{
	cin>>n;
	ull x;
	for(ll i=0;i<n;i++)
		cin>>s[i];
	for(ll i=0;i<n;i++)
		cin>>t[i];
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		for(ll j=0;j<64;j++)
		{
			u[j][i]=(x%2);
			x/=2;
		}
	}
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		for(ll j=0;j<64;j++)
		{
			v[j][i]=(x%2);
			x/=2;
		}
	}
	for(ll i=0;i<64;i++)
	{
		fill(i);
		if(check(i))
		{
			cout<<-1;
			return;
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			x=0;
			ull p=1;
			for(ll k=0;k<64;k++)
			{
				if(a[k][i][j]==1)
					x+=p;
				p*=2;
			}
			cout<<x<<' ';
		}
		cout<<endl;
	}
}
int main()
{
    FAST
    #ifdef ayk_16
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
}