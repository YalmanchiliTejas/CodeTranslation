#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct town{
  int x, y, num;

  town(int xx, int yy, int nn) : x(xx), y(yy), num(nn) {}

  bool operator < (const town& oth) const {
  if(x != oth.x) return x < oth.x;
  else if(y != oth.y) return y < oth.y;
  return num < oth.num;
  }
};

struct edge{int from, to, cost;

  edge(int f, int t, int c) : from(f), to(t), cost(c) {}

  bool operator < (const edge& oth) const {
    if(cost != oth.cost) return cost < oth.cost;
    else if(from != oth.from) return from < oth.from;
    return to < oth.to;
  }

};

vector<town> g;
vector<edge> s;
int n;
int par[100005];
int Rank[100005];
ll ans;
void init(int n) {
  for(int i = 0; i < n; i++) {
    par[i] = i;
    Rank[i] = 0;
  }
}

int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}

void Union(int x, int y) {
  int a = find(x);
  int b = find(y);
  if(a == b) return;

  if(Rank[a] > Rank[b]) par[b] = a;
  else {
    par[a] = b;
    if(Rank[a] == Rank[b]) Rank[b]++;
  }
}

int main() {
  cin >> n;
  init(n);
  for(int i = 0; i < n; i++) {
    int x,y;
    cin >> x >> y;
    g.push_back(town(x,y,i));
  }
  sort(g.begin(),g.end());

  for(int i = 1; i < n; i++) {
    int c = min(abs(g[i].x - g[i-1].x),abs(g[i].y - g[i-1].y));
    s.push_back(edge(g[i].num,g[i-1].num,c));
  }
  for(int i = 0; i < n; i++) swap(g[i].x,g[i].y);

  sort(g.begin(),g.end());

   for(int i = 1; i < n; i++) {
    int c = min(abs(g[i].x - g[i-1].x),abs(g[i].y - g[i-1].y));
    s.push_back(edge(g[i].num,g[i-1].num,c));
  }
  
   sort(s.begin(),s.end());
  
   for(int i = 0; i < s.size(); i++) {
     
     int u = s[i].from;
     int v = s[i].to;
     int C = s[i].cost;
   
     if(find(u) != find(v)) {
       Union(u,v);
       ans += C;
     }
   }

   cout << ans << endl;
}
  /*for(int i = 0; i < n; i++) {
  cout << g[i].x <<"   "<<g[i].y<<"   "<<g[i].num<< endl;
 }
 }*/
