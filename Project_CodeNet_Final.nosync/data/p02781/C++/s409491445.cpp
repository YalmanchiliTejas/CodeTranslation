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

struct node{
  ll num;
  int cnt;
  bool border;
};

int main() {
  string ns; int k;
  cin >> ns;
  cin >> k;

  vi n;
  rep(i, ns.size()) n.push_back(ns[i] - '0');
  int keta = n.size();

  queue<node> q;
  q.push(node{1, 0, 0});
  q.push(node{1, 1, 1});
  if (n[0] > 1){
    q.push(node{n[0] - 1, 1, 0});
  }

  for (int kn=1;kn<keta;kn++){
    queue<node> new_q;
    while(!q.empty()){
      node v = q.front(); q.pop();
      // printf("num: %d, cnt: %d, b: %d\n", v.num, v.cnt, v.border);
      if (v.cnt > k) continue;
      if (v.border){
        if (n[kn]){
          new_q.push(node{v.num, v.cnt+1, 1});
          new_q.push(node{v.num, v.cnt, 0});
        }else{
          new_q.push(node{v.num, v.cnt, 1});
        }

        if (n[kn] > 1){
          new_q.push(node{v.num * (n[kn] - 1), v.cnt+1, 0});
        }
      }else{
        new_q.push(node{v.num, v.cnt, 0});
        new_q.push(node{v.num * 9, v.cnt+1, 0});
      }
    }
    // cout << endl;
    q = new_q;
  }

  ll ans = 0;
  while (!q.empty()){
    node v = q.front(); q.pop();
    // printf("num: %d, cnt: %d, b: %d\n", v.num, v.cnt, v.border);
    if (v.cnt == k) ans += v.num;
  }
  cout << ans << endl;

  return 0;
}