/************************Code by Hardik Aggarwal!!!!***********************************/


#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
/*#define endl '\n'*/
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;

typedef long long int ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;
const ll maxn=100005;
ll a[55],p[55];
ll solve(ll n,ll x)
{	
	if(x>=a[n]) return p[n];
	if(x<=0) return 0;
	ll ans=0;
	if(x>=a[n]/2+1)
		{	ans++;
			ans+=solve(n-1,x-(a[n]/2+1));
		}
	ans+=solve(n-1,x-1);
	return ans;

}
int main()
{
	

/*	ll t;
	cin>>t;
	while(t--)
	{	
		string s1,s2;
		cin>>s1>>s2;

		ll pos,ans;
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		
			for(ll i=0;i<s2.size();i++)
			{
				if(s2[i]=='1')
				{
					pos=i;
					break;
				}
			}

			for(ll i=pos;i<s1.size();i++)
			{
				if(s1[i]=='1')
					{ans=i-pos;break;}
				
			}
		


		cout<<ans<<endl;

	}

*/


	ll n,x;
	cin>>n>>x;
	a[0]=1;
	p[0]=1;

	for(ll i=1;i<=n;i++)
	{
		a[i]=2*a[i-1]+3;
		p[i]=2*p[i-1]+1;
	}

	ll ans=solve(n,x);
	cout<<ans;






}
	