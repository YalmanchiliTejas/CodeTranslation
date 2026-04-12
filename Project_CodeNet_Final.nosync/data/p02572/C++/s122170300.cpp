#include <bits/stdc++.h>
#include <map>
#include <algorithm> 
#include <vector> 
#include <string.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <chrono> 
#include <thread> 
#include <iomanip>
#include <typeinfo>
 
//define
#define trav(i,v)   for(auto i: v)
#define rep(i,n)    for(int i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(int i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define all(v)  v.begin(), v.end()
#define itn int 

//typedef
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, int > > vpp;
 
const long long MOD = 1000000007;
// const long long MOD = 998244353;
const long long inf = 100000000000000;

using namespace std;

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}

ll power(ll x, ll n)
{
    ll res=1;
    while(n>0){
        if(n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    vll v(n+1);
    ll sum=0;
    repu(i,1,n)
    {
        cin>>v[i];
        sum+=v[i];
        sum%=MOD;
    }
    ll ans=0;
    repu(i,1,n)
    {
        sum=sum+MOD-v[i];
        sum%=MOD;
        ans+=sum*v[i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1, tt=1;
    // cin>>t;
    while(tt<=t)
    {
        // cout<<"Case #"<<tt<<": ";
        solve();
        tt++;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}