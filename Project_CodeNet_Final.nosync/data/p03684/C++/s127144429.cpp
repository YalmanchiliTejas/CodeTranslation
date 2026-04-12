#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct edge{int from, to, cost;
  edge (int f, int t, int c) : from(f),to(t),cost(c) {}
};

int N;
typedef pair<int,int> P;
bool operator < (const edge& a, const edge& b){
  return a.cost < b.cost;
}
vector<P>x,y;
vector<edge> e;
int p[100001];
int Rank[100001];

void init(int N) {
  for(int i = 0; i < N; i++) {
    p[i] = i;
    Rank[i] = 0;
  }
}

int Find(int x) {
  if(x == p[x]) return x;
  return p[x] = Find(p[x]);
}

bool Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if(a == b) return false;

  if(Rank[a] > Rank[b]) p[b] = a;

  else {
    p[a] = b;
    if(Rank[a] == Rank[b]) Rank[a]++;
  }
  return true;
}

  
int main() {
  cin >> N;

  for(int i = 0; i < N; i++) {
    int xx,yy;
    cin >> xx >> yy;
    x.push_back(P(xx,i));
    y.push_back(P(yy,i));
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  for(int i = 1; i < N; i++) {
    int xx = x[i].first - x[i-1].first;
    int yy = y[i].first - y[i-1].first;
    e.push_back(edge(x[i].second,x[i-1].second,xx));
    e.push_back(edge(x[i-1].second,x[i].second,xx));
    e.push_back(edge(y[i].second,y[i-1].second,yy));
    e.push_back(edge(y[i-1].second,y[i].second,yy));
  }
  sort(e.begin(),e.end());
  
  init(N);
  
  ll ans = 0;
  
  for(int i = 0; i < e.size(); i++) {
    if(Union(e[i].from,e[i].to))
      ans += e[i].cost;
  }
  cout << ans << endl;
}
    
    
