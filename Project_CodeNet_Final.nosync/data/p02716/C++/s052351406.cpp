#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define nmod         -1000000007
#define N            1000000//31630=sqrt(pow(10,9))
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;
 
}
//bool pf[N+1ll];
//vec prim;
//void sieve()
//{
//    repi(i,0,N)
//    pf[i]=true;
//	pf[0] = pf[1] = false;
//    for (int i = 2; i <= N; i++) {
//        if (pf[i]) 
//		{
//            prim.push_back(i);
//            for (int j = i + i; j <= N; j+=i) {
//                pf[j] = false;
//            }
//        }
//    }
//}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
ll logg(ll base,ll x) 
{
    return (ll)(log(x) / log(base));
}
ll a[200005],dp[200005],prefix[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS; 
    while(TESTS--)
    {
    	ll m,k,g,i,l,h,j,mx,my,ans,d,n,x;
    	cin>>n;
    	cin>>a[1]>>a[2];
    	prefix[1]=a[1], prefix[2]=a[2];
    	repi(i,3,n)
    	{
    		cin>>a[i];
    		prefix[i]=prefix[i-2]+a[i];
		}
		dp[0]=0; dp[1]=0;
		repi(i,2,n)
		{
			if(i%2==0)
			dp[i]=max(prefix[i-1],dp[i-2]+a[i]);
			else
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		}
		cout<<dp[n];
	}
	return 0;
} 
