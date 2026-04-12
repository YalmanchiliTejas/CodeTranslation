//author-micheal corleone
//the godfather
#include <bits/stdc++.h>
#include <set> 
#include<algorithm>
#include <set> 
#include<algorithm>
#define ll long long int
#define in(n) scanf("%lld",&n)
#define in2(a,b) scanf("%lld %lld",&a,&b)
#define out(n) printf("%lld\n",n)
#define inf 100000000000000
#define endl "\n"
#define precise(x) fixed << setprecision(x) 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
const int MOD =1000000007;
#define f(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
 
using namespace std;

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
}
 ll mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}
 //ll power(ll x, ll y) 
//{ 
  //  ll temp; 
    //if( y == 0) 
     //   return 1; 
    //temp = power(x, y/2); 
    //temp=temp%MOD;
    //if (y%2 == 0) 
     //   return (temp%MOD)*(temp%MOD); 
    //else
      //  return (x%MOD)*(temp%MOD)*(temp%MOD); 
//} 
 
 
ll ncr(ll n,ll r){if(n==1 || r==0)return 1;if(r>n/2)r=n-r;
	ll ans=1;for(ll i=1;i<=r;i++){ans=((ans * n )/i);n--;}return ans;
}
ll ncrsum(ll n,ll r, ll mod){
    if(n==1 || r==0)return 1;
  //  ll ans=1,sum=1;for(ll i=1;i<=r;i++){ans=((((ans * n)%MOD )*modinv(i,MOD))%mod);n--;sum+=ans;sum%=mod;}return sum;
}
 //diamond[2000005],ans[1000006];
 const int maxn=5e5+1000;
 ll vis[300000];
 
 
 
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     ll t;
    // cin>>t;
   
     t=1;	
     for(ll testcase=0;testcase<t;testcase++)
    {
        ll i1,i2,k,j,j1,a1,i31,i3,j2,i5,i4,i6,i7,i,m,n;
        ll x,y,z;
        ll total=0,cnt=0;
        ll flag=0;
        y=0;
        ll res,res1,ans,res2,q,sum;
        ans=0,cnt=0;
        res1=0,res=0,sum=0;
        ll flag1=0;
        ll k1,k2,k3;
        k1=1,k2=0;
        k3=0;
        ll required,days,h,w;
        //cin>>n;
        
        //for(it=mp.begin();it!=mp.end(),it++)
        //{
        //	for(int i=0;i<it->second.size();i++) cout<<it->second[i]<<" ";
		//}
		cin>>n;
		ll a[n];
	    f(i,0,n)
	    {
	    	cin>>a[i];
	    	sum=sum+a[i];
		}
		f(i,0,n)
		{
			sum-=a[i];
			ans+=(sum%MOD*a[i]%MOD)%MOD;
		}
		cout<<ans%MOD<<endl;
    }
}
	