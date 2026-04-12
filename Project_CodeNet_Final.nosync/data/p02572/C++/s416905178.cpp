// *
// *
// *  Created By :hozaifa wahid
// * "mai maut ko takia aur kafan ko chadar banakar sota hu" 
// *------------------------------------
// *  OS : Ubuntu 16.04
// *  Language : CPP14
// *  Editor : Sublime Text 3
// *  C++ compiler : g++
// *https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
// *https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
//https://www.geeksforgeeks.org/compute-ncr-p-set-2-lucas-theorem/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(n) for(int i = 0 ; i < n ;i ++)
#define repc(i, n) for(int i = 0 ; i < n ; i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b,c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a+n
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll MOD=1000000007;
ll mod=MOD;
ll C[2005][2005];
ll min(ll a,ll b)
{
 return a<b?a:b;
}
 
 
ll pw(ll a,ll b){
    if(b==0) return 1;
    ll x=pw(a,b/2);
    x=(x*x)%MOD;
    if(b%2) x=(x*a)%MOD;
    return x;
}
ll comb2(ll n,ll k, ll x)
{
ll res = 1LL; 
  
   
    if ( k > n - k ) 
        k = n - k; 
  
   
    for (int i = 0; i < k; ++i) 
    { 
        res = (res%MOD*(n - i)%MOD)%MOD; 
        res =(res%MOD* pw((i + 1),MOD-2)%MOD)%MOD; 
    } 
  
    //return res; 
return res%MOD;
}
void comb(ll n, ll k) 
{ 
    //int C[n+1][k+1]; 
    ll i, j; 
  
    // Caculate value of Binomial Coefficient in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1LL; 
  
            // Calculate value using previosly stored values 
            else
                C[i][j] = (C[i-1][j-1]%MOD + C[i-1][j]%MOD)%MOD; 
        } 
    } 
  
   // return C[n][k]; 
} 
ll phi(ll n) 
{ 
    ll result = n; // Initialize result as n 
  
    // Consider all prime factors of n and subtract their 
    // multiples from result 
    for (ll p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 
bool compare(const pair<ll,pair<ll,ll>>&a,const pair<ll,pair<ll,ll>>&b)
{
    if(a.first<b.first)
    return true;
    if(a.first==b.first)
    {
    if(a.second.first<b.second.first)
    return true;
    else if(a.second.second<b.second.second and a.second.first==b.second.first)
    return true;
    }
    else
    return false;
    
}
ull togglebit(ull n) 
{ 
    if (n == 0) 
        return 1; 
  
    // Make a copy of n as we are 
    // going to change it. 
    int i = n; 
  
    // Below steps set bits after 
    // MSB (including MSB) 
  
    // Suppose n is 273 (binary 
    // is 100010001). It does following 
    // 100010001 | 010001000 = 110011001 
    n |= n >> 1; 
  
    // This makes sure 4 bits 
    // (From MSB and including MSB) 
    // are set. It does following 
    // 110011001 | 001100110 = 111111111 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return i ^ n; 
} 
  
// Returns XNOR of num1 and num2 
ull XNOR(ull num1, ull num2) 
{ 
    // if num2 is greater then 
    // we swap this number in num1 
    if (num1 < num2) 
        swap(num1, num2);  
    num1 = togglebit(num1); 
    
    return num1 ^ num2; 
} 
  
void solve()
{
//comb(2001,2001);
std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
ll t;
//t=1;
t=1;
 
while(t--)
{
    ll n;
    cin>>n;
    ll a[n];
    ll s=0,s1=0;
    FOR(i,0,n)
    {
        cin>>a[i];
        s=(s+a[i])%mod;
        s1=(s1%mod+(a[i]*a[i])%mod)%mod;
    }
    s=(s*s)%mod;
    cout<<((s-s1+mod)%mod*pw(2,1000000005)%mod)%mod;
    
    
 
}
}
 
 
 
int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
}
 
 
 
 
 
 
 
 
 
 