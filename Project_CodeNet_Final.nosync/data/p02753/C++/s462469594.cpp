/*

*/
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((ll)(x).size())
#define cin1(x) cin >> x
#define cin2(x, y) cin >> x >> y
#define cin3(x, y, z) cin >> x >> y >> z
#define cin4(x, y, z, _) cin >> x >> y >> z >> _
#define cin5(x, y, z, p, q) cin >> x >> y >> z >> p >> q
#define cou(x) cout << x
#define cous(x) cout << x << " "
#define coul(x) cout << x << "\n"
#define ret(x) return x
#define MAX 5000001
#define start int main() {   fastio
#define finish ret(0); }
#define Test ll _t cin1(_t); rep(i, 0, _t)

struct point{    int x, y, ind;   char ch;  };
typedef long long ll;
typedef vector<ll> VI;
typedef pair<ll,ll> PII;
typedef double db;
//mt19937 mrand(random_device{}());
const ll mod=1000000007;
//ll rnd(ll x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}ret(res);}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll fact[13];
void factorial() {   fact[0]=1;  rep(i, 1, 12) fact[i]=(fact[i-1]*i);  }
vector <ll> sie; //for sieve function
ll spf[MAX+7];  //for sieve function
void sieve() {    rep(i, 2, MAX)  {  if (spf[i] == 0) {  spf[i] = i;   sie.pb(i);  }    for (ll j=0; j<SZ(sie) && i*sie[j] <= MAX && sie[j] <= spf[i]; j++)   spf[i * sie[j]] = sie[j]; }   }
bool cmp(point A, point B){   if(A.x != B.x) ret(A.x < B.x);  ret(A.y < B.y);   }
// head collected

ll n, m, _, __, u, v;
string str;
char ara_a[55][55];
char ara_b[55][55];

bool check(ll u, ll v){
    rep(i, 1, m+1)
        rep(j, 1, m+1)
            if( ara_b[ i ][ j ] != ara_a[ i + u - 1 ][ j + v - 1 ] )
                ret(false);

    ret(true);
}

bool solve()
{
    rep(i, 0, n-m+1)
        rep(j, 0, n-m+1)
            if ( ara_a[ i ][ j ] == ara_b[ i ][ j ] )
                if( check(i, j) )
                    ret(true);

    ret(false);
}

start;

    cin1(str);

    if( str[ 0 ] == str[ 1 ] && str[ 1 ] == str[ 2 ])
        coul("No");
    else
        coul("Yes");


finish
