#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
//
//using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*** Typedef ***/
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef    long double   ld;

//typedef    unordered_set<ll>   usll;
//typedef    unordered_multiset<ll>   umsll;

/*** Loops ***/
#define ffit(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)
#define F(a,b) for(int i = a; i < b; i++)
#define ff1(i,a,b) for(ll i = a; i < b; i++)
#define ff2(i,a,b) for(ll i = b-1; i >= a; i--)
#define ff3(i,a,b,m) for(ll i = a; i <b; i+=m)
#define ipar(ar,n) ll ar[n]; ff1(i,0,n) cin>>ar[i];
#define opar(ar,n) ff1(i,0,n) cout<<ar[i]<<" ";
#define foRev(num) for(ll i = num - 1; i >= 0; i--)
#define forIn(arr, num) for(ll i = 0; i < num; i++) sc1(arr[i]);
#define forIn1(arr, num) for(ll i = 1; i <= num; i++) sc1(arr[i]);
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');

/*** Define Values ***/

#define PI acos(-1.0)
#define eps 1e-7
#define size1 15

/*** STLs ***/
#define cu continue
#define br break
#define rsz resize
#define ins insert
#define ft front
#define bk back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define MN3(n1,n2,n3) min(n1,min(n2,n3))
#define MN4(n1,n2,n3,n4) min(n1,min(n2,min(n3,n4)))
#define MX3(n1,n2,n3) max(n1,max(n2,n3))
#define MX4(n1,n2,n3,n4) max(n1,max(n2,max(n3,n4)))
#define mxar(a,n) *max_element(a,a+n)
#define mnar(a,n) *min_element(a,a+n)
#define arr_sm(a,n) accumulate(a,a+n,0)
#define vc_sm(ve) accumulate(ve.begin(),ve.end(),0)
#define mx_vc(ve) *max_element(ve.begin(),ve.end())
#define mn_vc(ve) *min_element(ve.begin(),ve.end())
//#define endl " \n"

/*** STLs ***/
typedef vector <ll> vll;
#define vvll vector<vll>
typedef set <ll> sll;
typedef multiset <ll> msll;
//typedef multimap <ll> mpll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll, ll> > vpll;
typedef priority_queue <pair <ll, ll> > pqpll;
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ml unordered_map<ll,ll>
///typedef    unordered_multiset<int>   umsi;
typedef    unordered_set<ll>   us;


///vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns, with value 500.

/*** Sorts ***/
#define czero(n)                    __builtin_popcountll(n) // count the number of 1's in the bit representation of a number
#define cenzero(n)                  __builtin_ctzll(n) // count the number of zereos from the end of the bit representation of a number until a 1
#define countbegzero(n)             __builtin_clzxll(n)
#define checkparity(n)              __builtin_parityll(n)// checks whether the number of bits are even or odd
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtgrt(v) sort(all(v), greater<ll>())
#define prsrt greater<pair<int,int>>()
/*** Some Prints ***/
#define ip(n) ll n; cin>>n;
#define ipp(n,k) ll n; cin>>n; ll k; cin>>k;
#define ip3(n,m,k) ll n; cin>>n;ll m;cin>>m; ll k; cin>>k;
#define kl    '\n'
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define case cout << "Case " << t++ << ": ";
#define ps(x,y)         fixed<<setprecision(y)<<x
#define inf             1e18
#define w(x)             ll x; cin>>x; while(x--)
#define go(i, a) for (auto &i : a)
#define go1(it, v) for(auto it = v.begin(); it != v.end(); ++it)
#define mk(arr,n,type) type *arr=new type[n];
#define sz(obj) (int(obj.size()))
#define ipve(vc,n) vll vc(n); ff1(i,0,n){cin>>vc[i];}
#define ipvc(vc,n) vll vc; ff1(i,0,n){ip(x);vc.pb(x);}
#define cer cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define depressed()                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//bool ans = all_of(arr, arr + 6, [](int x) {return x & 1; } );
const double pi = 3.141592653589793238460;
#define TRC
#ifdef TRC
#define trc(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trc(...)
#endif
void fun()
{
  ip(n);
  if(n<30) cout<<"No";
  else cout<<"Yes";
}

int main()
{
//     ofstream cout ("ride.out");
//     ifstream cin ("ride.in");
    depressed();
  ll t = 1;
  //cin>>t;
  while(t--)
  {
     fun();
  }
  //cer;
  return 0;
}
