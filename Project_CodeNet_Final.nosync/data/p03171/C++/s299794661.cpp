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
ll n;
ll a[3005];
ll dp[3005][3005][2];
ll getans(ll find,ll flast,ll play)
{
if(find>flast)
{
	return 0;
}
if(dp[find][flast][play]!=-1)
{
	return dp[find][flast][play];
}
ll ans=0;
if(play==0)
{
ans=max(a[find]+getans(find+1,flast,1),a[flast]+getans(find,flast-1,1));
}
else
{
ans=min(-a[find]+getans(find+1,flast,0),-a[flast]+getans(find,flast-1,0));
}
return dp[find][flast][play]=ans;
}
int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
memset(dp,-1,sizeof(dp));
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
cout<<getans(0,n-1,0)<<endl;
}



