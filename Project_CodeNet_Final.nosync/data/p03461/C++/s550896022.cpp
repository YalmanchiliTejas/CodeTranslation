#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
  int u, v, w;
  Edge(){}
  Edge(int u, int v, int w){
    this -> u = u;
    this -> v = v;
    this -> w = w;
  }
};
bool operator<(const Edge& a, const Edge& b){
  return tie(a.u, a.v, a.w) < tie(b.u, b.v, b.w);
}
bool operator==(const Edge& a, const Edge& b){
  return tie(a.u, a.v, a.w) == tie(b.u, b.v, b.w);
}
string conv(int w){
  if(w == -1)
    return "X";
  else if(w == -2)
    return "Y";
  else
    return to_string(w);

}
int main(){
//  freopen("connect.in", "r", stdin);
//  freopen("connect.out", "w", stdout);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int a, b;
  cin >> a >> b;
  int arr[10][10];
  for(int i = 0;i < a;i++)
    for(int j = 0;j < b;j++)
      scanf("%d", arr[i] + j);
  for(int i = 0;i < a;i++){
    for(int j = 0;j < b;j++){
      if(i && arr[i][j] < arr[i - 1][j]){
        cout << "Impossible";
        return 0;
      }
      if(j && arr[i][j] < arr[i][j - 1]){
        cout << "Impossible";
        return 0;
      }
    }
  }
//  assert(false);
  vector<Edge> es;
  for(int i = 0;i < 100;i++){
    es.push_back(Edge(i, i + 1, -1));
  }
  es.push_back(Edge(100, 101, 100));
  for(int j = 0;j < 100;j++)
    es.push_back(Edge(100 + j + 1, 100 + j + 2, -2));
  int cur = 202;
  for(int i = 0;i < a;i++){
    for(int j = 0;j < b;j++){
      int x, y;
      x = i + 1;
      y = j + 1;
      bool done = 0;
      for(int c = 0;c <= 100;c++){
        for(int nx = 0;nx <= 100;nx++){
          int ny = (arr[i][j] - nx * x - c) / y;
          if((arr[i][j] - nx * x - c) % y || ny < 0)
            continue;
          bool good = 1;
          for(int k = 0;k < a;k++){
            for(int m = 0;m < b;m++){
              if(c + nx * (k + 1) + ny * (m + 1) < arr[k][m]){
                good = 0;
                break;
              }
            }
            if(!good)
              break;
          }
          if(good){
            es.push_back(Edge(nx, 201 - ny, c));
            done = 1;
            break;
          }
        }
        if(done)
          break;
      }
      if(!done){
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  sort(es.begin(), es.end());
  es.erase(unique(es.begin(), es.end()), es.end());
  cout << "202 " << es.size() << endl;
  for(auto el : es){
    cout << el.u + 1 << ' ' << el.v + 1 << ' ' << conv(el.w) << endl;
  }
  cout << "1 202";
}
