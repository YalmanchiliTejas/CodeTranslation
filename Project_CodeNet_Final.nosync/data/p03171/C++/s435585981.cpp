// Vaidik Patel(India)
// DA-IICT
#include <bits/stdc++.h>
using namespace std;
//********************************************
#include<ext/pb_ds/assoc_container.hpp> // include the associative containers or group of templates such as set, multimap, map etc.
#include<ext/pb_ds/tree_policy.hpp> // include the tree_order_statistics_node update
using namespace __gnu_pbds; //necessary for the GNU based Policy based data structures.
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//********************************************
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int INF = (int)1e9;
ll INFINF = (ll)1e18 + 10;
const ld PI = 3.14159265358979323846;
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minheap priority_queue<ll,vector<ll>,greater<ll> >
#define maxheap priority_queue<ll,vector<ll>,less<ll> >
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rFOR(i,a,b) for(ll i=a;i>=b;i--)
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define deb4(x,y,z,w) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#w<<" : "<<w<<endl;
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define checkbit(n,b) ( (n >> b) & 1)
#define mkp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TIME cerr << "Time Elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"\n";
#define lc 2*idx
#define rc 2*idx+1
ll powermodm(ll x,ll n,ll mod)
{ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%mod;x=(x*x)%mod;n=n/2;}return result;}
ll GCD(ll , ll );
ll LCM(ll ,ll);
ll power(ll ,ll);
ll choose(ll,ll);
int ones(ll);
void extendedEuclid(ll, ll);
ll MMI(ll, ll);
void fastscan(int &);
bool checkithbit(ll,ll); // ith bit is zero or not
vector<ll>SegmentTree;
void Build_Segment_Tree(vector<ll>&a,ll idx,ll l,ll r);
ll sum(ll idx,ll sl,ll sr,ll l,ll r);
void update(ll idx,ll sl,ll sr,ll value,ll id);
vector<ll>prime;
void findprime(void);
ll phi(ll num);
vector<int>isprime;
void precomputeprime(int N);
vector<int>prephi;
void precomputephi(int N);
inline int read();
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define pb push_back
#define M  1000000007
//////////////////////////////////////////////////////////////////////////////
ll n;
vll a;
ll dp[3005][3005];
ll find(ll l,ll r)
{
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    ll x=a[l]-find(l+1,r);
    ll y=a[r]-find(l,r-1);
    return dp[l][r]=max(x,y);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    cin>>n;
    a.resize(n);
    memset(dp,-1,sizeof(dp));
    FOR(i,0,n)
    {
        cin>>a[i];
    }
    ll ans=find(0,n-1);
    cout<<ans;
    return 0;
}
//////////////////////////////////////////////////////////////////////////
//precomputephi()
void precomputephi(int N)
{
    prephi.resize(N);

    FOR(i,0,N)
    {
        prephi[i]=i;
    }

    for(int i=1;i<N;i++)
    {
        if(isprime[i])
        {
            for(int j=i;j<N;j+=i)
            {
                prephi[j]=prephi[j]-(prephi[j]/i);
            }
        }
    }
}

//precomputedprime()
void precomputeprime(int N)
{
    isprime.resize(N);
    isprime.assign(N,1);
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i*i<=500005;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=500005;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
}
//"""euler totient function""": counts the number of integers between 1 and n inclusive, which are coprime to n.
ll phi(ll num) // find using factorization in O(sqrt(N)).....
{
    ll result=num;
    for(ll i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            while(num%i==0)
            {
                num/=i;
            }
            result-=(result/i);
        }
    }
    if(num>1)
    {
        result-=(result/num);
    }
    return result;
}

void findprime(void)
{
    int N=1e6+5;
    vector<bool>isprime(N,1); //up to 1e6+5 number
    for(int i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                if(isprime[j])
                {
                    isprime[j]=0;
                }
            }
        }
    }

    for(int i=2;i<=N;i++)
    {
        if(isprime[i])
        {
            prime.pb(i);
        }
    }

}

bool checkithbit(ll a,ll i)
{
if(a & (1 << i))
{
return  true;
}
else
{
return false;
}
}
ll GCD(ll a , ll b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}
ll LCM(ll a,ll b){return (max(a,b)/GCD(a,b))*min(a,b);}

