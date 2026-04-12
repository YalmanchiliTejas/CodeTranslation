#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<set>
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define REP(i,n) for(ll i=0;i<(ll)(n);i++) //REP(i, 5) cout<<i;
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define MOD 1000000007 //10^9+7
//#define MOD 1
 
ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}
 
const int MAX = 2000;

long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


void sosuu(ll n, vector<ll> &v){

  vector<ll> num(n, 0);

  FOR(i, 1, sqrt(n)){
    if(num[i]==0){
      FOR(j, 0, n/i){
        num[i+(j*i)] = 1;
      }
    }
  }
  REP(i, n){
    if(num[i]==0) v.push_back(i+1);
  }
}

ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}


int main(void){
  ll h, w;
  cin>>h>>w;
  ll count = 0;

  ll M[h][w];
  REP(i, h){
    REP(j, w){
      char x;
      cin>>x;
      M[i][j] = x;
      if(x=='#') count++;
    }
  }

  queue<pair<ll, ll>> q;
  q.push(make_pair(0, 0));
  ll V[h][w];
  REP(i, h){
    REP(j,w){
      V[i][j] = 0;
    }
  }
  V[0][0] = 1;

  while(q.size()!=0){
    pair<ll, ll> now = q.front();
    q.pop();
    ll nx = now.first;
    ll ny = now.second;
    //cout<<nx<<","<<ny<<endl;
    if(nx==h-1 && ny==w-1){
      if(count==(h+w-1)) cout<<"Possible"<<endl;
      else cout<<"Impossible"<<endl;
      return 0;
    }

    ll x, y;
    x = nx + 1;
    y = ny;
    if(x<h && y<w && M[nx][ny]=='#'){
      q.push(make_pair(x, y));
      V[x][y] = 1;
    }
    x = nx;
    y = ny+1;
    if(x<h && y<w && M[nx][ny]=='#'){
      q.push(make_pair(x, y));
      V[x][y] = 1;
    }

  }
  cout<<"Impossible"<<endl;
  return 0;
}