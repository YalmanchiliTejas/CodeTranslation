#include<bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<vi > vvi;
typedef std::vector<vll > vvll;
typedef std::pair<int,int> ii;
typedef std::pair< ll, ll > lp;
typedef std::vector<ii> vii;
typedef std::vector<vii > vvii;

#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<"\n"
#define ff first
#define ss second
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define rep(i,n) F(i,0,n-1)
#define clr(a) (a).clear()
#define rz resize
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int  main(int argc, char const *argv[])
{
	crap;
	int n;
	cin>>n;
	vi a(n);
	in(a,n);

	sort(all(a));

	deque<int> emni;

	emni.pb(a[0]);
	int mi=1,ma=n-1;
	int r=1;
	while (sz(emni)<n)
	{
		if (r&1)
		{
			ll x=a[ma];
			ll y=(ma-1<mi)? 0 : a[ma-1];
			ma-=2;

			int f=emni.front(),b=emni.back();

			ll conf1=abs(x-f)+abs(y-b);
			ll conf2=abs(x-b)+abs(y-f);

			if (conf1 > conf2)
			{
				emni.pf(x),emni.pb(y);
			}
			else
			{
				emni.pf(y),emni.pb(x);
			}
		}
		else
		{
			ll x=a[mi];
			ll y=(mi+1>ma)? 0 : a[mi+1];
			mi+=2;

			int f=emni.front(),b=emni.back();

			ll conf1=abs(x-f)+abs(y-b);
			ll conf2=abs(x-b)+abs(y-f);

			if (conf1 > conf2)
			{
				emni.pf(x),emni.pb(y);
			}
			else
			{
				emni.pf(y),emni.pb(x);
			}
		}
		r++;
	}
	vi ans;
	for (int i : emni)
	{
		if (i)
			ans.pb(i);
	}

	

	ll val1=0;
	rep(i,n-1)
		val1+=abs(ans[i]-ans[i+1]);
	

	emni.clear();

	emni.pb(a[n-1]);
	ma=n-2,mi=0;
	r=1;
	while (sz(emni)<n)
	{
		if (r&1)
		{
			ll x=a[mi];
			ll y=(mi+1>ma)? 0 : a[mi+1];
			mi+=2;

			int f=emni.front(),b=emni.back();

			ll conf1=abs(x-f)+abs(y-b);
			ll conf2=abs(x-b)+abs(y-f);

			if (conf1 > conf2)
			{
				emni.pf(x),emni.pb(y);
			}
			else
			{
				emni.pf(y),emni.pb(x);
			}
		}
		else
		{
			ll x=a[ma];
			ll y=(ma-1<mi)? 0 : a[ma-1];
			ma-=2;

			int f=emni.front(),b=emni.back();

			ll conf1=abs(x-f)+abs(y-b);
			ll conf2=abs(x-b)+abs(y-f);

			if (conf1 > conf2)
			{
				emni.pf(x),emni.pb(y);
			}
			else
			{
				emni.pf(y),emni.pb(x);
			}
		}
		r++;
	}
	ans.clear();
	for (int i : emni)
	{
		if (i)
			ans.pb(i);
	}



	ll val2=0;
	rep(i,n-1)
		val2+=abs(ans[i]-ans[i+1]);


	cout<<max(val1,val2)<<"\n";
	return 0;
}