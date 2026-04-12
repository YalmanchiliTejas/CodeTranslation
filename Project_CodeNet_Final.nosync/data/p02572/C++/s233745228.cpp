/*
 ALLAH is Almighty....
*/
#include <bits/stdc++.h>
using namespace std;

#define pi                            acos(-1.0)
#define fastio                        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout << setprecision(12)
#define rep(i,a,n)                    for (ll i=a;i<n;i++)
#define per(i,a,n)                    for (ll i=n-1;i>=a;i--)
#define pb                            push_back
#define mp                            make_pair
#define all(x)                        (x).begin(),(x).end()
#define fi                            first
#define se                            second
#define SZ(x)                         ((ll)(x).size())
#define cin1(x)                       cin >> x
#define cin2(x, y)                    cin >> x >> y
#define cin3(x, y, z)                 cin >> x >> y >> z
#define cin4(x, y, z, _)              cin >> x >> y >> z >> _
#define cin5(x, y, z, p, q)           cin >> x >> y >> z >> p >> q
#define cin6(x, y, z, p, q, r)        cin >> x >> y >> z >> p >> q >> r
#define cou(x)                        cout << x
#define cous(x)                       cout << x << " "
#define coul(x)                       cout << x << "\n"
#define ret(x)                        return x
#define MAX                           1000007
#define start                         int main() {   fastio
#define finish                        ret(0); }
#define Test                          ll _t; cin1(_t); rep(w, 0, _t)
#define minv(v)                       *min_element(v.begin(),v.end())
#define maxv(v)                       *max_element(v.begin(),v.end())
#define cntv(v,a)                     count(v.begin(),v.end(),a)
#define fans(x)                       if ( x  ) coul("Yes");  else coul("No")
#define mset(x, y)                    memset(x, y, sizeof(x))
#define fileshow                      freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define vs(x)                         vector < string > x
#define vi(x)                         vector < ll > x
#define vd(x)                         vector < double > x
#define lb                            lower_bound
#define ub                            upper_bound


struct point{    int x, y, ind;   char ch;  };
typedef long long ll;
typedef vector<ll> VI;
typedef pair<ll,ll> PII;
typedef long double db;
ll mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}ret(res);}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll fact[13];
void factorial() {   fact[0]=1;  rep(i, 1, 12) fact[i]=(fact[i-1]*i);  }
bool cmp(point A, point B){   if(A.x != B.x) ret(A.x < B.x);  ret(A.y < B.y);   }
vector <ll> sie; //for sieve function
ll spf[MAX+7];  //for sieve function
void sieve() {    rep(i, 2, MAX)  {  if (spf[i] == 0) {  spf[i] = i;   sie.pb(i);  }    for (ll j=0; j<SZ(sie) && i*sie[j] <= MAX && sie[j] <= spf[i]; j++)   spf[i * sie[j]] = sie[j]; }   }

//mt19937 mrand(random_device{}());
//ll rnd(ll x) { return mrand() % x;}
//void segPre(ll l, ll h, ll in) {  ll segTree[3*mx];   if ( l == h ){  segTree[ in ] = arr[ l ];   return;  }   ll m = (l + h) / 2; pre(l, m, 2*in);  pre(m+1, h, 2*in+1);    segTree[ in ] = segTree[ in*2 ] | segTree[ in*2+1 ];   segTree[ in ] = segTree[ in*2 ] ^ segTree[ in*2+1 ];    }
/*ll bfs(ll s){
    queue < ll > dq;  dq.push( s );
    while( !dq.empty() ) {
        ll u = dq.front();
        rep(i, 0, SZ( adj[ u ] ))    ll v = adj[ u ][ i ];
    }
}*/
/*------------------------------Graph Moves--------------------------
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
---------------------------------------------------------------------*/

const ll mx = 2e5 + 9;

// head collected
// Don't use variable name as --> prev, time, _t, w, y1
// Don't use ceil and pow function


ll n, a, b, _, ans, c, _1, _2, m, an, k, need, shuru, _3, _c, _a, _b, way, _0, mex, q, d, temp;
double DF, AF;
string st, st1, st2, isGood;
set < ll > ss;
vector < ll > path;
vector < ll > adj[ mx ];
bool ok;
char ch;
ll vis[ mx ], ar[ mx ], co[ mx ];




void f( )
{
    cin1( n );

    rep( i, 0, n )   cin1( ar[ i ] );
    co[ 0 ] = ar[ 0 ];
    rep( i, 1, n )  co[ i ] = co[ i - 1 ] + ar[ i ];

    rep( i, 1, n ) {
        co[ i ] %= mod;
        ans += ( co[ i - 1 ] * ar[ i ] ) % mod;
        ans %= mod;
    }

    coul( ans );
}

int main()
{
    fastio;
    //Test
        f();

    return 0;
}
