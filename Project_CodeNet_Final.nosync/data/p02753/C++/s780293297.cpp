/**
 *    Author:   Jay Sabale
 *	       
**/

#include<bits/stdc++.h>

using namespace std;
 
// Competetive Template:
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
typedef vector <lli> vl;
typedef vector <string> vs;
typedef vector < pair <long, long> > vll;

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
 
#define forz(i,n) for(lli i=0; i<n; i++)
#define rep(i,k,n) for (lli i = k; i < n; i++)
#define deci(n)  fixed<<setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n)  __builtin_ctz(n)
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

// Printing Data :
#define pvec(v) forz(i,v.si) cout<<v[i]<<" "; cout<<endl;
#define parr(arr, n) forz(i,n) cout<<arr[i]<<" "; cout<<endl;
#define p1(i) cout<<i<<endl;
#define p2(i, j) cout<<i<<" "<<j<<endl;
#define p3(i, j, k) cout<<i<<" "<<j<<" "<<k<<endl;
#define p4(i, j, k, l) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;

typedef pair <lli,lli> pll;

// Boolean Functions : 
bool isPalindrome(string str) 
{ 
    lli l = 0; 
    lli h = str.le - 1; 
  
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return false; 
        } 
    } 
 
    return true;
} 

bool isPrime(lli n)
{
    if(n==2) return true;
    
    if(n%2==0) return false;

    for(lli i=3; i<=sqrt(n); i+=2)
    {
        if(n%i==0) return false;
    }

    return true;
}

// Finds number of elements greater than k 
lli countGreater(lli arr[], lli n, lli k) 
{ 
    lli l = 0; 
    lli r = n - 1; 
  
    lli leftGreater = n; 
  
    while (l <= r) { 
        lli m = l + (r - l) / 2; 
  
        if (arr[m] > k) { 
            leftGreater = m; 
            r = m - 1; 
        } 
  
        else
            l = m + 1; 
    } 
  
    return (n - leftGreater); 
} 
 
// CODE BEGINS :

int main()
{
    kira; 

    string s; cin>>s;
    lli c1=0, c2=0;

    forz(i,s.le)
    {
        if(s[i]=='A') c1++;
        else c2++;
    }

    if(c1!=0 && c2!=0)
    cout<<"Yes"<<endl;

    else
    cout<<"No"<<endl;

    return 0;
}


















































