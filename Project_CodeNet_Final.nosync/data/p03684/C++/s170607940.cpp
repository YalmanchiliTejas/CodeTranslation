#include <bits/stdc++.h>


using namespace std;
typedef pair<int,int> P;
int n;
P x[100001];
P y[100001];
int p[100001];
int r[100001];

void init(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    r[i] = 0;
  }
}

int Find(int x) {
  return p[x] == x ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if(a == b) return;
  if(r[x] > r[y])  p[y] = x;
  else {
    p[x] = y;
    if(r[x] == r[y]) r[x]++;
  }
}
    
				 
			  
struct edge{
  int cost,from,to;

  edge(int c, int f, int t) : cost(c),from(f),to(t) {}
    
};

bool operator < (const edge& x, const edge& y) {
    return x.cost < y.cost;
  }

vector<edge> e;
int main() {
  cin >> n;
  init(n);
  for(int i = 0; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    x[i] = P(xx,i);
    y[i] = P(yy,i);
  }
  sort(x,x+n);
  sort(y,y+n);
  for(int i = 1; i < n; i++) {
    e.push_back(edge(abs(x[i].first - x[i-1].first),x[i-1].second,x[i].second));
    e.push_back(edge(abs(x[i].first - x[i-1].first),x[i].second,x[i-1].second));    e.push_back(edge(abs(y[i].first - y[i-1].first),y[i-1].second,y[i].second));
    e.push_back(edge(abs(y[i].first - y[i-1].first),y[i].second,y[i-1].second));
  }

  sort(e.begin(),e.end());
      

  /*for(int i = 0; i < e.size();i++) {
    cout << e[i].cost <<"   "<<e[i].from<<"   "<<e[i].to<<endl;
    }*/
  long long int ans = 0;

  for(int i = 0; i < e.size(); i++) {
    if(Find(e[i].from) != Find(e[i].to)) {
      //cout << Find(e[i].from) <<"   "<<Find(e[i].to)<<endl;
      // cout << e[i].cost <<"   "<<e[i].from<<"   "<<e[i].to<< endl;
      ans += e[i].cost;
      //cout << ans << endl;
      Union(Find(e[i].from),Find(e[i].to));
    }
  }

  cout << ans << endl;
  
}

  
    
  
