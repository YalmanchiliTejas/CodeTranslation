#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{
  int from, to, cost;

  edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

bool operator < (const edge& a, const edge& b) {
  return a.cost < b.cost;
}
  
int N;
vector<P> x,y;
int p[100001];
int r[100001];
vector<edge> e;


void init(int N) {
  for(int i = 0; i < N; i++) {
    p[i] = i;
    r[i] = 0;
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
  
  if(r[a] > r[b]) p[b] = a;
  else {
    p[a] = b;
    if(r[a] == r[b]) r[b]++;
  }
  
  return true;
}

int main() {
  cin >> N;

  for(int i = 0; i < N; i++) {
    int xx, yy;
    cin >> xx >> yy;
    x.push_back(P(xx,i));
    y.push_back(P(yy,i));
  }    

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    for(int i = 1; i < N; i++) {
      e.push_back(edge(x[i].second,x[i-1].second,x[i].first-x[i-1].first));
      e.push_back(edge(x[i-1].second,x[i].second,x[i].first-x[i-1].first));
      e.push_back(edge(y[i].second,y[i-1].second,y[i].first-y[i-1].first));
      e.push_back(edge(y[i-1].second,y[i].second,y[i].first-y[i-1].first));
    }
    
 sort(e.begin(),e.end());
 /* for(int i = 0; i < e.size(); i++) {
    cout <<e[i].from<<e[i].to<<e[i].cost<<endl;
  }
 */
  init(N);
  ll ans = 0;
  for(int i = 0; i < e.size(); i++) {
     
    if(Union(e[i].from,e[i].to)) {
      ans += e[i].cost;
      //cout <<"aaa"<<endl;
     
    }
  }


  cout << ans << endl;
    
}  
