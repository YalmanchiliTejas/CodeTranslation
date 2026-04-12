#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long long
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define ar array 
using namespace std;
ll a[100005];

int main(){
  ll n,x,m;
  cin>>n>>x>>m;
  map<ll,ll> help;
  help[x]=1;
  ll ans=x;
  ll len=n-1;
  ll c=1;
  a[1]=x;
  while(len){
  	
  	x=(x*x)%m;
  	c++;
  	if(help[x]){
  		break;
	}
	else{
		
		help[x]=c;
		a[c]=x;
		len--;
		ans+=x;
	}
  }
  
  if(len){
  
  ll cyc_len=c-help[x];
  ll sum=0;
  ll part_sum=len%cyc_len;
  ll no_time=len/cyc_len;
  
  ll st=help[x];
  ll en=c-1;
  
  ll su=0;
  
  for(ll i=st;i<=en;i++)su+=a[i];
  
  ans+=su*no_time;
  
  for(ll i=st;i<st+part_sum;i++)ans+=a[i];
  }
  
  cout<<ans<<endl;
  
  
  
  
  
  
  
  
    
    
    
    
    
    
	
   
}
  