#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,x,z) for(int i=x;i<z;i++)
#define debug(x) cout<<"DEBUG------> "<<x<<endl
#define endl "\n"
#define srt(v) sort(v.begin(), v.end())
int main()
{
	int t;
	std::vector<ll> v,v1;
	cin>>t;
	f(i,0,t)
	{
		ll a;
		cin>>a;
		v.pb(a);
		if(i==0)
		{
			v1.pb(a%1000000007);
		}
		else
		{
		    ll te=(v1[i-1]%1000000007)+(a%1000000007)%1000000007;
			v1.pb(te);
		}
	}
	int j=t-1;
	ll  sum=0;
	for(j=t-1;j>=1;j--)
	{
		sum=(sum%1000000007)+(v1[j-1]*v[j])%1000000007;
		sum=sum%1000000007;
	}
	cout<<sum;
   return 0;
}
