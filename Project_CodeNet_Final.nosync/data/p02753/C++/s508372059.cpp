#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb emplace_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define vll vector<ll>
#define fast ios:: sync_with_stdio(false),cin.tie(0);
#define COUT cout<<fixed<<setprecision(12)
#define SET set<ll,greater<ll>>gquiz
#define ITERATOR set<ll,greater<ll>> :: iterator itr
#define V vector<ll>vector
#define sz size()
//#define A vector<pair<ll,ll>>vect
ll N=100000,M=100000;
#define B vect.push_back(make_pair(N,M));
ll MOD=1000000007;
 
ll gcd(ll a,ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
/*ll ncr(ll n,ll r)
{
	if(n==1 || r==0)
	return 1;
	if(r>n/2)
	r=n-r;
	ll ans=1;
	for(ll i=1;i<=r;i++)
	{
		ans=((ans * n )/i);
		n--;
	}
	return ans;
}*/
ll pow1(ll n,ll k,ll mm){
    if(k==0)return 1;
    if(k%2==0)return (pow1((n%mm)*(n%mm),k/2,mm))%mm;
    return ((n%mm)*(pow1((n%mm)*(n%mm),k/2,mm)%mm))%mm;
}
ll pow(ll a,ll b,ll m)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*a)%m;
		b=b/2;
		a=(a*a)%m;
	}
	return ans;
}
 
ll modinv(ll k)
{
	return pow(k,MOD-2,MOD);
}

ll ncr(ll n,ll c)
{
    ll t=1;
    c=min(c,n-c);
    for(ll i=1;i<=c;i++)
    {
     	t=(t*(n-i+1))%MOD;
        t=(t*modinv(i))%MOD;
	}
    return t;
}
int main()
{
	string s;
	cin>>s;
	ll x=0,y=0;
	for(ll i=0;i<3;i++)
	{
		if(s[i]=='A')
		x++;
		else
		y++;
	}
	if(x==3 || y==3)
	cout<<"No";
	else
	cout<<"Yes";
}