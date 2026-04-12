#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a) for(ll i=0;i<a;i++)
#define jkl ll debug = 0;
#define RREP(i,a) for(ll i=a-1;i>=0;i--)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)
#define printall(n,array) {for(ll i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> Pi;
typedef pair<ll, Pi> V;
typedef vector<ll> VE;
const ll mod = 1e9 + 7; //10^9+7

ll a[52], p[52], b[52];

ll solve(ll level, ll res){
    ll ret = 0;
    if(a[level] == res)return p[level];
    if(res == 0)return 0;
    if(res <= a[level] / 2){
        ret = solve(level-1, res-1);
    }else if(res == a[level] / 2 + 1){
        ret = p[level-1] + 1;
    }else if(res > a[level] / 2 + 1){
        ret = p[level-1] + 1 + solve(level-1, res-a[level-1]-2);
    }
    return ret;
}

int main(){
    ll n, k;
    cin >> n >> k;
    a[0] = 1;
    p[0] = 1;
    b[0] = 0;
    rep(i, 1, n+1){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
        b[i] = 2 * b[i-1] + 2;
    }
    ll level = 0;
    while(a[level] < k){level++;}
    print(solve(n, k));
}






