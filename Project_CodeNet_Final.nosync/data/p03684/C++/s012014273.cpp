#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

struct ST {
  int i;
  ll x, y;
};

bool sort_x(const ST& a, const ST& b){
  return a.x < b.x;
}
bool sort_y(const ST& a, const ST& b){
  return a.y < b.y;
}

struct DIFF {
  int a, b;
  ll diff;
};
bool operator<(const DIFF& a, const DIFF& b){
  return a.diff > b.diff;
}

class UnionFind{
  int n;
  vector<int> data;
public:
  UnionFind(int _n):n(_n),data(_n,-1){}
  bool link(int a, int b){ //if new link, then true.
    int ra=find_root(a);
    int rb=find_root(b);
    if(ra!=rb){
      if(data[rb]<data[ra]) swap(ra,rb);
      data[ra]+=data[rb];
      data[rb]=ra;
    }
    return (ra!=rb);
  }
  bool check(int a, int b){ //if same set, then true.
    return (find_root(a)==find_root(b));
  }
  int find_root(int a){
    return ((data[a]<0)?a:(data[a]=find_root(data[a])));
  }
};



int main(){
  int N;
  cin >> N;
  vector<ST> v;
  rep(i,N){
    ST st;
    st.i = i;
    cin >> st.x >> st.y;
    v.push_back(st);
  }

  UnionFind uf(N);
  priority_queue<DIFF> que;
  
  sort(ALLOF(v), sort_x);
  rep(i,N-1){
    DIFF diff;
    diff.a = v[i].i;
    diff.b = v[i+1].i;
    diff.diff = llabs(v[i].x - v[i+1].x);
    que.push(diff);
  }
  sort(ALLOF(v), sort_y);
  rep(i,N-1){
    DIFF diff;
    diff.a = v[i].i;
    diff.b = v[i+1].i;
    diff.diff = llabs(v[i].y - v[i+1].y);
    que.push(diff);
  }

  ll ret = 0;
  while(!que.empty()){
    DIFF diff = que.top(); que.pop();
    if(uf.check(diff.a, diff.b)) continue;
    ret += diff.diff;
    uf.link(diff.a, diff.b);
  }

  cout << ret << endl;
  
  return 0;
}
