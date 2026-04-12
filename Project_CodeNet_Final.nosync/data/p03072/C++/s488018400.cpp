#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())

using namespace std;

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(){
  int64_t n;
  cin >> n;
  int64_t h;
  int64_t mx= 0;
  int t = 0;
  REP(i,n){
    cin >> h;
    if (h >= mx){
      t++;
      mx = h;
    }
  }
  cout << t << endl;
  return 0;
}

