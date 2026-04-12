 
/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define all(x)     x.begin(),x.end()
#define tc   int tt; scf(tt); while(tt--)
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
typedef double dd;
using namespace std;
const ll M =1e9+7;
const int N = 2e5+7;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)


int main()
{
   
   int n;
   scf(n);
   
   ll a[n],b[n];
   
   rep(i,0,n)
   {lscf(a[i]);
  
    b[i]=a[i];}   
   
    rep(i,1,n)
    {
        b[i]+=b[i-1];
    
        b[i]%=M;
    }
    
    
    ll sum=0;
    
    rep(i,0,n)
    {
        ll v=(a[i]*(b[n-1]-b[i]+M))%M;
        
        sum+=v;
        
        sum%=M;
        
    }
    
    lprin(sum%M);
    

    
}