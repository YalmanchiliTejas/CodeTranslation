 #include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repbit(n) for(ll bit=0,bit<(1<<n),bit++)
inline constexpr int intpow(ll a,ll b){
    if(b==0) return 1;
    ll ans=intpow(a,b/2);
    return ans*ans*(b&1?a:1);
}
inline constexpr int modpow(ll a,ll b){
    if(b==0) return 1;
    ll ans=intpow(a,b/2);
    return ans*ans%MOD*(b&1?a:1)%MOD;
}
int main(){
    ll n,k;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>k;
    rep(i,0,n){
        if(s[i]==s[k-1]) t[i]=s[k-1];
        else t[i]='*';
    }
    rep(i,0,n) cout<<t[i];

}