#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;

int main() {
  string ns; int k;
  cin >> ns;
  cin >> k;

  vi n;
  rep(i, ns.size()) n.push_back(ns[i] - '0');
  int keta = n.size();

  map<pi, int> mp;
  mp[pi{0, 0}] = 1;
  mp[pi{1, 1}] = 1;

  if (n[0] > 1){
    mp[pi{1, 0}] = n[0] - 1;
  }

  for (int kn=1;kn<keta;kn++){
    map<pi, int> new_mp;
    for(int ic=0;ic<=k;ic++) for(int b=0;b<=1;b++){
      int num = mp[pi{ic, b}];
      if (ic > k || num == 0) continue;
      if (b){
        if (n[kn]){
          new_mp[pi{ic+1, 1}] += num;
          new_mp[pi{ic, 0}] += num;
        }else{
          new_mp[pi{ic, 1}] += num;
        }

        if (n[kn] > 1){
          new_mp[pi{ic+1, 0}] += num * (n[kn] - 1);
        }
      }else{
        new_mp[pi{ic+1, 0}] += num * 9;
        new_mp[pi{ic, 0}] += num;
      }
    }
    mp = new_mp;
  }

  ll ans = mp[pi{k, 0}] + mp[pi{k, 1}];
  cout << ans << endl;

  return 0;
}