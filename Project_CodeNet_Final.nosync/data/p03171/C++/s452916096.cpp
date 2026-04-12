#include <bits/stdc++.h>
#include <numeric>
#define M 1000000007
#define inf 1e18+1
#define pb push_back
// #define mp make_pair
#define forz(i,s,n) for(lli i=s;i<n;i++)
#define fore(i,n,s) for(lli i=n;i>=s;i--)
#define shaktimaan ios_base ::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef long long int lli;
//typedef pair<long long int, long long int> pll;
typedef unsigned long long int ull;
using namespace std;
 
lli recpow(lli x, lli n, lli mod)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return recpow((x * x) % mod, n / 2, mod);
    else //n is odd
        return (x * recpow((x * x) % mod, (n - 1) / 2, mod)) % mod;
}
 
lli mem[5001][5001], n, a[5001];
 
lli dp(lli i, lli j)
{
    if(mem[i][j]!=-1)
    return mem[i][j];
    if(i==j)
    return mem[i][j]=a[i];
    if(j-i==1)
    return mem[i][j]=max(a[i],a[j]);
    return mem[i][j] = max(a[i]+min(dp(i+1,j-1),dp(i+2,j)), a[j]+min(dp(i+1,j-1),dp(i,j-2)));
}
 
//code begins here
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    shaktimaan
    //sieve();
    cin>>n;
  	lli sum=0;
    forz(i,0,n)
    cin>>a[i], sum+=a[i];
    forz(i,0,n+1)
    forz(j,0,n+1)
    mem[i][j]=-1;
    cout<<2*dp(0,n-1)-sum;
    return 0;
}