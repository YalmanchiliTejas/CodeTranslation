#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define ll long long 
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//typedef long long  MOD=1000000009;
ll MOD=998244353;
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll lcm(ll x, ll y) {ll res = (x * y) / __gcd(x, y); return res;}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}

void iofoj(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}


void solution()
{
    ll k,i,j,h,m,w,n;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
    cin>>a[i];
    ll sum[n+2]={0};
    ll mod=1000000007;
    for(i=n;i>0;i--)
    sum[i]=sum[i+1]+a[i],sum[i]%=mod;
    ll ans=0;
    
    for(i=1;i<=n;i++)
    {
        ans+=((a[i]%mod)*(sum[i+1]%mod))%mod;
        ans%=mod;
    }
    cout<<ans;
}

int main(){
    fio
    //iofoj();
    // ll t;
    // cin>>t;
    // while(t--)
    solution();
    return 0; 
}



