#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(i=0;i<n;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
ll bg=998244353;
ll power(ll x,ll y)
{
	ll ss=1;
	if(y==0)
	return ss;
	ll h=(power(x,y/2))%bg;
	h=(h*h)%bg;
	ll gg=(x*h)%bg;
	if(y%2==1)
	 return gg;
	else
	 return h;
}
ll modinv(ll k)
{
	return (power(k,bg-2))%bg;
}
ll dp[500001];
int main()
{
    ll a[3]={0},b,c,i;
    string f;
	cin>>f;
	for(i=0;i<3;i++)
	{
		a[f[i]-'A']++;
	}	   	  	  	
	if(a[0]>0 && a[1]>0)
	   cout<<"Yes";
	else
	   cout<<"No";   
    return 0;
}