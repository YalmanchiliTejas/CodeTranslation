/*╔═══╗──╔╗╔╗───────────────────╔╗────────╔═══╦═══╗
  ║║─║╠╗╠╗╔╣╚═╦══╦═╗╔╦╗╔═╗╔══╦══╣╚═╦╦══╦══╣║─║║║─╚╝
  ║╔═╗║╚╝║╚╣║║║╚╝║║─╔╦╗║║║║╚╝║╚╝║╚╝║║║═╬══║╔═╗║╚╩═║
  ╚╝─╚╩══╩═╩╝╚╩══╩╝─╚╩╝╚╝╚╩══╩══╩══╩╩══╩══╩╝─╚╩═══╝*/

#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pdbs;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/
//#define int long long

using namespace std;

#define f(i,k,n) for(i=k;i<n;i++)
#define fd(i,k,n) for(i=k;i>n;i--)
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define umap unordered_map
#define all(c) c.begin(),c.end()
#define sz(c) (int)c.size()
#define si(c) (int)c.size()
#define lb lower_bound
#define ub upper_bound
#define gi greater<int>
#define rev reverse
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define imp cout << "IMPOSSIBLE" << endl
#define nl cout << endl
#define hello cout << "hello" << endl
#define sp(x) fixed << setprecision(x)
#define re return
#define p_q priority_queue
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


//debugging
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const double pi = 3.14159265359;
const ll mod = 1000000007;
const ll modc = 998244353;

ll inline power(ll a, ll b, ll p){
    a %= p;
    ll ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}

ll mod_inv(ll n, ll p){
    return power(n,p-2, p);
}

bool inline isPrime(ll n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}
template<typename... T>
void W(T&&... args)
{
	((cout << sp(9) <<  args << " "), ...);
	nl;
}
template<typename... T>
void R(T&&... args)
{
	((cin >> args), ...);
}
ll ston(string s) 
{
	ll a = 0;
	reverse(s.begin(),s.end());
	ll pow = 1;
	for(int i=0;i<s.size();i++)
	{
		a += pow*(s[i]-'0');
		pow*=10;
	}
	return a;
}
template <class T>
string to_binary(T n) 
{
	string binaryNum;
	int i = 0;
	while (n > 0) {
		binaryNum.pb((n % 2)+'0');
		n = n / 2;
		i++;
	}
	reverse(binaryNum.begin(),binaryNum.end());
	return binaryNum;
}
template<class T>
void wv(T &v)
{
	for(auto x : v)
		cout << x << " " ;
	nl;
}
template<class T>
void rv(T &v)
{
	for(int i=0;i<sz(v);i++)
		cin >> v[i];
}

//to safe_guard unordered_map<> in STL
//now declare something as unordered_map<int,int,custom_hash>mp :)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

/*
 * USING WITH STRUCT 
   Define a structure .
   Initialize variables in structure.
   Define another structure of type compare.(don't use bool operator < for stl containers (since it is there in std namespace);
   Overload the variables of structure in compare structure.(bool operator()(arguments){} )
   Use container with compare structure. (priority queue me ulta)
*/
/*
      FUNCTIONS YOU ARE USING
    * ll inline power(ll a, ll b, ll p)
    * ll mod_inv(ll n, ll p)
    * bool inline isPrime(ll n) 
    * ll ston(string s)
    * string to_binary(T n)
*/
/* 
 *int overflow (ll vs int)
 *array out of bounds(runtime errors)
 *special cases (n=1)?
 *don't store large numbers in double(use long double instead)
 *BINARY SEARCH ??
 *BRUTE FORCE with some optimization ??
 *in compare return true if you want to place first argument before second argument(p_q me ulta)(bool operator<)(bool operator())
 *Use custom_hash with unordered_map to avoid collisions
 *Think of your approach for one more minute if it will work or not , otherwise you will end up implementing shit as always :(
 *use factor cmd to get prime factorization of something instead of writing another code for it :)
 *DO SOMETHING INSTEAD OF NOTHING
*/
const int M = 2e5;//for graph

void solve()
{
	int i,j;ll sum = 0,prod = 1;ll maxl = LLONG_MIN, minl = LLONG_MAX;int maxi = INT_MIN,mini = INT_MAX;
	int x;
	cin >> x;
	if(x >= 30)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
int32_t main()
{
	FAST;
	int t = 1;
	while(t--)
	{
		solve();
	}
} 
