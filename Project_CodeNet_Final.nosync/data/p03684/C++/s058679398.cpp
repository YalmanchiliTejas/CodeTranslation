#include <bits/stdc++.h>
#define FOR(x,n) for(int x = 0; x < n; x++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef long long ll;
const int MXN = 1e5 + 1;
int N;
pair<int,int> xs[MXN], ys[MXN], id[MXN];
struct Edge {
  int a, b, v;
  bool operator<(const Edge &o) const {
    return v > o.v;
  }
};

int P[MXN];
int find(int i) { return i == P[i] ? i : P[i] = find(P[i]); }
int main() {
  cin >> N;
  fore(x,0,MXN) P[x] = x;
  fore(x, 0, N) cin >> xs[x].first >> ys[x].first, xs[x].second = x, ys[x].second = x;
  sort(xs,xs+N); sort(ys,ys+N);
  fore(x,0,N) id[xs[x].second].first = x, id[ys[x].second].second = x;

  priority_queue<Edge> pq;
  fore(x,0,N-1){
    pq.push(Edge{xs[x].second, xs[x+1].second, xs[x+1].first - xs[x].first});
    pq.push(Edge{ys[x].second, ys[x+1].second, ys[x+1].first - ys[x].first});
  }

  ll ans = 0;
  while(!pq.empty()){
    Edge e = pq.top(); pq.pop();

    if(find(e.a) != find(e.b)){
      ans += e.v;
      P[find(e.a)] = find(e.b);
    }
  }

  cout << ans << "\n";
}
