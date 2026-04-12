#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;
ll bitpow(ll x,ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2 == 1) ans = ans * x ;
        x = x * x ;
        n = n >> 1;
    }
    return ans;
}
int ans = 0;
int n,x;


void dfs(int lv,int y){
    cerr << lv << " " << y << endl;
    if(lv < 0){
        cerr << "error" << endl;
        return;
    }
    if(y == 0)return;
    if(y == 1 && lv != 0)return;
    if(y == 1 && lv == 0){
        ans += 1;
        return;
    }
    if(y == bitpow(2,lv+1) - 1){
        ans += bitpow(2,lv);
        return;
    }
    if(y == bitpow(2,lv+1) - 2){
        ans += bitpow(2,lv)-1;
        return;
    }
    if(y == bitpow(2,lv+2) - 3 || y == bitpow(2,lv+2) - 4){
        ans += bitpow(2,lv+1) - 1;
        return;
    }

    if(y <= bitpow(2,lv+1) - 2){
        dfs(lv-1,y-1);
    }else{
        ans += bitpow(2,lv);
        dfs(lv-1,y-(bitpow(2,lv+1) - 1));
    }
}

signed main(){

    cin >> n >> x;
    int lvn_all = bitpow(2,n+2) - 3;
    int lvn_p = bitpow(2,n+1) - 1;
    
    dfs(n,x);

    cout << ans << endl;
    
    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 