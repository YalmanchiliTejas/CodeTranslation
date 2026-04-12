#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include<string.h>
#define pi 3.1415926535897932384626433832795028841971
#define fastttt std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
#define str_max_len 4294967295
#define mod 1000000007
#define max_ll LLONG_MAX
#define min_ll LLONG_MIN
#define cps CLOCKS_PER_SEC
#define pb push_back
#define fi first
#define se second
#define in insert
#define m_p make_pair
#define fo(i,n) for(ll i=0;i<n;i++)
#define fo1(i,n) for(ll i=1;i<=n;i++)
#define vii vector <pair<int,int>> 
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);} 
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
ll maximum(ll a[],ll n)
{
	ll max1=min_ll;
	fo(i,n)
	{
		max1=max(max1,a[i]);
	}
	return max1;
}
ll minimum(ll a[],ll n)
{
	ll min1=max_ll;
	fo(i,n)
	{
		min1=min(min1,a[i]);
	}
	return min1;
}
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
ll power(ll x,ll y,ll m){            //power(x,y)=x^y  %m;
    if(y==0)return 1;
    ll a=power(x,y/2,m);
    if(y%2){
        return (a*((a*x)%m))%m;
    }
    else{
        return (a*a)%m;
    }
}
ll mod_inverse(ll x,ll m){
    return power(x,m-2,m);
}
ll fact(ll n,ll m){
    if(n<=1)return 1;
    return (fact(n-1,m)*n)%m;
}
ll ncr(ll n,ll r,ll m){
    if(r>n)return 0;
    ll n1=1,d1=1,d2=1;
    n1=fact(n,m);d1=fact(r,m);d2=fact(n-r,m);
    ll ans=mod_inverse((d1*d2)%m,m);
    ans=(ans*n1)%m;
    return ans;
}
int gcd(int a, int b){ 
	if(a==0||b==0)return max(a,b);
    if (a < b)return gcd(b, a); 
    if (a % b == 0) return b; 
    return gcd(b,a % b);}

int ispal(string s){
    int len=s.size();
    int flag=1;
    for(int i=0;i<len;++i){
        if(s[i]!=s[len-i-1]){
            flag=0;break;
        }
    }
    return flag;
}
 
ll sroot(ll n,ll low=1,ll high=1e9+1){
    if(low==high)return low;
    if(low==high-1){
        if(high*high<=n)return high;
        else return low;
    }
    ll mid=(low+high)/2;
    ll a=mid*mid;
    if(a>n)return sroot(n,low,mid-1);
    else return sroot(n,mid,high);
}
ll croot(ll n,ll low=1,ll high=1e6+1){
    if(low==high)return low;
    if(low==high-1){
        if(high*high*high<=n)return high;
        else return low;
    }
    ll mid=(low+high)/2;
    ll a=mid*mid*mid;
    if(a>n)return croot(n,low,mid-1);
    else return croot(n,mid,high);
 
}

bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
}  
//A^A=0   2^10=10^3, 2^20=10^6  2^30=10^9.......
// map <ll,ll> mp can give TLE over ll mp[n+5]
//ind mod ques .... always do ans=(ans+mod)%mod;
//-----------------FUCK RATING------------------
    
/***************************code begins here*****************************/


class solver{
	public:
		
	void solve()
	{	
		ll n;cin>>n;
		ll a[n];fo(i,n)cin>>a[i];
		ll dp[n];
		dp[n-1]=a[n-1]%mod;
		
		for(ll i=n-2;i>=0;i--)
		dp[i]=(dp[i+1]+a[i])%mod;
		
		
		ll ans=0;
		fo(i,n-1)
		{
			ll m=(a[i]*dp[i+1])%mod;
			ans=(ans+m)%mod;
		}
		cout<<(ans+mod)%mod;
    }
};
 
int main(){
	fastttt
	int test=1,c=1;
	//cin>>test;
	while(test--){
		//cout<<"Case #"<<c<<": ";c++;
		solver o;
		o.solve();
	}
}