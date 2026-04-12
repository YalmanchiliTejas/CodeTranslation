#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

int main(){
  ll N,X,M; cin >> N >> X >> M;


  if(N==1){
    cout << X << endl;
    return 0;
  }
  vector<ll> nxt(M,0);
  for(ll i=0;i<M;i++){
    nxt[i] = i*i%M;
  }

  vector<ll> cnt(M+10,0);
  vector<ll> sum(M+10,0);
  vector<ll> res(M+10,-1);
  ll now = X;
  cnt[X]++;
  sum[1] = X;
  res[0]=X;
  ll l=-1,r=-1;
  for(ll i=1;i<=M;i++){
    res[i] = now = nxt[now];
    if(cnt[now]!=0 && r==-1){
      r = i;
    }
    cnt[now]++;
    sum[i+1] = sum[i]+now;
  }
  rep(i,M+1){
    if(res[i]==res[r] && l==-1){
      l = i;
    }
  }
  ll ans=0;
  if(r==-1){
    ans = sum[N];
  }
  else{
    ll lng = r-l;
    ll tim = (N-l)/lng;
    ans = sum[l];
    ans += tim*(sum[r]-sum[l]);
    for(ll i=0;l+lng*tim+i<N;i++){
      ans += res[l+i];
    }
  }

  cout << ans << endl;

  return 0;
}
