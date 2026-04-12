#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <bitset>
using namespace std;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rrep(i,a,n) for(ll i=n;i>=a;i--)
#define elif else if
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF = 1e+17;
const ll MODcdf = 998244353;
bool pairCompare(const P& firstElof,const P& secondElof){
    return firstElof.first<secondElof.first;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;cin>>n;
    ll h[n];
    rep(i,0,n)cin>>h[i];
    ll high=h[0];
    ll ans=1;
    rep(i,1,n){
        if(h[i]>=high){
            ans++;
            high=h[i];
        }
    }
    cout<<ans<<endl;
}
