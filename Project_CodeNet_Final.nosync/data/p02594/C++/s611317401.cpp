#include<bits/stdc++.h>
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scl1(a) scanf("%lld",&a)
#define scl2(a,b) scanf("%lld%lld",&a,&b)
#define scl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define pr1(a) printf("%d ",a)
#define pr2(a,b) printf("%d %d ",a,b)
#define pr3(a,b,c) printf("%d %d %d ",a,b,c)
#define mii map<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define mii map<int,int>
#define ll long long
#define ii pair<int,int>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define rloop(i,a,b) for(int i=(a);i>(b);i--)
#define tr(it,c) for(decltype((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
#define mod 998244353
#define mod2 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL)
 
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
	swap(a,b);
	if(b==0)
	return a;
	while((a=a%b)!=0)
	{
		swap(a,b);
	}
	return b;
}
ll modpow(ll x,int y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
		res=res*x%mod2;
		y=y>>1;
		x=x*x%mod2;
	}
	return res;
}
ll ncr(int n,int r)
{
	ll f1=1,f2=1;
	loop(i,n-r+1,n+1)
	f1=f1*i%mod;
	loop(i,1,r+1)
	f2=f2*i%mod;
	return f1*modpow(f2,mod-2)%mod;
}
int *sieve(int n)
{
	int *lpf=new int[n+1];
	for(int i=1;i<=n;i++)
	lpf[i]=i;
	int rt=(int)floor(sqrt(n))+1;
	loop(i,2,rt)
	{
		if(lpf[i]!=i)
		continue;
		for(int j=i*i;j<=n;j+=i)
		{
			if(lpf[j]==j)
			lpf[j]=i;
		}
	}
	return lpf;
}









void solve()
{
	int x;
	cin>>x;
	if(x>=30)
	cout<<"Yes";
	else
	cout<<"No";
	
}

int main()
{
	SYNC;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=1;
	//cin>>t;
	while(t--)
	{
		//cout<<"Case #"<<z+1<<": ";
		solve();
		cout<<"\n";
	}
}
