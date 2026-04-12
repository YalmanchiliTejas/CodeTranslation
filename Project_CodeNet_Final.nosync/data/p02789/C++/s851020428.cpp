 
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <assert.h>
#include <memory.h>
#include <time.h>
#include <bitset>
#include<iomanip>
 
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define repb(i, r, l) for (int i = (r); i > (l); i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(a, b) make_pair(a, b)
#define mt(a,b,c) make_tuple(a,b,c)
#define rank qwertyuio
#define next dfghjk
#define plus fsghsf
#define minus ytryr
#define pb push_back
#define debug(x) cerr<<#x<<": "<<(x)<<endl
using namespace std;
 
inline bool setmin(int &x, int y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(int &x, int y) { return (y > x) ? x = y, 1 : 0; }
inline bool setmin(ll &x, ll y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(ll &x, ll y) { return (y > x) ? x = y, 1 : 0; }
 
const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int mod = (int)1e9 + 7;
const int mod1 = (int)1e9 + 9;
const int mod2 = 998244353;
const int mod3 = (int)1e6+3;
const ld eps = 1e-12;
const double pi = atan2(0, -1);
const int ABC = 26;
 
 
ll binary_search(vector<ll> arr,ll val,ll l,ll r){
    ll m=l+(r-l)/2;
    if(l>=r){
        return l;
    }
    if(val<arr[m]){
        return binary_search(arr,val,l,m);
    }
    else{
        return binary_search(arr,val,m+1,r);
    }
}//return position less than
ll binary_search2(vector<ll> arr,ll val,ll l,ll r){
    ll m=l+(r-l)/2;
    if(l>=r){
        return l;
    }
    if(val<=arr[m]){//changed here
        return binary_search2(arr,val,l,m);
    }
    else{
        return binary_search2(arr,val,m+1,r);
    }
}//return position less than or equal
ll power(ll x, ll y) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % mod;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % mod; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % mod; 
    } 
    return res; 
} 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
}
ll gcdl(ll a ,ll b){ 
    if (a == 0) 
        return b;  
    return gcdl(b % a, a);  
 }

int main()
{   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(m==n){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
             
    
}