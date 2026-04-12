#include <bits/stdc++.h>  // This will work only for g++ compiler. 
#include <ext/pb_ds/assoc_container.hpp> // Used to include policy based data structure 
using namespace __gnu_pbds;  // Only for g++ compiler
using namespace std;
 
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define max(a, b)  (a > b) ?a :b  // max of 2 elements 
#define min(a, b)  (a < b) ?a :b  // min of 2 elements
 
//short hand for usual tokens
#define pb              push_back
#define fi              first
#define se              second
#define mp              make_pair
#define mii             map<int,int>
#define pqb             priority_queue<int>   // Max Heap
#define pqs             priority_queue<int,vi,greater<int> >   // Min Heap
#define setbits(x)      __builtin_popcountll(x)   // returns the number of set bits in the binary representation of x
#define zrobits(x)      __builtin_ctzll(x)   // returns the number of zeroes before the first set bit in the binary representation of x       
#define mod             1000000007   // 1e9 + 7   
#define inf             1e18   // pow(10, 18)  
#define mk(arr,n,type)  type *arr=new type[n];   // generates a dynamic array
#define w(x)            int x; cin>>x; while(x--)   // for taking test cases 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());   // used with shuffle
 
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
 
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
 
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
 
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())
 
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;   // Used to implement policy-based data structure
 
// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
 
ll moduloMultiplication(ll a, ll b){
    ll res = 0;
    a %= mod;
 
    while(b){
    	if(b & 1)
    		res = (res + a)%mod;
 
    	a = (2*a)%mod;
    	b >>= 1;
    } 
 
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    
    ll n;
    cin>>n;
    vll arr(n);
    ll totSum = 0LL;
    for0(i, n){
       cin>>arr[i];
       totSum += arr[i];
    }
 
    ll ans = 0LL;
    for(ll i = 0; i < n; i++){
        totSum -= arr[i];
        ll temp = moduloMultiplication(totSum, arr[i]);
        ans = (ans + temp)%mod;
    }
    ans = (ans + mod)%mod;
    cout<<ans;
       
    return 0;
}