#include<bits/stdc++.h>
 
using namespace std;
 
// Competetive Template:
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
// Debugging :
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ba  back
#define si size()
#define be begin()
#define en end()
#define le length()
#define mp make_pair 
#define mt make_tuple
#define fi first
#define se second
#define gcd __gcd
#define maxe *max_element
#define mine *min_element
#define deb debug
 
#define forz(i,n) for(long long int i=0;i<n;i++)
#define rep(i,k,n) for (lli i = k; i <= n; i++)
#define deci(n)  fixed<<setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n)  __builtin_ctz(n)
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
typedef pair <lli,lli> pll;
 
 
lli countGreater(lli arr[], lli n, lli k) 
{ 
    lli l = 0; 
    lli r = n - 1; 
  
    // Stores the index of the left most element 
    // from the array which is greater than k 
    lli leftGreater = n; 
  
    // Finds number of elements greater than k 
    while (l <= r) { 
        lli m = l + (r - l) / 2; 
  
        // If mid element is greater than 
        // k update leftGreater and r 
        if (arr[m] > k) { 
            leftGreater = m; 
            r = m - 1; 
        } 
  
        // If mid element is less than 
        // or equal to k update l 
        else
            l = m + 1; 
    } 
  
    // Return the count of elements greater than k 
    return (n - leftGreater); 
}
 
bool is_palin(string input)
{
if (input == string(input.rbegin(), input.rend())) 
    return true;
return false;
}

void solve()
{
    string s;
    cin>>s;
    char prev = s[0];
    bool d=false;
    forz(i,s.size())
    {
        if(s[i]!=prev)
            d =true;
        prev =s[i];
    }
    if(d)
        cout<<"Yes";
    else
        cout<<"No";
}
 
int main()
{
    kira; 
    lli t=1; //cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}