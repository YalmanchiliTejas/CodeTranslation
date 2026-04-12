//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	 printf
#define sf			 scanf
#define pb(a)        push_back(a)
#define mp			 make_pair
#define ff			 first
#define ss			 second
#define for0(i,n)    for(ll i=0;i<n;i++)
#define for1(i,n)    for(ll i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define sq(a)		 (a)*(a)
#define endl		     "\n"
#define abs(x)		 fabs(x)
#define all(v) 		 v.begin(),v.end()
#define pcase(z,x)   cout<<"Case "<<z<<": "<<x<<"\n"
#define mod 1000000007
#define WakandaForever     ios_base::sync_with_stdio(0); cin.tie(0);

int main()
{
    WakandaForever
    ll n,sum=0;
    cin>>n;
    vi a(n),suf(n+1);
    for0(i,n) cin>>a[i];
    suf[n] = 0;
    for(ll i=n-1 ; i>=0 ; i--){
        suf[i] = (a[i] + suf[i+1])%mod;
    }
    for0(i,n){
        ll x = (a[i]%mod * suf[i+1]%mod)%mod;
        sum = (sum + x) % mod;
    }

    cout<<sum<<endl;


    return 0;
}
