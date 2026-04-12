//To debug :  g++ -g file.cpp -o code
//to flush output : fflush(stdout) or cout.flush()
//cout<<setprecision(p)<<fixed<<var
//use 1LL<<i to for 64 bit shifting , (ll)2 because by default 2 is ll
//take care of precedence rule of operators 
//do not forget to change the sizes of arrays and value of contants and other things after debugging  
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for(i=a;i<n;++i)
#define irep(i,n,a) for(i=n;i>a;--i)
#define mod 1000000007
#define pb push_back
#define big 9223372036854775807
#define big1 LONG_MAX
#define big2 ll_MAX
#define big3 1000000000
#define sma1 LONG_MIN
#define sma2 ll_MIN
#define sma3 -1000000000
#define mp make_pair
#define dub double
#define ivec vector<ll>
#define lvec vector<long long>
#define cvec vector<char>
#define svec vector<string>
#define mt make_tuple
#define MOD 998244353
#define ld long double
#define pi acos(-1.0)
 
#define SZ(x)  (ll)(x.size())
 
//comment the below if not required
 
/*
 
#define ss second.second
#define ff first.first
#define f first
#define s second
#define sf second.first
#define fs first.second
*/
 
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//cout<<"Case #"<<c<<": "<<ans<<"\n" ;

int main()
{

    ll n,i,ans=0,s;

    cin>>n;

    ll a[n+1];

    rep(i,1,n+1)
        cin>>a[i];


    s = a[1];

    rep(i,2,n+1)
    {
        ans  = (ans + ((s*a[i])%mod))%mod;
        s = (s + a[i])%mod;
    }


    cout<<ans<<"\n";

    return 0;

}