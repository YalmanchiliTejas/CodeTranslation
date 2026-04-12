//AUTHOR - NAVEEN KUMAR(@naveen19991124)
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#inlcude<boost/multiprecision/cpp_dec_float.hpp>
#define ll long long
#define ld long double
#define F first
#define S second
#define nl "\n"
#define mem(v) memset(v,0,sizeof(v))
#define all(v) v.begin(), v.end()
#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(),v.rend())
#define pb push_back
#define f(a) for(ll i = 0;i<a;i++)
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define rrep(i,a,b) for(ll i = a;i>b;i--)
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector< pair<ll,ll> >
#define mp make_pair
#define trace(a) cout<<a<<"\n";
#define trace2(a,b) cout<<a<<" "<<b<<"\n";
#define trace3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define dbgarr(a) for(auto y:a){cout<<y<<" ";}cout<<"\n";
#define dbgparr(a) for(auto y:a){cout<<y.F<<" "<<y.S<<"\n";}cout<<"\n";
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define hell 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using namespace std:: chrono;
//using boost :: multiprecision :: cpp_int;
//using boost :: multiprecision :: cpp_dec_float_50;
//using boost :: multiprecision :: cpp_dec_float_100;


//Debug section
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

//Power functions
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;
a *= a; a %= mod;} return p % mod;}

//Mod functions
ll modInverse(ll a, ll m) { ll m0 = m; ll y = 0, x = 1; 
if (m == 1) {return 0;} 
while (a > 1) { ll q = a / m; ll t = m;  m = a % m, a = t; t = y; y = x - q * y; x = t; } 
if (x < 0) {x += m0;} return x; } 

inline ll add(ll a, ll b) { return (((a >= hell) ? a % hell : a) + ((b >= hell) ? b % hell : b) + hell) % hell; }
inline ll subt(ll a, ll b) { return (a - b + hell) % hell; }
inline ll mult(ll a, ll b) { return (1ll * ((a >= hell) ? a % hell : a) * ((b >= hell) ? b % hell : b)) % hell; }


//Miscellaneous
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll mylog(ll n,ll b)
{ll i = 1;ll ans = 0;
while(1)
{if(i>n/b){break;} i = i*b;ans++;}return ans;
}


//Comparators
bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b){
if (a.first == b.first)
{return a.second<b.second;} 
return a.first<b.first;
}

bool comparerev(const pair<ll,ll> &a,const pair<ll,ll> &b){
if(a.first == b.first)
{return a.second>b.second;}
return a.first>b.first;
}
#define maxx 3005
ll dp[maxx][maxx];
//MAIN CODE
int main()
{
    fast
    ll t = 1;
   // cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll arr[n+1];
    rep(i,1,n+1){
        cin>>arr[i];
    }
    for(ll right = 1;right<=n;right++)
    {
        for(ll left = right;left>=1;left--)
        {
            if(left == right)
            {
                dp[left][right] = arr[left];
            }
            else
            {
                dp[left][right] = max(arr[left]-dp[left+1][right],arr[right]-dp[left][right-1]);
            }
            
        }
    }
    cout<<dp[1][n]<<"\n";

    } 
    return 0;
}
