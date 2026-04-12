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
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
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
ll f[1000010], invf[1000010];
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
    int n; cin>>n;
    ll s=0, ans=0;
    for(int i=0; i<n; i++){
        ll a; cin>>a;
        (ans+=s*a)%=MOD;
        (s+=a)%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}