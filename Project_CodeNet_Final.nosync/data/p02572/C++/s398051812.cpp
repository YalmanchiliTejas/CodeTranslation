/**
*
* Author: MARS
* Lang: GNU C++14
*
**/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair<int,int>

typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl pi = acos(-1);
const ll inf = 1LL<<30;
const dbl eps = 1e-9;
const ll mod = 1e9+7;

/** /////////// ** Code ** /////////// **/

const int N=200200;
ll a[N];

int main(){
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=0 ; i<n ; i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }

    ll ans=0;
    for(int i=0 ; i<n ; i++){
        sum-=a[i];
        ans+=(sum%mod*a[i]%mod)%mod;
        ans%=mod;
    }

    printf("%lld",ans);
}
