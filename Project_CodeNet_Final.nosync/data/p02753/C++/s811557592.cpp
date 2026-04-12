#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define mod ((ll)1e9+7)
#define inf ((ll)1e18+5)
#define maxx ((ll)1e6+5)
#define pb push_back
#define endl "\n"
#define time(i) cout<<"\nTime Elapsed "<<i<<" : " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#define usefile freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
ll exp(ll x,ll y,ll p){ ll res=1; while(y) {if(y%2) res=(res*x%p)%p; x=(x*x)%p; y/=2; } return res;}
ll expm(ll x,ll y){ ll res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
/*
bool sv[maxx]={0};    // returns 0 if a num is prime
int sp[maxx]={0};     // gives smallest prime factor of the number
void Sieve() {for(int i= 2; i< maxx; i+= 2) sv[i]=1,sp[i] = 2;sv[2]=0;for(ll i = 3; i < maxx; i += 2){if (!sv[i]){sp[i] = i;for (ll j = i; (j*i) < maxx; j += 2){if (!sv[j*i])sv[j*i] = true, sp[j*i] = i;}}}}
ll fact[1000007]={0}; // returns factorial of that number
void facto() {fact[0]=1;fact[1]=1;for(int i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%mod;}
ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expm(fact[r],mod-2)))%mod; res=(res*(expm(fact[n-r],mod-2)))%mod; return res;}
*/
using namespace std;
signed main(){
  fast;
  //usefile;
  //test
  {
    string s;
    cin>>s;
    if(s[0]==s[1]&& s[1]==s[2])
        cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
    }
    
  }
  //time("");
  return 0;
}