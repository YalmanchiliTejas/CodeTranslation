#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <assert.h>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater <>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;





// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

vector<ll> all(51);
vector<ll> p(51);

ll solve(int lvl, ll remain){
    ll ans = 0ll;
    if (lvl == 0){
        rn ans++;
    }
    if (remain >= 1){
        remain--;
    }
    
    if (remain < all[lvl-1] ){
        ans += solve(lvl-1,remain);
        rn ans;
    }
    else{
        remain -= all[lvl-1];
        ans += p[lvl-1];
    }
    
    if (remain >= 1){
        ans++;
        remain--;
    }

    if (remain < all[lvl-1] ){
        ans += solve(lvl-1,remain);
        rn ans;
    }
    else{
        remain -= all[lvl-1];
        ans += p[lvl-1];
    }
    
    if (remain >= 1){
        remain--;
    }
    
    rn ans;
}

int main(){
    int n;
    ll x;
    cin >> n >> x;

    all[0] = 1ll;
    p[0] = 1ll;
    FOR(i,1,51){
        all[i] = all[i-1]*2 + 3;
        p[i] = p[i-1]*2 + 1;
    }
    ll a = solve(n,x);

    cout << a;
}
