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
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#define popcount __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD=998244353;
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
ll f[5000001], invf[5000001];
void fac(int n){
    f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    invf[n]=inv(f[n]);
    for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
}
ll comb(int x, int y){
    if(!(0<=y && y<=x)) return 0;
    return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
    int n;
    cin>>n;
    fac(n/2);
    ll p2[5000050];
    p2[0]=1;
    for(int i=1; i<=n/2; i++) p2[i]=p2[i-1]*2%MOD;
    ll s[5000050];
    s[0]=0;
    for(int i=0; i<=n/2; i++){
        s[i+1]=(s[i]+comb(n/2, i)*p2[n/2-i])%MOD;
    }
    ll ans=0;
    for(int i=0; i<=n/2; i++){
        (ans+=comb(n/2, i)*p2[n/2-i]%MOD*(s[n/2+1]-s[n/2-i+1]+MOD))%=MOD;
    }
    ans=ans*2%MOD;
    ll p3=1;
    for(int i=0; i<n; i++) p3=p3*3%MOD;
    ans=(p3-ans+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}