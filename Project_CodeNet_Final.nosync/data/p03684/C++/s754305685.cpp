#include <bits/stdc++.h>
using namespace std;
typedef long long int llong ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
const int MOD = 1e9+7;
const int NMAX = 1e5+5;
template<typename T, template<typename ELEM, typename ALLOC=std::allocator<ELEM> > class Container>
std::ostream& operator<< (std::ostream& o, const Container<T>& container)
{ typename Container<T>::const_iterator beg = container.begin();
  /*o << "[";*/ while(beg != container.end()) o << " " << *beg++; /*o << " ]";*/ return o; }
int n, a, b;

#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)

static vector<pair<int,int> >x, y;
static vector<pair<int, llong> > adj[NMAX + 1];
static bool visited[NMAX + 1];
static int d[NMAX + 1];

llong prim(int start) {
  fill(d, d + n + 1, INT_MAX);

  priority_queue<pair<llong, int> > q;
  d[start] = 0;
  q.push(make_pair(0, start));
  llong res = 0;

  while (!q.empty()) {
    int dist = -q.top().first;
    int a = q.top().second;
    q.pop();
    if (dist > d[a]) continue;
    res += dist;
    visited[a] = true;

    foreach(it, adj[a]) {
      int b = it->first;
      llong w = it->second;
      if (!visited[b] && w < d[b]) {
        d[b] = w;
        q.push(make_pair(-w, b));
      }
    }
  }

  return res;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
    scanf("%d" , &n);

  for(int i = 1 ; i <= n ; i++){
    scanf("%d %d", &a, &b);
    x.pb(mp(a, i));
    y.pb(mp(b, i));
  }

  sort(all(x));
  sort(all(y));

  for(int i = 1 ; i < (int)x.size() ; i++){
    adj[x[i-1].second].pb(mp(x[i].second, abs(x[i].first - x[i-1].first)));
    adj[x[i].second].pb(mp(x[i-1].second, abs(x[i].first - x[i-1].first)));
  }

   for(int i = 1 ; i < (int)y.size() ; i++){
    adj[y[i-1].second].pb(mp(y[i].second, abs(y[i].first - y[i-1].first)));
    adj[y[i].second].pb(mp(y[i-1].second, abs(y[i].first - y[i-1].first)));
  }

  printf("%lld", prim(1));

  return 0;
}  

