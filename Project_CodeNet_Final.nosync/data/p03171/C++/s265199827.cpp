#include<bits/stdc++.h>
using namespace std;
//
typedef long double ld;
typedef long long int ll;
//
typedef pair<long long int,long long int> pii;
typedef pair<ll,ll> pll;
//
typedef vector<long long int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define prq priority_queue<ll>;
#define vbs(xx,x) binary_search(all(xx),x)
#define vlb(xx,x) lower_bound(all(xx),x)
#define vub(xx,x) upper_bound(all(xx),x)
//
//ll MOD=998244353;
ll M=1e9+7;
ll MOD=1e9+7;
#define PI 3.1415926535897932384626433832795
ll llMAX=1000000000000000008;
ll llMIN=-1000000000000000008;
//
#define forx(i,j,n) for(long long int i=j;i<n;i++)
#define fory(i,j,n) for(long long int i=j;i>=n;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define MEM(xx,yy) memset(xx,yy,sizeof(xx))
//
#define in(x) cin>>x
#define op(x) cout<<x
#define opnl(x) cout<<x<<"\n"
#define ops(x) cout<<x<<" "
#define nl cout<<"\n"
#define sp cout<<" "
#define flush fflush(stdout)
clock_t tim;
void showtime(){ tim=clock()-tim; cout<<" ===> "<<(ld)tim/CLOCKS_PER_SEC<<" seconds\n"; }
//
ll mul(ll mul_1,ll mul_2){ ll mul_t=((mul_1%MOD)*(mul_2%MOD)+MOD)%MOD; return mul_t; }
ll mul3(ll mul_1,ll mul_2,ll mul_3){ ll mul_t=mul(mul(mul_1,mul_2),mul_3)%MOD; return mul_t; }
ll add(ll add_1,ll add_2){ ll add_t=((add_1%MOD)+(add_2%MOD)+MOD+MOD)%MOD; return add_t; }
ll sub(ll sub_1,ll sub_2){ ll sub_r=1e15; ll sub_t=(((sub_1+sub_r)%MOD)-((sub_2+sub_r)%MOD)+sub_r)%MOD; return sub_t; }
ll pwm(ll x,ll y,ll p=M){ ll res=1; x=x%p; while(y>0){ if(y&1) res=(res*x)%p; y=y/2; x=(x*x)%p; } return res; } 
ll pw(ll x,ll y){ ll res=1; while(y>0){ if(y&1) res=(res*x); y=y/2; x=(x*x); } return res; } 
ll modinv(ll n){ return pwm(n, M-2, M); }
ll gcd(ll num1,ll num2){ return (num2?gcd(num2,num1%num2):num1); }
ll lcm(ll num1,ll num2){ return 1LL*((num1*num2)/__gcd(num1,num2)); }
ll myceil(ll x,ll y){ return (x+y-1)/y;}
long long int my_log(ll n, long long int b){ll i = 1;long long int ans = 0;while (1){if (i > n){ans--;break;}if (i == n)break;i *= b;ans++;}return ans;}
//
ll countbit(ll num){ return 1LL*(__builtin_popcountll(num)); }
ll setbit(ll num, ll kk){ return 1LL*(num|(1LL<<kk)); }
ll unsetbit(ll num, ll kk){ return 1LL*(num&~(1LL<<kk)); }
ll invertbit(ll num, ll kk){ return 1LL*(num^(1LL<<kk)); }
bool kthbit(ll num, ll kk){ return num&(1LL<<kk); }
ll zerotrail(ll num){ return 1LL*(__builtin_ctzll(num)); }
ll zerobegin(ll num){ return 1LL*(__builtin_clzll(num)); }
//
ll prime[1000005]; 
void sieve(){ //spf
    forx(i,0,1000005) prime[i]=i; 
    for(ll p=2; 1LL*p*p<1000005; p++){ if(prime[p]==p) { for(ll i=1LL*p*p; i<1000005; i+=p) if(prime[i]==i) prime[i]=p; } } 
    return; 
} 
bool isPrime(ll pri){
    if(pri==1||pri==0) return 0;
    if(prime[pri]==pri) return 1;
    return 0;
}
vl alldiv(ll num){
    vl prDiv; for(ll i=1; 1LL*i*i<=num; i++){ if(num%i==0){ prDiv.pb(i); if(i!=(num/i)) prDiv.pb(num/i); } }
    sort(all(prDiv)); return prDiv;
}
vl prdiv(ll num){
    vl prDiv; while(num!=1){ prDiv.pb(prime[num]); ll prtemp=prime[num]; while(num%prtemp==0) num/=prtemp; }
    return prDiv;
}
//
/*
bool vis[100005];
int dp[100005];
vector<vector<int>>ad(100005);
void dfs(int root){
   vis[root]=true;
   for(auto j:ad[root]){
      if(!vis[j]){
         dfs(j);
      }
      dp[root]=max(dp[root],1+dp[j]);
   }
}
*/
//
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int x=1;
//comment for single test case
//in(x);
forx(u,0,x){
   //cout<<"Case #"<<h+1<<":"<<" ";
   long long int n,j=0,k,m,f,q,s=0;
   cin>>n;
   long long int a[n+1];
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   long long int dp[n+1][n+1];
   memset(dp,0,sizeof(dp));
   for(int i=n;i>=1;i--){
      for(int j=i;j<=n;j++){
         if(i==j) dp[i][j]=a[i];
         else{
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
         }
      }
   }
   cout<<dp[1][n]<<"\n";
   
      
}

   //opnl(r);
//showtime();
return 0;
}
