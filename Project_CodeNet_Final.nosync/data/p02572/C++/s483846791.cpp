                               //ABHISHEK AGRAWAL,BIT mesra//                    
                      //Newbie......You have to be odd to be no. ONE :)//
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fl float
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define vs vector <string>
#define vc vector <char>
#define vii vector<int>
#define vll vector<ll>
#define sll set<ll>
#define pii pair<int,int>
#define plc pair<ll,char>
#define tlll tuple<ll,ll,ll>
#define mt make_tuple
#define vpll vector<pair<ll,ll>>
#define vpii vector<pair<int,int>>
#define vtll vector<tuple<ll,ll,ll>>
#define vvll vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define mll map<ll,ll>
#define mp make_pair
#define sp(n) fixed<<setprecision(n)
#define mcl map<char,ll>
#define msl map<string,ll>
#define mod (ll)1000000007
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define test ll t;read(t);while(t--) 
#define sortv(v) sort(v.begin(),v.end())
#define INF (ll)(1e15)
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<=n;i++)
#define rloop(n,i) for(int i=n-1;i>=0;i--)
#define loopab(i,a,b,c) for(int i=a;i<=b;i+=c)
#define reada(a,n) loop(i,n) cin>>a[i];
#define reada1(a,n) loop1(i,n) cin>>a[i];
#define sorta(a) sort(a,a+n,greater<ll>())
#define countone(n) __builtin_popcount(n)
#define numoftrailzero(n) __builtin_ctz(n)
#define maxpowoftwo(n) __builtin_clz(n)
#define leastindexwithone(n)  __builtin_ffs(n)
#define what_is(x) cerr << #x << " is " << x << endl;
#define pfv(v) cout<<v.size()<<"\n";loop(i,v.size()) cout<<v[i]<<" ";cout<<"\n";
#define pv(v) loop(i,v.size()) cout<<v[i]<<" ";
#define all(v) v.begin(),v.end()
#define mset(dp,val) memset(dp,val,sizeof(dp))
//if we need to devide any given number in powers of term the power of max term
#define answer(n) ceil(log2(n+1))
int q,n;ll ans,sum;
ll gcd(ll a, ll b){if (b==0){return a;} return gcd(b,a%b);}
ll powe(ll a,ll b){ll res=1;while(b>0){if(b%2 ==1){res=(res*a);}a=(a*a);b/=2;} return res;}
ll power(ll a,ll b,ll M){a%=M;ll res=1;while(b>0){if(b%2 ==1){res=(res*a)%M;}a=(a*a)%M;b/=2;} return res;}
ll extendedEuclid(ll A,ll B,ll &x,ll &y){
    if(B == 0) {
        x = 1;
        y = 0;
        return A;
    }
    else {
        ll x1 , y1;
        ll gcd = extendedEuclid(B,A%B,x1,y1);
        y = x1-(A/B)*y1; 
        x = y1;
        return gcd;
    }
}
ll mi(ll A, ll M){ll x,y;extendedEuclid(A,M,x,y);if(x<0){x+=mod;} return x;}
vector<bool>sieve(1000000,true);
void Sieve(){
 sieve[0]=false;
 sieve[1]=false;
 for(ll i=2;i*i<=1000000;i++){
  if(sieve[i]==true){
   for(ll j=i*i;j<1000000;j+=i)
    sieve[j]=false;
  }
 }
}
 vll sieve_spf;
void Sieve_spf(){
 const ll n = 1e6 + 5;
 sieve_spf.resize(n);
 
 loop(i,n)
  sieve_spf[i]=i;
 
 sieve_spf[0]=-1;
 sieve_spf[1]=1;
 
 loopab(i,2,n,2)
  sieve_spf[i]=2;
 
 loopab(i,3,n,2)
  if(sieve_spf[i]==i)
   loopab(j,i*i,n,i)
    if(sieve_spf[j]==j)
     sieve_spf[j]=i;
}
#ifdef TESTING 
#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#else 
#define DEBUG 
#define VALUE(x) 
#define debug(...) 
#endif
bool isUpcase(char c){
    if(c >= 'A'&&c <= 'Z') return true;
    else return false;
}
bool islowcase(char c){
    if(c >= 'a'&&c <= 'z') return true;
    else return false;
}
void the_happiest_place_on_earth()
{
    flash;
  #ifdef ENABLE_FILE_IO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif      
} 
bool comp(const pii &a, const pii &b){
 if(a.f>b.f)
  return true;
 else if(a.f==b.f && a.s<b.s)
  return true;
 else
  return false;
}

const int N=200055;ll a[N],b[N],k,w,a1,b1,c1,d1,a2,b2,c2,d2;
vii graph[N];
bool vis[N];
map<pii,ll>m1;
void gra(ll m){
  loop(i,m){
    ll x,y,w;cin>>x>>y>>w;
    //x--,y--;
    m1[{y,x}]=w;
    graph[x].pb(y);
    graph[y].pb(x);
  }
}
vii an;

void testcase(){
  cin>>n;
  ll sum=0;
  loop(i,n) cin>>a[i],sum+=a[i];
  loop(i,n){
    b[i]=sum-a[i];
    sum-=a[i];
  }
  ans=0;
  loop(i,n){
    (ans+=(b[i]%mod*a[i]%mod)%mod)%=mod;
  }
  cout<<ans%mod;
  return;
}
int main(){
  //the_happiest_place_on_earth;
  //Today's thought: Push yourself,because no one else is going to do it for you.
  //Things aren’t always #000000 and #FFFFFF
  //START OF PROGRAM LOGIC
  //g++ -o a BB.cpp -DENABLE_FILE_IO;./a
  the_happiest_place_on_earth();
  q=1;//int t=0;
  //cin>>q;   
  while(q--){
    //cout<<"Case #"<<++t<<": ";
    testcase();
  } 
  cerr << "Time : " << 1000 *((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
  //END OF PROGRAM LOGIC
	return 0;
}
/*
######  ###### #     # ####### #     # ##### #     #    #    ####### ####### ######
#     # #      ##    # #     # ##   ##   #   ##    #   # #      #    #     # #     #
#     # #      # #   # #     # # # # #   #   # #   #  #   #     #    #     # #     #
#     # #####  #  #  # #     # #  #  #   #   #  #  # #     #    #    #     # ######
#     # #      #   # # #     # #     #   #   #   # # #######    #    #     # #   #
#     # #      #    ## #     # #     #   #   #    ## #     #    #    #     # #    #
######  ###### #     # ####### #     # ##### #     # #     #    #    ####### #     #
*/