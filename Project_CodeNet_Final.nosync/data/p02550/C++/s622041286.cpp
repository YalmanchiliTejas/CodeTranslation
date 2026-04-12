/*

*/
#include <bits/stdc++.h>
using namespace std;
#define pi                       acos(-1.0)
#define fastio                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout << setprecision(12)
#define rep(i,a,n)               for (ll i=a;i<n;i++)
#define per(i,a,n)               for (ll i=n-1;i>=a;i--)
#define pb                       push_back
#define mp                       make_pair
#define all(x)                   (x).begin(),(x).end()
#define fi                       first
#define se                       second
#define SZ(x)                    ((ll)(x).size())
#define cin1(x)                  cin >> x
#define cin2(x, y)               cin >> x >> y
#define cin3(x, y, z)            cin >> x >> y >> z
#define cin4(x, y, z, z2)        in >> x >> y >> z >> z2
#define cin5(x, y, z, p, q)      cin >> x >> y >> z >> p >> q
#define cou(x)                   cout << x
#define cous(x)                  cout << x << " "
#define coul(x)                  cout << x << "\n"
#define ret(x)                   return x
#define MAX                      1000000007
#define start                    int main() {   fastio
#define finish                   ret(0); }
#define Test ll _t; cin1(_t); rep(w, 0, _t)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cntv(v,a) count(v.begin(),v.end(),a)
#define fans(x) \
    if ( x  ) coul("YES"); \
    else coul("NO")
#define mset(x, y) memset(x, y, sizeof(x))
#define fileshow  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)

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
ll Com[1005][1005];
void comfunc(){    for(ll i=0;i<=1000;i++){Com[i][0]=1;for(ll j=1;j<=i;j++){Com[i][j]=(Com[i-1][j-1]+Com[i-1][j])%mod;}}}
ll fact[13];
void factorial() {   fact[0]=1;  rep(i, 1, 12) fact[i]=(fact[i-1]*i);  }

//for phi function
//void phi_1_to_n(int n) {vector<int> phi(n + 1);phi[0] = 0;phi[1] = 1;for (int i = 2; i <= n; i++){phi[i] = i;}for (int i = 2; i <= n; i++) {if (phi[i] == i) {for (int j = i; j <= n; j += i){phi[j] -= phi[j] / i;}}}}
//for sieve function
//void sieve() {    rep(i, 2, MAX)  {  if (spf[i] == 0) {  spf[i] = i;   sie.pb(i);  }    for (ll j=0; j<SZ(sie) && i*sie[j] <= MAX && sie[j] <= spf[i]; j++)   spf[i * sie[j]] = sie[j]; }   }
bool cmp(point A, point B){   if(A.x != B.x) ret(A.x < B.x);  ret(A.y < B.y);   }
//void segUpdate(ll node, ll b, ll e, ll i, ll newvalue){    if (i > e  i < b){return;} if (b >= i && e <= i) {tree[node] = newvalue; return;} ll Left = node * 2; ll Right = node * 2 + 1;ll mid = (b + e) / 2; segUpdate(Left, b, mid, i, newvalue);segUpdate(Right, mid + 1, e, i, newvalue);tree[node] = tree[Left] + tree[Right];}
//void seqQuery(ll node, ll b, ll e, ll i, ll j){ map<ll,ll>Query; if (i > e || j < b){Query[i][j] = 0; }if (b >= i && e <= j){Query[i][j]= tree[node];} ll mid = (b + e) / 2;ll p1 = segQuery(2*node, b, mid, i, j);ll p2 = segQuery(2*node+1, mid + 1, e, i, j);Query[i][j]= p1 + p2; }
//void segPre(ll l, ll h, ll in) {  ll segTree[3*mx];   if ( l == h ){  segTree[ in ] = arr[ l ];   return;  }   ll m = (l + h) / 2; segPre(l, m, 2*in);  segPre(m+1, h, 2*in+1);    segTree[ in ] = segTree[ in*2 ]  segTree[ in*2+1 ];   segTree[ in ] = segTree[ in*2 ] ^ segTree[ in*2+1 ];    }
// head collected
// Don't use variable name as --> prev, time, _t, w, y1
// Don't use ceil and pow function

/*** Code Starts from here ***/
//-----------------------------

ll n,m,k,ok,ans,dp[1000005],a[1000005],cnt[1000005],x,y,l;

map<ll,ll>flag,pos;


int main()
{
    cin>>n>>x>>m;
    dp[1] = x;ok=0;
    cnt[1] = x;
    for(int i=2;i<=n;i++)
    {
        dp[i] = ((dp[i-1]%m)*(dp[i-1]%m))%m;


        if(!flag[dp[i]]){cnt[i]=dp[i]+cnt[i-1];flag[dp[i]]=1;pos[dp[i]]=i;}
        else {k = pos[dp[i]];y=i;ok=1;break;}
    }
    //cous(y);cous(k);
    l=k;
    a[0]=0;
    ll diff = y-k;a[1]=dp[k];k++;
    rep(i,2,diff+1){a[i] = dp[k++]+a[i-1];}
    ll sum = cnt[y-1]-cnt[l-1];
    //coul(sum);
    ll p = n-y+1;//coul(p);coul(diff);
    if(n==1 || !ok)coul(cnt[n]);
    else
    {
        ans = cnt[y-1];
        //coul(ans);
        ans += (p/(diff))*sum ;
        if(p%diff!=0)ans+= a[p%(diff)];

        coul(ans);
    }

    return 0;
}
