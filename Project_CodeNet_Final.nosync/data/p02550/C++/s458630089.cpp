#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 
 
#define pb push_back
#define ll long long
#define ld long double
#define sz(x) (ll)x.size()
 
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
 
#define infi INT_MAX
#define infl INT_MAX
#define infd LDBL_MAX
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(i,a,b) for(ll i=(b-1);i>=a;i--)
#define F first
#define S second
#define G(a,b) get<a>(b)
#define MP make_pair
#define MT make_tuple
#define pll pair<ll,ll>
//#define endl "\n"
#define ALL(v) v.begin(),v.end()
#define nl cout<<"\n";
#define pr(x) cout<<x;
#define pr1(x) cout<<x<<" ";
#define pr2(x,y) cout<<x<<" "<<y;
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z;
#define pr4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w;
#define deb cout<<"***************************************************************************************\n";
#define moshi cout<<"moshi moshi ! \n";
#define hi cout<<"hi ! \n";
#define bye cout<<"bye bye ! \n";
#define kawai cout<<"O kawai koto ! \n";
#define o_set(ll) tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define number_of_set_bits  __builtin_popcountll
const ld PI=3.1415926535897932384626433;
 

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
 
#define endl "\n"
 


 

 
 
ll is_set(ll a,ll i)
{
   if( ( a & ((ll)1<<i) ) == 0 ) return 0;
   else return 1;
}
 
 
 
//  Comparator should follow :
//  1: x<=y or y<=x uniquely
//  2: Transitivity : a<=b and b<=c implies a<=c
//  3: Anti-Symmetry: a<=b and b<=a implies a=b
// return 1 to put x before y in sorted order
/*inline bool comp(pll &x,pll &y)
{
   if(x.F<y.F) return 1;
   else if(x.F==y.F)
   {
      if(x.S>y.S) return 1;
      else return 0;
   }
   return 0;
}*/
 
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
// resize : str.resize(new_size)   new size <= old size
 
// for Vector :
// lower_bound(starting iterator , iterator next to end , value)  :  iterator to first element greater than or equal to value
// upper_bound(starting iterator , iterator next to end , value)  :  iterator to first element strictly greater than value
 
// For Set :      s.lower_bound(value)
// if no such element exists they return  vector.end() or s.end()
 
 
// x bits : [x-1 , x-2 , .... , 1(1st bit) , 0(0th bit)] =>   leftmost 1 at 2^(x-1)    max number that can be represented : 2^(x) -1
// 63 bits is greater than 10^18
 
// 1<<x  :  2 ^ x  (left shift)
 
// Min heap :  priority_queue < ll , vector<ll>, greater<ll> > q
// Max heap :  priority_queue < ll > q
    // Set in descending order  :   set< ll,greater <ll> >
 
 
// While debugging :
// 1 : check if array size is correct  :  It may give unexpected results
// 2 : check if you have swapped i and j at some part of program
// 3 : for string check if you are trying to acces  index = -1
 
 
// Bitwise Tricks :
// 1 : While using 1<<i  use (ll)1<<i  because in former one "1" is considered as int
// 2 : To flip first k-bits of a number :  x xor (2^k-1)  or x ^ (((ll)1<<k)-1)  : 2^k-1 is the largest number of k bits
// 3 : To flip k-th bit (0-based)  :  x xor (2^k)  or  x ^ ((ll)1<<k)
// 4 : To set k-th bit (0-based)   :  x or (2^k)   or  x | ((ll)1<<k)
// 5 : To un-set k-th bit (0-based)   :  x & (~ ((ll)1<<k) )
 
 
// To prove Greedy :
// 1 : Optimal Choice at each step
// 2 : Exchange Argument
// 3 : Find a lower or upper bound on answer and then construct an answer for that bound
// 4 : Find properties which Optimal Solution must satisfy ( This can be useful to deduce form of Optimal answer)
 
// Erase one occurrence in multiset : it=s.find(element)   s.erase(it)
// putchar('a'+j) : to print (j+1)th character
// getline(cin,str) : To input string until newline
 
 
void lps(string &pp,ll *lps)
{
   ll xx=pp.length();
   //ll lps[xx]={};
   f(i,1,xx)
   {
       ll j=lps[i-1];
       while(j>0 && pp[j]!=pp[i]) j=lps[j-1];
       if(pp[i]==pp[j]) j++;
       lps[i]=j;
   }
}
 
 
// Remember to take input string as  getline(cin,s)
void stoi(string &s,vll &v)
{
   stringstream str(s);
   ll x;
   while(str>>x)
   {
       v.pb(x);
   }
}
 
 
 
 
void Miden(ll **p1,ll n)
{
    ll (*x)[n]=(ll(*)[n]) p1;
    f(i,0,n)
    {
        f(j,0,n)
        {
            x[i][j]=0;
        }
        x[i][i]=1;
    }
    return;
}
 
