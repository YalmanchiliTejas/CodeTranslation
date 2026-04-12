#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define sclll(n,m,w) scanf("%lld%lld%lld",&n,&m,&w)
#define pf(a)   printf("%d\n",a)
#define CASE(a) printf("Case %d:\n",a)
#define dbg(i) printf("yo %lld\n", i)
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

using namespace __gnu_pbds;
using namespace std;

int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,-1,1};
//ll ncr(ll n,ll r){
    //if(n==r)return 1;
    //if(r==1)return n;
    //if(dp[n][r]!=-1)return dp[n][r];
    //return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
//}

bool checkbit(int mask,int bit){
    return mask & (1<<bit);
}
int setbit(int mask,int bit){
    return mask | (1<<bit) ;
}
int clearbit(int mask,int bit){
    return mask & ~(1<<bit);
}
int togglebit(int mask,int bit){
    return mask ^ (1<<bit);
}
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}

template <typename T> T BigMod (T b,T p,T m){
    if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m){
    return BigMod(b,m-2,m);
}
template <typename T> T in(){
    char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}
    if (ch>='0' && ch<='9')     break;}
    while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);
}
template <typename T> T POW(T B,T P){
    if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));
}
template <typename T> T Bigmod(T b,T p,T m){
    if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template <typename T> T Dis(T x1,T y1,T x2, T y2){
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}
template <typename T> T Angle(T x1,T y1,T x2, T y2){
    return atan( double(y1-y2) / double(x1-x2));
}
template <typename T> T DIFF(T a,T b) {
    T d = a-b;if(d<0)return -d;else return d;
}
template <typename T> T ABS(T a) {
    if(a<0)return -a;else return a;
}
template <typename T> T euclide(T a,T b,T &x,T &y) {
    if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
    if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
    if(b==0){x=1;y=0;return a;}
    else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
template <typename T> T gcd(T a,T b){
    if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);
}
template <typename T> T lcm(T a,T b) {
    if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));
}

template<class t>
int lwb(const vector<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

template<typename A, typename B>
class Dijkstra {
public:
    vector<vector<pair<int, A>>> vertexs;
    vector<int>par;
    B Cost_Function;
    Dijkstra(int n, B cost) : Cost_Function(cost) {
        vertexs = vector<vector<pair<int, A>>>(n, vector<pair<int, A>>{});
        par = vector<int>(n);
    }
    ~Dijkstra() {
        vertexs.clear();
    }
    void add_edge(int a, int b, A c) {
        vertexs[a].push_back(make_pair(b, c));
    }
    void clr(){par.clear(); }
    vector<ll> build_result(int StartPoint) {
        vector<ll> dist(vertexs.size(), 2e18);
        dist[StartPoint] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
        next.push(make_pair(0, StartPoint));
        while (next.empty() == false) {
            pair<ll, int> now = next.top();
            next.pop();
            if (dist[now.second] != now.first) continue;
            for (auto x : vertexs[now.second]) {
                ll now_cost = now.first + x.second;// Cost_Function(x.second);
                if (dist[x.first] > now_cost) {
                    dist[x.first] = now_cost;
                    par[x.first] = now.second;
                    next.push(make_pair(now_cost, x.first));
                }
            }
        }
        return dist;
    }
};

#define mxn 100005

const ll nax=100050;
ll n,w,m;
char ar[6][nax];
char ch[nax];
void solve()
{
    ll a,b,c,q,j,k,l,mx=0,i;
    ll hn,hm,gc,sx,sy,ex=1,ey=-1;
    cin>>n;
    scanf("%s",ch+1);
    ar[1][1]='S';ar[2][1]='S';ar[3][1]='W';ar[4][1]='W';
    char ox[7]="sSSWW";
    ar[1][n]='S';ar[2][n]='W';ar[3][n]='S';ar[4][n]='W';
    for(j=n-1;j>=1;j--){
        for(i=1;i<=4;i++){
            if(ar[i][j+1]=='S'){
                if(ch[j+1]=='o') ar[i][j]=(j==n-1)?ar[i][1]:ar[i][j+2];
                else ar[i][j]=(j==n-1)?(ar[i][1]=='S')?'W':'S':(ar[i][j+2]=='S')?'W':'S';
            }else{
                if(ch[j+1]=='x') ar[i][j]=(j==n-1)?ar[i][1]:ar[i][j+2];
                else ar[i][j]=(j==n-1)?(ar[i][1]=='S')?'W':'S':(ar[i][j+2]=='S')?'W':'S';
            }
        }
    }
    //for(i=1;i<=4;i++) {FOR(j,1,n+1){ cout<<ar[i][j]<<' ';}cout<<endl;}
    for(i=1;i<=4;i++) {
        if(ar[i][1]=='S'&&(ar[i][1]==ox[i])){
            if(ch[1]=='o'){if((ar[i][2]=='S'&&ar[i][n]=='S')||(ar[i][2]=='W'&&ar[i][n]=='W')){ey=i;break;}}
            else if((ar[i][2]=='S'&&ar[i][n]=='W')||(ar[i][2]=='W'&&ar[i][n]=='S')){ey=i;break;}
        }else if(ar[i][1]=='W'&&(ar[i][1]==ox[i]) ){
            if(ch[1]=='x'){if((ar[i][2]=='S'&&ar[i][n]=='S')||(ar[i][2]=='W'&&ar[i][n]=='W')){ey=i;break;}}
            else if((ar[i][2]=='S'&&ar[i][n]=='W')||(ar[i][2]=='W'&&ar[i][n]=='S')){ey=i;break;}
        }
    }
    if(ey==-1){cout<<ey<<'\n';return;}
    //cout<<ey<<endl;
    for(i=1;i<=n;i++) cout<<ar[ey][i];
    cout<<'\n';
}
int main()
{
    //IOS;
    double start_time = clock();
    ll t=1,mex=1;
   //cin>>t;
    while(t--){
        solve();
    }
    double end_time = clock();
    //fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}
