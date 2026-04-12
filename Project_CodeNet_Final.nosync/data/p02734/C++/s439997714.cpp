/*
方針
先ず、f(L,R)について。
f(l,r)を満たす組み合わせは、f(k,r) (0<k<l)も満たすので重複が出る。
今回は動的計画法(DP)を使うが、f(1,r)はa_1からa_rまでの要素からsを作る組み合わせである一方、
f(2,r)はa_2からa_rまでの要素からsを作る組み合わせになる。
つまり、f(2,r)はf(1,r)を求めるDPの途中(a_2以降)で、ついでに計算することができる。
更にrについては、f(~,N)を計算する途中のrにおいて合計がsになっている組み合わせを出力すればいい。
つまり、DPに必要なループはf(1,N)の1つになる。



*/

#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define fr(i,b,e) for(int i=(b); i!=(e); ++i)
#define rp(i,e) for(int i=0; i!=(e); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long int li;
typedef long long ll;
const int INF=1000000;
const int MOD=998244353;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int s;
    cin >> n >> s;
    vector<int> a(n);
    rp(i,n) cin >> a[i];

    vector<ll> knap(s+1);
    ll out=0;
    rp(i,n){
        ++knap.at(0);      //i回目からDPを行う時の初期値
        for(int j=s-a.at(i); j>=0; --j){
            knap.at(j+a.at(i))+=knap.at(j)%MOD;
        }
        out+=knap.at(s);
    }

    cout << out%MOD << '\n' ;
}   