#include<bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX
#define ll long long int
#define MP make_pair
#define PF push_front
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define F first
#define S second
#define tr(i,c) for(__typeof(c.begin()) i = (c).begin(); i != (c).end(); i++)
#define rtr(i,v) for(__typeof(v.rbegin()) i = (v).rbegin() ; i != (v).rend() ; i++)
#define sint(n); scanf("%d",&n);
#define sll(n); scanf("%lld",&n);
#define pint(n); printf ("%d\n",n);
#define pll(n); printf ("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define set(a,b) memset(a, b, sizeof(a))
#define DRT() ll tst;cin>>tst;for(ll test=1;test<=tst;test++)
#define present(c,x) ((c).find(x) != (c).end())

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll MOD = 1000000007;

/*
    Inbuilt GCC compiler functions
    __gcd(x, y)
    
    int __builtin_ffs (int x)    [ Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero ]
    int __builtin_ffsll (long long) [ Similar to __builtin_ffs, except the argument type is long long ]
    
    int __builtin_clz (unsigned int x)  [ Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined ]
    int __builtin_clzll (unsigned long long)   [ Similar to __builtin_clz, except the argument type is unsigned long long ]
    
    int __builtin_popcount (unsigned int x)  [ Returns the number of 1-bits in x ]
    int __builtin_popcountll (unsigned long long)  [ Similar to __builtin_popcount, except the argument type is unsigned long long ]
*/


inline void add(ll &x, ll y){x+=y; if(x>=MOD)x-=MOD; if(x<0)x+=MOD;}
inline ll mul(ll x, ll y){ return ((ll)x * y)%MOD;}
ll gcd(ll a, ll b){ if(b)return gcd(b,a%b); return a;}
ll power(ll a ,ll p){ll ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
ll phi(ll n){ ll ret=n; ll i = 2;                    // Counts the positive integers up to a given integer n that are relatively prime to n
    if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    if(n>1)ret-=ret/n;return ret;
}

typedef pair<ll, ll> PLL;
typedef vector<ll> VLL;

ll n;
ll dsu[100005], size[100005];
ll root (ll i)
{
    while(dsu[ i ] != i)
    {
        dsu[ i ] = dsu[ dsu[ i ] ] ; 
        i = dsu[ i ]; 
    }
    return i;
}

void weighted_union(ll A, ll B)
{
    ll root_A = root(A);
    ll root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
        dsu[ root_A ] = dsu[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        dsu[ root_B ] = dsu[root_A];
        size[root_A] += size[root_B];
    }
    return;
}

int main()
{
    cin>>n;
    PLL a[100005];
    set <PLL> aa;
    f(i, 0, n)
    {
        sll(a[i].F);
        sll(a[i].S);
        aa.insert(MP(a[i].F, a[i].S));
    }
    
    ll ct=0;
    vector < PLL > xv, yv;
    tr(i, aa)
    {
        ll x = (*i).F, y = (*i).S;
        xv.PB(MP(x, ct));   yv.PB(MP(y, ct));
        ct++;
    }
    f(i, 0, ct)
    {
        dsu[i]=i;
        size[i] = 1;
    }

    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    
set< pair<ll, PLL> > dv;
    tr(i, xv)
    {
        ll x1 = (*i).F, num = (*i).S;
        auto nx = next(i, 1);
        if (nx == xv.end())
            continue;
        ll x2 = (*nx).F, num2 = (*nx).S;
        
        dv.insert(MP(x2-x1, MP(min(num, num2), max(num, num2))));
    }
    tr(i, xv)
    {
        ll x1 = (*i).F, num = (*i).S;
        auto nx = next(i, 1);
        if (nx == xv.end())
            continue;
        ll x2 = (*nx).F, num2 = (*nx).S;
        
        dv.insert(MP(x2-x1, MP(min(num, num2), max(num, num2))));
    }
    tr(i, yv)
    {
        ll x1 = (*i).F, num = (*i).S;
        auto nx = next(i, 1);
        if (nx == yv.end())
            continue;
        ll x2 = (*nx).F, num2 = (*nx).S;
        
        dv.insert(MP(x2-x1, MP(min(num, num2), max(num, num2))));
    }
    
    ll ans=0;
    tr(i, dv)
    {
        ll d = (*i).F, v1 = (*i).S.F, v2 = (*i).S.S;
        
        if (root(v1) != root(v2))
        {
            weighted_union(v1, v2);
            ans += d;
        }

        if (size[root(0)] == ct)
            break;
    }
    cout<<ans<<endl;
    

    return 0;
}