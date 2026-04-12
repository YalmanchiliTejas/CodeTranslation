/*Alohomora*/
#include<bits/stdc++.h>
#define ll         long long
#define fl(i,n)    for(i=0;i<n;i++)
#define fld(i,a,b) for(i=a;i>b;i--)
#define fli(i,a,n) for(i=a;i<n;i++)
#define inp(i,a,n) for(i=0;i<n;i++) {cin>>a[i];}
#define op(i,a,n)  for(i=0;i<n;i++) {cout<<a[i]<<" ";}
#define pb         push_back
#define mp         make_pair
#define mod1        987654319 
#define speedup    ios_base::sync_with_stdio(false),cin.tie(0)
using namespace std;
ll fact(ll n){ if(n==0){return 1;}return (n*fact(n-1))%mod1;}
ll power(ll x, ll y,ll mod){ll out = 1;while (y > 0){if (y & 1) out=(out*x)%mod;y = y>>1;x = (x*x)%mod;}return out%mod;}
ll inverse(ll a){return power(a,mod1-2,mod1);}
ll gcd(ll a,ll b){if(b==0){return a;}gcd(b,a%b);}
ll a[2000000];
void sieve(){ll i,j;fli(i,2,1000001){if(a[i]==0){for(j=i*i;j<1000001;j+=i){a[j]=1;}}}}
map<ll,vector<ll> >m1;
vector<ll>v1;
bool compar(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second);
} 
ll level[1000000];
vector<ll>root;
set<ll>s1;
void factorise(long long n) 
{ 
    while (!(n%2)) 
    { 
        n >>= 1; 
        s1.insert(2);
    } 
    for (long long i=3; i<=sqrt(n); i+=2) 
    { 
        while (n%i==0) 
        { 
        	s1.insert(i);
            n=n/i; 
        } 
    } 
  	if (n>2) 
  	{
       s1.insert(n);
	}
} 
void comp()
{
	ll l,i,j,k,q,n,d,m,temp=0,sum,count=0;
	cin>>n;
	vector<ll>v1;
	fl(i,n)
	{
		cin>>j;
		v1.pb(j);
	}
	int arr[n+1];
	int arr1[n+1];
	arr[n-1]=v1[0];
	ll curr=n-1;
	ll low,high,mid,ans;
	fli(i,1,n)
	{
		low=curr;
		high=n-1;
		ans=-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(v1[i]>arr[mid])
			{
				ans=mid;
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		if(ans==-1)
		{
			arr[curr-1]=v1[i];
			curr--;
		}	
		else
		{
			arr[ans]=v1[i];
		}
	}
	cout<<n-curr<<"\n";
} 
int main()
{
	speedup;
	ll i=0,t;
	ll n;
	//cin>>t;
	t=1;
	while(t--)
	{
	 comp();
	}
}