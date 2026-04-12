#include<bits/stdc++.h>
#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

typedef long long       ll;
typedef long double     ld;

typedef vector<int>     vi;
typedef vector<bool>    vb;
typedef vector<ll>      vll;
typedef vector<vi>      vvi;
typedef vector<vll>     vvll;
typedef vector<string>  vs;

typedef pair<int, int>  pii;
typedef pair<ll, int>   pli;
typedef pair<ll, ll>    pll;
typedef vector< pii >   vpi;
typedef vector< pll >   vpll;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

#define pb           push_back
#define mod          1000000007
#define INF          1e17
#define mini         INT_MIN
#define maxo         INT_MAX
#define eb           emplace_back
#define ff           first
#define ss           second
#define re           return 
#define endl         "\n" 

#define all(c)       c.begin(),c.end()
#define be           begin()
#define en           end()
#define sz(x)        (ll)x.size()
#define mem(a,val)   memset(a,val,sizeof(a))
#define mk(x,y)      make_pair(x,y)
#define mid(s,e)     ((s)+((e)-(s))/2) 

#define fo(i,a,b)     for(ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i,a,b)    for(ll i = (ll)(a); i >= (ll)(b); i--)
#define read(a,n)    for(int i=0;i<n;i++)cin>>a[i];
#define show(a,n)    for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
#define p2(n)        (1LL << (n))
#define deb(x) cout <<#x << " = " << x << " | " << "LINE: "<<__LINE__<< endl;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }

void add(ll &x, ll y){ x += y; if(x>=mod) x %= mod; if(x<0) x = x%mod + mod; }

//============== *** START OF CODE ***


const ll maxn = 2e5+5;
ll ans = -1e17;
ll a[maxn]; 

map<string,ll> mp;

ll go(int n,int left){
    if(left==0) re 0;
    if(n==1) re a[1];
    if(n==2) re max(a[1],a[2]);
    string temp = to_string(n) + "|" + to_string(left);
    if(mp.count(temp))return mp[temp];

    if(n&1 and left==(n+1)/2) return mp[temp] = a[n]+go(n-2,left-1);
    return mp[temp]=max(a[n]+go(n-2,left-1),go(n-1,left));
}
void solve()
{
    int n;rd(n);   
    read((a+1),n);
   
    ans = go(n,n/2);
    pp(ans);
}


void prep(){}

//=============== *** END OF CODE ***

int main(){
    speedio; cout<<fixed<<setprecision(12);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    prep();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}