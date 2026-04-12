#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 300030;
int par[MAX_N];
int rnk[MAX_N];
int n;

void init(){
  for (int i=0; i<n; i++){
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x==y) return;
  if (rnk[x]<rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x]==rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}


int main(){
  cin >> n;
  init();
  vector<vector<ll>> x(n, vector<ll>(2)), y(n, vector<ll>(2));
  for (int i=0; i<n; i++){
    cin >> x[i][0] >> y[i][0];
    x[i][1] = i; y[i][1] = i;
  }
  sort(x.begin(), x.end(), [](const auto& a, const auto& b){return a[0]<b[0];});
  sort(y.begin(), y.end(), [](const auto& a, const auto& b){return a[0]<b[0];});
  vector<vector<ll>> road;
  for (int i=0; i<n-1; i++){
    road.push_back({x[i+1][0]-x[i][0],x[i][1],x[i+1][1]});
    road.push_back({y[i+1][0]-y[i][0],y[i][1],y[i+1][1]});
  }
  sort(road.begin(), road.end(), [](const auto& a, const auto& b){ return a[0]<b[0]; });
  ll cost = 0;
  ll use = 0;
  for (int i=0;;i++){
    if (use==n-1) break;
    if (!same(road[i][1], road[i][2])){
      use++;
      cost += road[i][0];
      unite(road[i][1], road[i][2]);
    }
  }
  cout << cost << endl;
}
