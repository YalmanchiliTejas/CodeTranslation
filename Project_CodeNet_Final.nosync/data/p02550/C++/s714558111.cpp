#include<bits/stdc++.h>
#include<cmath>
#define SZ(x) ((int)x.size())
#include<vector>
#include<set>
#include<map>
#define ll long long
#define lli long long int
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#include<string>
#include<cctype>
#include<queue>
#define ii pair<int,int>
#include <sstream>
#define lli long long int
#define pairs pair<int,int>
#define mod 1000000007
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
ll pows(ll a,ll n,ll m)
{
	ll res=1;
	while(n)
	{
	if(n%2!=0)
	{
		res=(res*a)%m;
		n--;
		}
		else
		{
			a=(a*a)%m;
			n=n/2;
			}	
	}
	return res%m;
}
ll  gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else 
	return gcd(b,a%b);
}
bool isprime(ll n)
{
	if(n==1)
	{
		return false;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
bool istrue(string s)
{
	int i=0;
	int j=s.size()-1;
	while(i<j)
	{
	if(s[i]==s[j])
	{
		i++;
		j--;
		}
		else
		{
			return false;
			}	
	}
	return true;
}

int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
ll n,x,m;
cin>>n>>x>>m;
ll val=0;
ll ar[100011];
memset(ar,-1,sizeof(ar));
vector<ll>vi;
while(ar[x]==-1)
{
	vi.pb(x);
	ar[x]=val;
	val++;
	x=pows(x,2,m);
}
ll tot=0;
for(ll i=0;i<val;i++)
{
tot+=vi[i];	
}
if(n<=val)
{
	ll df=0;
	for(ll i=0;i<n;i++)
	{
		df=df+vi[i];
	}
	cout<<df<<endl;
	return 0;
}
ll rep=val-ar[x];
ll c=n-val;
ll rem=c/rep;
ll mde=c%rep;
ll sum=0;
for(ll i=ar[x];i<vi.size();i++)
{
	sum=sum+vi[i];
}
ll dl=0;
for(ll i=0;i<mde;i++)
{
	dl=dl+vi[i+ar[x]];
}
ll ans=tot+(sum*rem)+(dl);
cout<<ans<<endl;
}



 