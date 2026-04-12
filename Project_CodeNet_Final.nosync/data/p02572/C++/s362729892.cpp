//Bismillah Hir Rehmanir Rahim
//Allah knows best
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define mini -10000000000000000
#define start ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i, a, n) for( i=a; i<n;i++)
#define ll long long
#define pi 3.141592653589793
#define vi              vector<int>
#define si              set<int>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define deb(x)          cout << #x << " = " << x << endl
ll power(ll a, ll b)
{ a = a%mod;
    ll ans = 1;
    while(b>0)
    {
        if(b&1) {
            ans = ans*a;
            ans = ans%mod;
        }
        a = a*a;
        a = a%mod;
        b>>=1;
    }
    return ans;
}
ll bhag(ll n, ll m){
  n%= mod; m%= mod;
  ll ans = n*power(m, mod-2);
  ans%= mod;
  return ans;
}
int main()
{
    start;
    //freopen("in.txt","r",stdin);
   ll i,j,k,n,m;
   cin>>n;
   ll a[n];
   f(i,0,n) cin>>a[i];
   k=0;
   for(i=0;i<n;i++)
    {
        k+=a[i];
        k%=mod;
    }
    k=k*k;
    k%=mod;
    m=0;
    for(i=0;i<n;i++)
    {
        m+=(a[i]*a[i]);
        m%=mod;
    }
    ll ans=(k-m+mod)%mod;
   // cout<<ans/2<<endl;
    cout<<bhag(ans,2)<<endl;
    rr;
}

