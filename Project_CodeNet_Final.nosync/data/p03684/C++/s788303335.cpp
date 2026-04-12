# include <bits/stdc++.h>

using namespace std;

typedef long long lin;
typedef long double ld;
typedef pair < int, int > pii;

const int N = int(1e6) + 5;
const int inf = (int)1e9 + 7;

int n, p[N];
vector < pair < int, pii > > edges;
vector < pair < pii, int > > xy;

int dist(pii a, pii b){
  return min(abs(a.first - b.first), abs(a.second - b.second));
}

void add_edges(){
  for(int i = 1; i < (int)xy.size(); ++i){
    edges.push_back(make_pair(dist(xy[i].first, xy[i - 1].first), make_pair(xy[i].second, xy[i - 1].second)));
  }
}

int find9(int v){
  return p[v] == v ? v : p[v] = find9(p[v]);
}

void merge9(int x, int y){
  x = find9(x), y = find9(y);
  if(x == y){
    return;
  }
  p[y] = x;
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    p[i] = i;
    int x, y;
    scanf("%d %d", &x, &y);
    xy.push_back(make_pair(make_pair(x, y), i));
  }
  sort(xy.begin(), xy.end());
  add_edges();
  for(auto &i : xy){
    swap(i.first.first, i.first.second);
  }
  sort(xy.begin(), xy.end());
  add_edges();
  lin cost = 0;
  sort(edges.begin(), edges.end());
  for(auto i : edges){
    if(find9(i.second.first) != find9(i.second.second)){
      cost += i.first;
      merge9(i.second.first, i.second.second);
    }
  }
  printf("%lld", cost);
  return 0;
}
