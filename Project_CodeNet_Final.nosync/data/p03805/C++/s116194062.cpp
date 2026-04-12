#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vl = vector<ll>;  // long longの1次元の型に vl という別名をつける
using vvl = vector<vl>; // long longの2次元の型に vvl という別名をつける
int MOD = 1000000007; //10^9 + 7

// 無限大の値
const ll  lINF = 1LL << 60;
const int iINF = 1 << 29;


vvi graph(8, vi(8, 0));


int bfs(int s, int n, vi visited){
  if(accumulate(visited.begin(), visited.end(), 0)==n) return 1;

  int ret = 0;
  rep(i,n){
    if(!graph[s][i] || visited[i]) continue;

    visited[i] = 1;
    ret += bfs(i, n, visited);
    visited[i] = 0;
  }

  return ret;
}

int main(void){
  int n,m;
  cin >> n >> m;
  

  int a,b;
  rep(i,m){
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = 1;
  }

  vi visited(n);
  visited[0] = 1;
  cout << bfs(0, n, visited) << endl;
  return 0;
}