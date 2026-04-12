#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX 1000006
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define Case(t) printf("Case %d:\n", t)
#define pii pair<int, int>
#define MOD 1000000007
#define mod 10007
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

inline int Set(int N, int pos){return N=N | (1<<pos);}
inline int Reset(int N, int pos){return N=N & ~(1<<pos);}
inline bool Check(int N, int pos){return (bool)(N & (1<<pos));}

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll fast_exp(ll x, ll n, ll m)
{
    ll res = 1;
    while(n>0)
    {
        if(n%2==1)
            res = (res * x) % m;
        x = (x * x) % m;
        n/=2;
    }
    return res%m;
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

clock_t t_Start;
void Start()
{
    t_Start = clock();
}
void End()
{
    double Time = (double)(clock()-t_Start)/CLOCKS_PER_SEC;
    error(Time);
}

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet1;

typedef vector<vector<ll> >matrix;

ll p, q;
unsigned long long m = (1LLU<<64);

matrix multiply(matrix A, matrix B)
{
    int sz = A[0].size();
    matrix mul(sz, vector<ll>(sz, 0));
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
            for(int k = 0; k < sz; k++)
                mul[i][j] = (mul[i][j]%m + (A[i][k]%m * B[k][j]%m))%m;

    return mul;
}

matrix Power(matrix M, ll n)
{
    if(n==1)
        return M;
    if(n&1)
        return multiply(M, Power(M, n-1));
    matrix X = Power(M, n/2);
    return multiply(X, X);
}

void findNthTerm(ll n)
{
    matrix M(6, vector<ll>(6, 0));
    if(n < 3)
        printf("%lld %lld\n", m, m);
    else
    {
        M = Power(M, n-2);
        //printf("%lld %lld\n", fn, gn);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //Start();

    int n, m;
    cin>>n>>m;
    (n==m)?cout<<"Yes"<<endl:cout<<"No"<<endl;

    //End();
    return 0;
}
