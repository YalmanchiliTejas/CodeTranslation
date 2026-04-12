#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
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
  int64_t h,w;
  cin >> h >> w;
  vector<vector<char>> vec(h, vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> vec.at(i).at(j);
    }
  }
  rep(i,h){
    bool chk = false;
    rep(j,w){
      if (vec.at(i).at(j) == '#'){
        chk = true;
        break;
      }
    }
    if (!chk){
      vec.at(i).at(0) = '1';
    }
  }
  rep(j,w){
    bool chk = false;
    rep(i,h){
      if (vec.at(i).at(j) == '#'){
        chk = true;
        break;
      }
    }
    if (!chk){
      if (j==0 && vec.at(0).at(0) == '1'){
        vec.at(0).at(j) = '3';
      }else if (j==0){
        vec.at(0).at(j) = '2';
      }else{
        vec.at(0).at(j) = '1';
      }
    }
  }
  int cnt = 0;
  rep(i,h){
    rep(j,w){
      if (i!=0 && j==0 && cnt > 0){
        cout << endl;
        cnt = 0;
      }
      if (i == 0){
        if (vec.at(0).at(0) == '3' || vec.at(0).at(0) == '1'){
        }else{
          if(vec.at(0).at(j) != '1'){
            cout << vec.at(i).at(j);
            cnt++;
          }
        }
      }else if (j == 0){
        if (vec.at(0).at(0) == '3' || vec.at(0).at(0) == '2'){
        }else{
          if(vec.at(i).at(0) != '1'){
            cout << vec.at(i).at(j);
            cnt++;
          }
        }
      }else if(vec.at(i).at(0) != '1' && vec.at(0).at(j) != '1'){
        cout << vec.at(i).at(j);
        cnt++;
      }
    }
  }
  cout << endl;
  return 0;
}

