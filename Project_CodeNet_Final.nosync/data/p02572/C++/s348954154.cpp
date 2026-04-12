#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    const ll mod =1000000007;
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n) cin >>a.at(i);
    ll ans =0;
    ll b = 0;
    rep(i,n){
        ans = (ans+a.at(i) * b)%mod;
        b = (b+a.at(i))%mod;
    }
    cout << ans << endl;
    return 0;


}