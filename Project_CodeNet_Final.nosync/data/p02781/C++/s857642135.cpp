//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

ll comb(ll x,ll y){
  if(y == 1)return x;
  ll ans = 1;
  rep(i,y)ans *= x-i;
  for(int i = 1;i <= y;i++) ans /= i;
  return ans;
}

int main(){
  string N;
  cin >> N;
  ll K;
  cin >> K;
  ll ans = 0;
  ll keta = N.size();

  for(int i = 1;i < keta;i++){
    if(K == 1){
      ans += 9;
    }else if(K == 2){
      if(i >= 3){
        ans += 81*comb(i-1,1);
      }else if(i == 2){
        ans += 81;
      }else{
        continue;
      }
    }else{
      if(i == 3){
        ans += 729;
      }else if(i > 3){
        ans += 729*comb(i-1,2);
      }else{
        continue;
      }
    }
/*
    if(i >= K){
      if(i == K){
        ll add = 1;
        rep(j,K)add *= 9;
        ans += add;
      }else if(i == K+1){
        ll add = 1;
        rep(j,K)add *= 9;
        ans += add*(i-1);
      }else{
        ll add = 1;
        rep(j,K)add *= 9;
        ans += add*comb(i-1,K-1);
        //ans += add;
      }
    }else{
      continue;
    }
    */
  }
//return 0;
  vector<int> num(keta+1,0);
  for(int i = 1;i <= keta;i++)num[i] = (int)(N.at(i-1)-'0');

  //cout << ans << endl;

  if(K == 1)ans += num[1];

  if(K == 2){
    ans += (num[1]-1)*(keta-1)*9;
    /*
    for(int a = 2;a <= keta;a++){
      ans += num[a];
    }
    */
    //cout << ans << endl;
    for(int f = 2;f <= keta;f++){
      if(num[f] == 0)continue;
      else if(f == keta && num[f] > 0)ans += num[keta];
      else{
        if(num[f] > 0){
          ans += 9*comb(keta-f,1);
          ans += num[f];
          break;
        }
      }
    }
  }

  if(K == 3){
    ans += (num[1]-1)*comb(keta-1,2)*81;
    ll s = 0;
    for(int f = 2;f <= keta;f++)if(num[f] > 0){
      s = f;
      break;
    }
    if(s == 0){
      cout << ans << endl;
      return 0;
    }
    if(s == keta)ans += 0;
    else if(keta-1 == s){
      ans += (num[s]-1)*9;
      ans += num[keta];
      cout << ans << endl;
      return 0;
    }else{
      ans += 81*comb(keta-s,2);
      ans += (num[s]-1)*(keta-s)*9;
      for(int ss = s+1;ss <= keta;ss++){
        if(num[ss] == 0)continue;
        else if(ss == keta && num[ss] > 0)ans += num[keta];
        else{
          if(num[ss] > 0){
            ans += 9*comb(keta-ss,1);
            ans += num[ss];
            break;
          }
        }
      }
    }


  }

  cout << ans << endl;



return 0;
}
