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
#define COUT cout<<fixed<<setprecision(9)
#define SET set<ll,greater<ll>>gquiz
#define ITERATOR set<ll,greater<ll>> :: iterator itr
#define V vector<ll>vector
#define sz size()
#define A vector<pair<ll,ll>>vect
ll N=100000,M=100000;
#define B vect.push_back(make_pair(N,M));
 
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
ll pow1(ll n,ll k,ll mm){
    if(k==0)return 1;
    if(k%2==0)return (pow1((n%mm)*(n%mm),k/2,mm))%mm;
    return ((n%mm)*(pow1((n%mm)*(n%mm),k/2,mm)%mm))%mm;
}
ll pow2(ll n,ll k){ll ans=1;
	while(k>0){
        if(k%2==1)ans=ans*n;n=n*n;k/=2;
    }return ans;
}
ll ncr(ll n,ll r){if(n==1 || r==0)return 1;if(r>n/2)r=n-r;
	ll ans=1;for(ll i=1;i<=r;i++){ans=((ans * n )/i);n--;}return ans;
}
ll ncrsum(ll n,ll r, ll mod){
	if(n==1 || r==0)return 1;
	ll ans=1,sum=1;for(ll i=1;i<=r;i++){ans=(((ans * n )/i)%mod);n--;sum+=ans;sum%=mod;}return sum;
}
bool isprime(ll n){if(n==1 || (n!=2 && n%2==0))return false; if(n==2)return true; 
		for(ll i=3;i<=sqrt(n);i+=2)if(n%i==0)return false; return true; }
		
vll factor(ll n){
	vll ans;
	if(n>0)ans.pb(1);if(n==2)ans.pb(2);
	for(ll i=2;i*i<=n;i++){if(n%i==0){ans.pb(i);if(n/i!=i)ans.pb(n/i);}}if(n>2)ans.pb(n);
	return ans;
}
ll numoffactor(ll n){ return factor(n).sz;}
ll gcd(ll a,ll b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b%a, a); 
} 
 
int main()
{
	ll n,m,k;
	string s;
	cin>>n>>m;
	if(n==m)
	cout<<"Yes";
	else
	cout<<"No";
}