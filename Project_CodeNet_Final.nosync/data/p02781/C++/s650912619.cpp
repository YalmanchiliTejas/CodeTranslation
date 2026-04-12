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
ll fact[1000007]={0}; // returns factorial of that number
bool sv[maxx]={0};    // returns if a num is prime or not
int sp[maxx]={0};     // gives smallest prime factor of the number
void facto() {fact[0]=1;fact[1]=1;for(int i=2;i<100007;i++)fact[i]=(fact[i-1]*i)%mod;}
void Sieve() {for(int i= 2; i< maxx; i+= 2)sp[i] = 2;for(ll i = 3; i < maxx; i += 2){if (!sv[i]){sp[i] = i;for (ll j = i; (j*i) < maxx; j += 2){if (!sv[j*i])sv[j*i] = true, sp[j*i] = i;}}}}
ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expm(fact[r],mod-2)))%mod; res=(res*(expm(fact[n-r],mod-2)))%mod; return res;}
*/
using namespace std;
int k,dp[100][2][4];
int func( string arr,int pos,bool tight,int digitsUsed){
  
  if(digitsUsed==k && pos==arr.length())
    return 1;
  if(digitsUsed>k)
  {
    return 0;
  }
  if(pos==arr.length())
    return 0;
  if(dp[pos][tight][digitsUsed]!=-1) 
    return dp[pos][tight][digitsUsed];
  int ans=0;
  if(tight)
  {
    for(int i=0;i<=(arr[pos]-'0');i++)
    {
      if(i!=0)
        digitsUsed++;
      if(i==(arr[pos]-'0'))
      {
        ans+=func(arr,pos+1,1,digitsUsed);
      }
      else
      {
        ans+=func(arr,pos+1,0,digitsUsed);
      }
      if(i!=0)
        digitsUsed--;
      
    }
  }
    else
    {
      for(int i=0;i<=9;i++)
      {
        if(i!=0)
          digitsUsed++;
        ans+=func(arr,pos+1,0,digitsUsed);
        if(i!=0)
          digitsUsed--;
        
      }
    }
    dp[pos][tight][digitsUsed]=ans;
    return ans;
    

}

signed main(){
  fast;
  //usefile;
  //test
  {
    // fill(dp,dp+800,-1);
    memset(dp,-1,sizeof(dp));
    string n;
    cin>>n;
    cin>>k;
  cout<<func(n,0,1,0);
  }
  //time("");
  return 0;
}