#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int
#define mk make_pair
#define pb push_back
#define xx first
#define yy second
#define ar array
#define del 1e-8

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

double pi=3.141592653589793238;
const int M = 1e9+7;
const int Nmax=5005;
const int MM = 998244353;
const int N=1000005;


int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
      ll n,x,m;
      cin>>n>>x>>m;
      ll ans=0;
      ll k=x;
      map<ll,ll> s;
      int flag=0;
      for(ll i=1;i<=n;i++){
        if(flag==0 && s.count(k)){
            flag=1;
            ll in=(i-s[k]);
            ll pc=0;
            ll kk=k;
            for(ll j=i;j<i+in;j++){
                pc+=kk;
                kk=(kk*kk)%m;
            }
            ll bulk=(n-i+1)/in;
            ans+=bulk*pc;
            i+=bulk*in;
        }
        if(i<=n){
        ans+=k;
        if(flag==0)s[k]=i;
        k=(k*k)%m;
        }
       // cout<<i<<" -=-\n";
      }
      cout<<ans<<"\n";
    }
	return 0;
}
