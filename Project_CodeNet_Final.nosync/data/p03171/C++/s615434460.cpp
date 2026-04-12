#include <bits/stdc++.h>
using namespace std;


//************** StrAnge.R *********************

#define ll              long long int
#define ull             unsigned long long
#define ld              long double
#define lll             __int128
#define vi              vector<int>
#define vl              vector<ll>
#define vvi             vector<vector<int> >
#define pii             pair<int,int>
#define piii            pair<int,pair<int,int> >
#define pll             pair<ll,ll>
#define vii             vector<pii>
#define min_pq      priority_queue<int,vector<int>,greater<int> >

#define sz(v)           ((int)(v).size())
#define all(s)          s.begin(),s.end()
#define allr(s)         s.rbegin(),s.rend()
#define unq(c)          (sort(all(c)), c.resize(distance(c.begin(),unique(all(c)))))
#define get_pos(c,x)    (lower_bound(all(c),x)-c.begin())
#define ran(a, b)       ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

#define MS0(v)          memset((v), 0, sizeof((v)))
#define MS1(v)          memset((v), -1, sizeof((v)))
#define LEN(v)          strlen(v)

#define MP              make_pair
#define pb              push_back
#define pob             pop_back
#define ff              first
#define ss              second
#define sc              scanf
#define pf              printf
#define endl            "\n"

#define LL              ({ll __LL; scanf("%lld",&__LL); __LL;})
#define II              ({int __II; scanf("%d",&__II); __II;})
#define CC              ({char __CC; scanf("%c",&__CC); __CC;})
#define DD              ({double __DD; scanf("%lf",&__DD); __DD;})

#define intmx           INT_MAX
#define llmx            1llu<<61
#define PI              3.14159265358979323846264338327950L
#define MOD             1000000007
#define MAX             100010

#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       ((a)*((b)/gcd(a,b)))

#define shuffle(v)          (random_shuffle(all(v)))
#define min_ele(v)          (*min_element(all(v)))
#define max_ele(v)          (*max_element(all(v)))
#define is_equal(x, y)      (abs(x-y)<eps)
#define cnt_ele(v, x)       (count(all(v), x))
#define sum_ele(v)          (accumulate(all(v),0))
#define pro_ele(v)          (accumulate(all(v),1, multiplies<int>()))
#define init_range(v, x)    (iota(all(v),x))

#define TEST_CASE       int ___T; scanf("%d",&___T); for(int cs=1;cs<=___T;cs++)
#define PRINT_CASE      printf("Case %d: ", cs)
#define PRINT_CASEN      printf("Case %d:\n", cs)

#define vpf(v, len)     for(int ix=0;ix<len;ix++){pf("%d",v[ix]);if(ix!=len-1)pf(" ");else pf("\n");}
#define vsc(v, len)     for(int ix=0;ix<len;ix++)scanf("%d",&v[ix]);

#define FOR(i, a, b, stp)   for(int i = (a); i <= (b); i+=stp)
#define ROF(i, a, b, stp)   for(int i = (a); i >= (b); i-=stp)

template<class T>inline bool read(T &x) {int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
inline ll exp(ll a, ll p)               { if(p == 0) return 1; ll x = exp(a, p / 2) % MOD; x = (x * x) % MOD; if(p & 1) x = (x * (a % MOD)) % MOD; return x; }

inline int add(int a, int b) { a += b; if(a >= MOD) a -= MOD; return a; }
inline int sub(int a, int b) { a -= b; if(a < MOD) a += MOD; return a; }
inline int multi(ll a, ll b) { a *= b; if(a >= MOD) a %= MOD; return a; }

inline int on_bit(int N,int pos)    {return N = N | (1<<pos);}
inline int off_bit(int N,int pos)   {return N = N & ~(1<<pos);}
inline bool check_bit(ll N,int pos) {return (bool)(N & (1<<pos));}
#define on_bit_cnt(x)               (__builtin_popcount(x))

#define start_clock     clock_t tStart = clock()
#define end_clock       printf("\n>>Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fileio          freopen("in.txt","r",stdin);freopen("out.txt","w",stdout)


//******************* my code starts here **********************************

int n, ar[3005];

pair<ll, ll> dp[3005][3005][2];
bool used[3005][3005][2];

pair<ll, ll> solve(int lo, int hi, int player) {
    if(lo > hi) return {0, 0};

    if(used[lo][hi][player]) return dp[lo][hi][player];
    used[lo][hi][player] = 1;

    if(player) {
        pair<ll, ll> x = solve(lo+1, hi, player^1);
        x.ff += ar[lo];

        pair<ll, ll> y = solve(lo, hi-1, player^1);
        y.ff += ar[hi];

        if(x.ff >= y.ff) return dp[lo][hi][player] = x;
        return dp[lo][hi][player] = y;
    }
    else{
        pair<ll, ll> x = solve(lo+1, hi, player^1);
        x.ss += ar[lo];

        pair<ll, ll> y = solve(lo, hi-1, player^1);
        y.ss += ar[hi];

        if(x.ss >= y.ss) return dp[lo][hi][player] = x;
        return dp[lo][hi][player] = y;
    }
}

int main() {

    n = II; vsc(ar, n); // input

    pair<ll, ll> answer = solve(0, n-1, 1); // calculate dp
    
    printf("%lld\n", answer.ff - answer.ss); // output

    return 0;
}
