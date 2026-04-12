#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
 
map< int64, int > data;
 
int64 sum(int64 k)
{
  k += 1e13;
  int ret = 0;
  for(; k > 0; k -= k & -k) {
    if(!data.count(k)) continue;
    ret += data[k];
  }
  return (ret);
}
 
void push(int64 k, int x)
{
  k += 1e13;
  for(; k < 1e14; k += k & -k) data[k] += x;
}
 
int main()
{
  int64 N, A, B;
  vector< pair< int64, int64 > > T[5];
 
  cin >> N >> A >> B;
  for(int i = 0; i < N; i++) {
    int64 a, b, c;
    cin >> a >> b >> c;
    T[--a].emplace_back(b, c);
  }
 
  for(int i = 0; i < 5; i++) {
    T[i].emplace_back(0LL, 0LL);
  }
 
  map< int64, vector< pair< int64, int > > > add;
  map< int64, vector< int64 > > que;
  map< int64, vector< pair< int64, int > > > del;
 
  for(auto &s : T[0]) {
    for(auto &t : T[1]) {
      for(auto &q : T[2]) {
        int64 a = s.first + t.first + q.first;
        int64 b = s.second + t.second + q.second;
        que[a].emplace_back(b);
      }
    }
  }
 
  for(auto &s : T[3]) {
    for(auto &t : T[4]) {
      int64 a = s.first + t.first;
      int64 b = s.second + t.second;
      pair< int64, int64 > latte = {A - a, B - a};
      pair< int64, int64 > malta = {A - b, B - b};
      if(latte.first > latte.second) continue;
      if(malta.first > malta.second) continue;
      add[latte.first].emplace_back(malta.first, +1);
      add[latte.first].emplace_back(malta.second + 1, -1);
      del[latte.second].emplace_back(malta.first, -1);
      del[latte.second].emplace_back(malta.second + 1, +1);
    }
  }
 
  auto ptr = que.begin();
  auto latte = add.begin(), malta = del.begin();
 
 
  while(ptr != que.end()) {
    while(latte != add.end() && latte->first <= ptr->first) {
      for(auto &v : latte->second) {
        push(v.first, v.second);
      }
      ++latte;
    }
    while(malta != del.end() && malta->first < ptr->first) {
      for(auto &v : malta->second) push(v.first, v.second);
      ++malta;
    }
    for(auto &v : ptr->second) {
      if(sum(v) != 0) {
        cout << "Yes" << endl;
        return (0);
      }
    }
    while(malta != del.end() && malta->first <= ptr->first) {
      for(auto &v : malta->second) push(v.first, v.second);
      ++malta;
    }
    ++ptr;
  }
 
  cout << "No" << endl;
}