void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m)
{
    ll (*a)[y]=(ll (*)[y])p1;
    ll (*b)[z]=(ll (*)[z])p2;
    ll (*c)[z]=(ll (*)[z])ans;
    f(i,0,x)
    {
        f(j,0,z)
        {
            c[i][j]=0;
            f(k,0,y)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return;
}
 
void Mpow(ll **p1,ll **ans,ll n,ll y,ll m)
{
    if(y==0)
    {
        Miden(ans,n);
        return;
    }
    ll t[n][n];
    Mpow(p1,(ll **)t,n,y/2,m);
    ll z[n][n];
    Mmult((ll **)t,(ll **)t,(ll **)z,n,n,n,m);
    if(y%2)
    {
        Mmult((ll **)z,p1,ans,n,n,n,m);
    }
    else
    {
        Miden((ll **)t,n);
        Mmult((ll **)z,(ll **)t,ans,n,n,n,m);
    }
    return;
}
 


//const ll N=2e5+5;
ll p=998244353;
//ll fac[N];

ll gcd(ll a, ll b)
{
   if (a == 0) return b;
   return gcd(b % a, a);
}
 
inline ll ceil(ll a,ll b)
{
   return (a+b-1)/b;
}

ll max(ll x,ll y,ll z)
{
   return max(x,max(y,z));
}
 
ll min(ll x,ll y,ll z)
{
   return min(x,min(y,z));
}
 
 
ll modpro(ll x,ll y,ll z=1)
{
   x%=p;
   y%=p;
   z%=p;
   ll res=(x*y)%p;
   res=(res*z)%p;
   return res;
}
 
ll modadd(ll x,ll y,ll z=0)
{
   x%=p;
   y%=p;
   z%=p;
   ll res=(x+y)%p;
   res=(res+z)%p;
   return res;
}
 
 
ll pow_mod_p(ll a,ll b)
{
   a=a%p;
   ll res=1;
   while(b>0)
   {
     if(b&1) res=(res*a)%p;
     b=b>>1;
     a=(a*a)%p;
   }
   return res;
}
 
inline ll mod_inv(ll x)
{
   return pow_mod_p(x,p-2);
} 
 

 
void exit()
{
  cout<<"-1\n";
  exit(0);
}




//Don't forget to set fac[0]=1
/*ll nCr(ll x,ll y)
{
   if(x<y) return 0;
   if(x==y) return 1;
   ll res=fac[x];
   ll den=(fac[y]*fac[x-y])%p;
   ll deni=mod_inv(den);
   res=(res*deni)%p;
   return res;
}*/
 
auto clk=clock(); 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

//template<typename T>
//#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

const ll N=1e5+5;
bool mark[N];

void func()
{
  ll n,x,m;
  cin>>n>>x>>m;
  //trace(n,x,m);
  
  vll v;
  v.pb(x);
  ll sm=0;
  
  mark[x]=1;
  

  ll curr=(x*x)%m;
  while( (!mark[curr]) )
  {
    v.pb(curr);
    mark[curr]=1;
    curr=(curr*curr)%m;
  }  
  
  ll idx=0,temp=x;
  while(temp!=curr)
  {
    idx++;
    temp=(temp*temp)%m;
  }

  if(n<=sz(v))
  {
    ll ans=0;
    f(j,0,n) ans=ans+v[j];
    cout<<ans<<"\n";
    return;
  }

  /*for(auto i:v) 
  {
    cout<<i<<" ";
    nl
  }*/

  //trace(curr);
  //trace(sz(v),idx);
  
  f(j,idx,sz(v)) sm+=v[j];
  //trace(sm);
  ll ans=0;
  f(j,0,idx) ans+=v[j];
  //trace(ans);
  n-=idx;
  //trace(n);
  ll y=sz(v)-idx;

  ll cnt=n/y,rem=n%y;
  ans+=(sm*cnt);

  f(i,idx,idx+rem) ans+=v[i];
  cout<<ans<<"\n";
} 


int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout<<fixed<<setprecision(8);

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif // ONLINE_JUDGE


    ll ntc=1;
    //cin>>ntc;

    f(i,1,ntc+1)
    {
      //cout<<"Case #"<<i<<": ";
      func();
    }

    #ifdef rd
    cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

    return 0;
}
