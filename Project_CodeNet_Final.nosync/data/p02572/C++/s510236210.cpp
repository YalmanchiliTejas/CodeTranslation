#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

ll modpow(ll a, ll n, ll mod){
    ll ret=1;
    while(n>0){
        if(n&1) ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    ll sum2=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        sum%=MOD;
        ll nizyou=a[i]*a[i]%MOD;
        sum2+=nizyou;
        sum2%=MOD;
    }
    ll ans=0;
    ans=sum*sum%MOD;
    ans-=sum2;
    ans%=MOD;
    if(ans<0) ans+=MOD;
    ans*=modpow(2,MOD-2,MOD);
    ans%=MOD;
    cout<<ans<<endl;

}