ll power(ll a , ll n)
{
    unsigned long long int result=1,x=a;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x = x * x;
        n=n/2;
    }
    return result;
}
ll choose(ll n,ll k)
{
    if(k==0)  return 1;
    return (n* choose(n-1,k-1))/k;
}
int ones(ll n)
{
    int c=0;
    while(n)
    {
        n=n&(n-1);
        c++;
    }
    return c;
}
//store gcd of a,b in d
//store solution of a*x + b*y = d in x,y
// if gcd(a,b)=1 then x = a^(-1)(mod b) and y = b^(-1)(mod a)
ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
// return modulo inverse of a wrt modulo p(should be prime)
// retunt -1 if modulo inverse does not exist
ll MMI(ll a, ll p)
{
    extendedEuclid(a,p);
    if(d==1 && p!=1)
        return ((x%p)+p)%p;
    else
        return -1;
}

//Fastest way to read Input
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
void Build_Segment_Tree(vector<ll>&a,ll idx,ll l,ll r) //where l and r is query range.
{
  if(l==r)
  {
    SegmentTree[idx]=a[l];
  }
  else
  {
    ll mid=(l+r)/2ll;
    Build_Segment_Tree(a,(2ll*idx),l,mid);
    Build_Segment_Tree(a,(2ll*idx)+1,mid+1,r);
    SegmentTree[idx]=SegmentTree[2ll*idx]+SegmentTree[2ll*idx+1];
  }
}
ll sum(ll idx,ll sl,ll sr,ll l,ll r) //here [sl...sr] segment range associate at idx index. where l and r is query range.
{
    if(l>r)
    {
        return 0;
    }
    if(sl==l && sr==r)
    {
        return SegmentTree[idx];
    }


    ll mid=(sl+sr)/2;
    return sum(2ll*idx,sl,mid,l,min(r,mid))+sum(2ll*idx+1,mid+1,sr,max(mid+1,l),r);
}

void update(ll idx,ll sl,ll sr,ll value,ll id)
{
    if(sl==sr && sl==id)
    {
        SegmentTree[idx]=value;
    }
    else
    {
        ll mid=(sl+sr)/2ll;
        if(id<=mid)
        {
            update(2ll*idx,sl,mid,value,id);
        }
        else
        {
            update(2ll*idx+1,mid+1,sr,value,id);
        }
        SegmentTree[idx]=SegmentTree[2ll*idx]+SegmentTree[2ll*idx+1];
    }
}
/*
note:
//a.resize(unique(a.begin(), a.end()) - a.begin()); use for create array unique element...
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); shuffle(g1.begin(), g1.end(), rng);(g1 is array name) for choose random number
//int grand(int x) {
    return uniform_int_distribution<int>(0, x - 1)(rng);
}
//use once(num) give no of 1 in its binary form
//use give (int)log2(num)+1 give no of digits in its binary form
//bitset<64>(num).to_string() convert decimal to num64 bit binary number
//stoull(str, nullptr, 2) convert str in binary form to decimal number
// "max" priority queue: priority_queue<ll, vector<ll>, less<ll> >pq;   #select max element as top()#
// "min" priority queue: priority_queue<ll, vector<ll>, greater<    ll> >pq; #select min element as top()#
//set<int> inbuit sort accending order (set<int,less<int>>)
//set<int,greater<int>> sort element in decreasing order
// int  __builtin_popcount(unsigned int)
--->It returns the numbers of set bits in an integer (the number of ones in the binary representation of the integer).
///for finding xnor from xor
        x1=Xor
    x2=Xnor
    ll x1=a ^ b;

        ll num=max(a,b);

        ll xx=log2(num)+ 1;   (length of num in binary form)
    ****ll t=(1 << xx) - 1;  (set all xx length bits to 1)
        ll x2=x1 ^ t;            (get xnor via xor using t)


--->Dilworth's theorem:-
        this theorem says that the minimum number of non-decreasing sequences we need to cover the
        whole sequence equals the length of least decreasing subsequence.
----->a + b = (a xor b) +( 2 * (a & b)); ///very imp
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

x&(-x) which is equal to highest power of two that divides x.
x&(x-1) which is equal 0 only when x is a power of two(except x == 0)
###
string str;
vector<string>ip;
istringstream iss(str);
for(string s;iss>>s;)
{
 ip.push_back(s);
}
###
*/

