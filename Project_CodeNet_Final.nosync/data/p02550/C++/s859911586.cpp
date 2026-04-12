#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

ll u = 100100;

int main(){
    ll n, x, m;
    ll ans = 0;
    cin >> n >> x >> m;
    vector<ll> a(u,0);
    a[1] = x;
    ans += a[1];
    rep2(i,u){
        
        a[i+1] = a[i]*a[i]%m;
        // if(i<=5) cout << a[i] << endl;
        if(i<u-1 || i == n-1) ans += a[i+1];
        if(i == n-1) {
            cout << ans << endl;
            return 0;
        }
    }

    // uから下に向かって一致するものを探す。
    for(ll i=u-1;i>0;i--){
        if(a[i] == a[u]){
            // どこかで必ず一致するから、このカッコ内で全ての処理を行う。
            ll loopSet = 0;
            for(ll j=i;j<u;j++){
                loopSet += a[j];
            } 
            // ループの輪の長さ
            ll loopcnt = u-i;

            // u〜nでのループの回数（セットの個数）及び、余りを求める。
            ll SetNum = (n-u+1)/loopcnt;
            ll amari = (n-u+1)%loopcnt;
            // cout << "now ans:" << ans << endl; 

            ans += SetNum * loopSet;
            // cout << "now 2 ans: " << ans << endl;
            // cout << SetNum * loopSet << endl;
            for(ll j=i;j<i+amari;j++){
                ans += a[j];
            }
            cout << ans << endl; 
            // cout << "loopcnt = " << loopcnt << endl << "loopSet = " << loopSet << endl << "SetNum = " << SetNum << endl; 
            return 0;
        }
    }
}

// 632660880097787
// 492443256176507