#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD=1e9+7;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
	return powmod(a, MOD-2);
}
ll f[1500001], invf[1500001];
void fac(int n){
    f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    invf[n]=inv(f[n]);
    for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
}
ll comb(int x, int y){
    if(x<y) return 0;
    return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
    ll n, m, k; cin>>n>>m>>k;
    ll s1=0, s2=0;
    for(ll i=1; i<n; i++){
        s1+=i*(n-i);
    }
    for(ll i=1; i<m; i++){
        s2+=i*(m-i);
    }
    ll c=1;
    for(ll i=1; i<=k-2; i++){
        c*=((n*m-1-i)%MOD);
        c%=MOD;
        c*=inv(i);
        c%=MOD;
    }
    ll ans=m*m%MOD*s1%MOD+n*n%MOD*s2%MOD;
    ans*=c;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}