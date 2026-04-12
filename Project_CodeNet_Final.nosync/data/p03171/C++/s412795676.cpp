                                  //ABHISHEK AGRAWAL//                    
                      //Newbie......You have to be odd to be no. ONE :)//
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fl float
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define vs vector <string>
#define vc vector <char>
#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll,ll>
#define plc pair<ll,char>
#define tlll tuple<ll,ll,ll>
#define mt make_tuple
#define vpll vector<pair<ll,ll>>
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
#define mcc map<char,char>
#define msl map<string,ll>
#define mss map<string,string>  
#define mod (ll)1000000007
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define test ll t;read(t);while(t--) 
#define sortv(v) sort(v.begin(),v.end())
#define INF (ll)(1e15)
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop1(i,n) for(ll i=1;i<=n;i++)
#define rloop(n,i) for(ll i=n-1;i>=0;i--)
#define loopab(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define reada(a,n) loop(i,n) cin>>a[i];
#define reada1(a,n) loop1(i,n) cin>>a[i];
#define sorta(a) sort(a,a+n,greater<ll>())
#define countone(n) __builtin_popcount(n)
#define numoftrailzero(n) __builtin_ctz(n)
#define maxpowoftwo(n) __builtin_clz(n)
#define leastindexwithone(n)  __builtin_ffs(n)
#define what_is(x) cerr << #x << " is " << x << endl;
#define pfv(v) cout<<v.size()<<"\n";loop(i,v.size()) cout<<v[i]<<" ";
#define pv(v) loop(i,v.size()) cout<<v[i]<<" ";
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
//if we need to devide any given number in powers of term the power of max term
#define answer(n) ceil(log2(n+1))
ll n,q;
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
 
 
template <typename T>
void read(T &x) {
    cin >> x;
}
template <typename T , typename T0>
void read(T &x, T0 &y) {
    cin >> x >> y;
}
template <typename T , typename T0 , typename T1>
void read(T &x, T0 &y, T1 &z) {
    cin >> x >> y >> z;
}
template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
    cin >> x >> y >> z >> w;
}
 
//pair//
//read pair//
template <typename T , typename T0>
void read(pair< T , T0 > &p) {
    cin >> p.f >> p.s;
}
//write pair//
template <typename T , typename T0>
void write(pair< T , T0 > &p){
    write(p.f);
    write(p.s);
}
 
//vector//
//read vector//
template <typename T>
void read(vector< T > &oneD, ll n) {
    loop(i,n)
    {
        ll x;
        read(x);
        oneD.pb(x);
    }
}
//array//
//read array//
template <typename T>
void read(T oneD[] , ll n) {
    loop(i,n){
        read(oneD[i]);
    }
}
//write array//
template <typename T>
void write(T oneD[] ,int n){
    loop(i,n){
        write(oneD[i]);
    }
    cout << endl;
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
bool oppositeSigns(ll x,ll y) 
{ 
    return ((x^y)<0); 
} 
int mpt(ll n){
    ll c=0;
     ll n1=pow(2,c);
     while(n1<n){
         c++;
         n1=pow(2,c);
     }
     return c;
}
void the_happiest_place_on_earth()
{
    flash;
  #ifdef ENABLE_FILE_IO
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif      
}
//const int N=305;ll a[N],dp[N][N][N];vll v[N];
const int N=3005;ll dp[N][N];
void solve(){
    read(n);
    vll a(n);
    loop(i,n) read(a[i]);
    for(ll l=n-1;l>=0;l--){
        for(ll r=l;r<n;r++){
            if(l==r) dp[l][r]=a[l];
            else dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1];
    return;
}
int main(){
    the_happiest_place_on_earth();
    //Today's thought: Push yourself, because no one else is going to do it for you.
    //Things aren’t always #000000 and #FFFFFF
    //START OF PROGRAM LOGIC
    solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    //END OF PROGRAM LOGIC
	return 0;
}