  //author: chinmay0402
  #include<bits/stdc++.h>
  using namespace std;
  //policy based data structures
  #include<ext/pb_ds/assoc_container.hpp>
  using namespace __gnu_pbds;
  typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

  #define ll long long int
  #define ld long double
  #define fl float
  #define vs vector<string>
  #define vll vector<ll>
  #define pll pair<ll,ll>
  #define vpll vector<pair<ll,ll>>
  #define fst first
  #define scd second
  #define sll set<ll>
  #define mll map<ll,ll>
  #define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
  #define INF (ll)10000000000000000
  #define MOD (ll)1000000007
  #define pb push_back
  #define msl map<string,ll>
  #define test ll t;cin>>t;while(t--)
  #define sortv(v) sort(v.begin(),v.end())
  #define max3(a,b,c) max(a,max(b,c))
  #define lcm(a,b) (a*b/__gcd(a,b))
  #define all(a) a.begin(),a.end()
  #define sz(a) a.size()
  #define present(c,x) (c.find(x)!=c.end());
  #define c_sum accumulate(all(c),(ll)0);
  #define count_ones(x) __builtin_popcountll(x)
  #define doom cout<<"doom\n"
  #define debug(x) cerr<<#x<<"->"<<x<<"\n";
  #define min_pq priority_queue<ll,vll,greater<ll>>;

  #define forn(i,n) for(ll i=0;i<n;i++)
  #define for1(i,n) for(ll i=1;i<=n;i++)
  #define fornr(i,n) for(ll i=n-1;i>=0;i--)
  #define forab(i,a,b,c) for(ll i=a;i<=b;i+=c)

  template<typename T>
  void read(T &x){
  cin>>x;
  }
  template<typename T,typename T1>
  void read(T &x, T1 &y){
  cin>>x>>y;
  }
  template<typename T,typename T1, typename T2>
  void read(T &x, T1 &y, T2 &z){
  cin>>x>>y>>z;
  }
  template<typename T,typename T1, typename T2, typename T3>
  void read(T &x, T1 &y, T2 &z , T3 &a){
  cin>>x>>y>>z>>a;
  }
  template<typename T>
  void reada(T oneD,ll n){
  for(ll i=0;i<n;i++)
    cin>>oneD[i];
  }
  template <typename T>
  void readv(vector< T > &oneD,ll n){
  forn(i,n){
    ll x;
    read(x);
    oneD.push_back(x);
  }
  }
  template<typename T>
  void readg(vector< T >graph[100001], ll n){
  forn(i,n){
    ll x,y;
    cin>>x>>y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  }

  #define iread1(n) ll n;read(n);
  #define iread2(n,m) ll n,m;read(n,m);
  #define iread3(x,y,z) ll x,y,z;read(x,y,z);

  ll gcd(ll a, ll b){
  if(a==0)
    return b;
  else
    return gcd(b%a,a);
  }

  ll gcdExt(ll a,ll b, ll &x, ll &y){
  if(a==0){
    x=0;
    y=1;
    return b;
  }
  ll x1,y1;
  ll gcd=gcdExt(b%a,a,x1,y1);
  x=y1-(b/a)*x1;
  y=x1;
  return gcd;
  }

  ll pwr(ll a, ll b){
  ll res=1;
  while(b>0){
   if(b&1)
    res=res*a;
   a*=a;
   b>>=1;
  }
  return res;
  }

  ll pwrm(ll a, ll b, ll m){
  a%=m;
  ll res=1;
  while(b>0){
    if(b&1)
    res=res*a%m;
    a=a*a%m;
    b>>=1;
  }
  return res;
  }

  ll pwrm_which_works_too(ll a, ll b, ll m){
  a%=m;
  if(a==0)
    return 0;
  else if(b==0)
    return 1;
  else if(b&1)
    return (a*pwrm(a,b/2,m)%m*pwrm(a,b/2,m)%m)%m;
  else
    return (pwrm(a,b/2,m)%m*pwrm(a,b/2,m)%m)%m;
  }

  ll no_of_divisors(ll n){ 
  ll c = 0; 
  for (ll i = 1; i <= sqrt(n); i++) { 
    if (n % i == 0){ 
    if(n/i==i)
      c=c+1;
    else
      c=c+2;
    }
  }
  return c; 
  } 

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

  vll sieve_spf(1000001);
  void Sieve_spf(){
  ll n=1000001;
  
  forn(i,n)
    sieve_spf[i]=i;
  
  sieve_spf[0]=-1;
  sieve_spf[1]=-1;
  
  forab(i,2,n,2)
    sieve_spf[i]=2;
  
  forab(i,3,n,2)
    if(sieve_spf[i]==i)
    forab(j,i*i,n,i)
      if(sieve_spf[j]==j)
      sieve_spf[j]=i;
  }

 bool oppositeSigns(ll x,ll y) 
 { 
  return ((x^y)<0); 
 } 

 bool isInt(ll a, ll b){
  if((ld)a/(ld)b==a/b)
   return true;
  else
   return false;
 }

 struct CustomComp {
   bool operator() (const ll& a, const ll& b) const
   {return a<b;}  // {return a<b;} can be replaced by {return f(a)<f(b);}
   // Usage:set<ll,CustomComp>s;   and similarly for maps, etc.
 };

 // Lambda expression for custom sort
 auto comp = [](ll a, ll b) { return a < b; }; // {return a<b;} can be replaced by {return f(a)<f(b);}
 // Usage : map<ll,ll,decltype(comp)>mp(comp);    and similarly for set, etc;

 ll modInv(ll a,ll p){ //Only when p is prime
  return pwrm(a,p-2,p);
 }

 bool comparator(const pll &a, const pll &b){
  if(a.fst>b.fst)
   return true;
  else if(a.fst==b.fst && a.scd<b.scd)
   return true;
  else
   return false;
 }

ll mul(ll &a,ll b){
 return a=(((a+MOD)%MOD)*((b+MOD)%MOD))%MOD;
}

ll add(ll a,ll b){
 return (((a+MOD)%MOD)+((b+MOD)%MOD))%MOD;
}

bool is_int(ld a){
 if((ll)a==(ld)a && a>=1)
  return true;
 return false;
}

int countBits(float num) {       
 return (int)log2(num)+1; 
}

int main(){
// Work like there is someone working 24 hours a day to take it all away from you.

 #ifdef ENABLE_FILE_IO
 freopen("testfile.txt", "r", stdin);
 freopen("outfile.txt", "w", stdout);
 #endif

 // g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o 

 //START OF PROGRAM LOGIC
 int n;
 cin>>n;
 ll a[n];
 ll sum=0;
 const ll mod=1e9+7;
 for(int i=0;i<n;i++){
  cin>>a[i];
  sum=((sum%mod)+(a[i]%mod))%mod;
 }
 ll ans=0;
 for(int i=0;i<n;i++){
  ll forThis=(sum-a[i]+mod)%mod;
  ans=((ans%mod)+(((forThis%mod)*(a[i]%mod))%mod))%mod;
 }
 cout<<((ans%mod)*modInv(2,mod))%mod<<"\n";
 //END OF PROGRAM LOGIC
 cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
 return 0;
}
/*
 TIPS(FOR ME):
 *Sp.) In a binary search question, remember to always test your code on a two-element set,
      where the predicate is false for the first element and true for the second.
 0.) Read question correctly
 1.) Check for corner cases (like 0 is exception case)
 2.) Check for uninitialzed variables (even arrays)(bool does not get initialized as false by default)
 3.) Check for numbers overflow (while multiplying and doing MOD) (even ll can overflow)
 4.) Check for typecasting issues like int to float(while dividing numbers)
 5.) Check for division-by-zero error
 6.) Try to reduce space complexity for large constraints
 7.) Check if modulo has been applied correctly
 8.) Read constraints correctly
*/