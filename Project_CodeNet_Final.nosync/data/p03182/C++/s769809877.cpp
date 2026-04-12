#include <bits/stdc++.h>
using namespace std;

enum{INI, QRY, END};
typedef long long int ll;

const int MAX = 2e5+7;
const ll inf = 1e18;

struct Event
{
  int x, a, b;
  ll v;
  int t;
  Event(){}
  Event(int x, int a, int b, ll v, int t)
    : x(x), a(a), b(b), v(v), t(t) {}
  bool operator <(const Event& e)const
  {
    if(x != e.x) return x < e.x;
    return t < e.t;
  }
};

ll T[MAX << 2], lazy[MAX << 2];
int n, m;
#define mid ((x+xend)>>1)
#define lef (nod<<1)
#define rig ((nod<<1)|1)

void push(int nod, int x, int xend)
{
  if(!lazy[nod]) return;
  T[nod] += lazy[nod];
  if(x != xend)
    lazy[lef] += lazy[nod],
    lazy[rig] += lazy[nod];
  lazy[nod] = 0;
}

void upd(int a, int b, ll v, int nod=1, int x=1, int xend=n)
{
  push(nod, x, xend);
  if(a <= x && xend <= b)
  {
    lazy[nod] += v;
    push(nod, x, xend);
    return;
  }
  if(xend < a || x > b) return;
  upd(a, b, v, lef, x, mid);
  upd(a, b, v, rig, mid+1, xend);
  T[nod] = max(T[lef], T[rig]);
}

ll qry(int a, int b, int nod=1, int x=1, int xend=n)
{
  push(nod, x, xend);
  if(a <= x && xend <= b) return T[nod];
  if(xend < a || x > b) return -inf;
  return max(qry(a, b, lef, x, mid), qry(a, b, rig, mid+1, xend));
}

void dump()
{
  for(int i=1;i<=5;++i) cerr << i << ' ' << T[i] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  cin >> n >> m;
  vector<Event> E;
  
  for(int i=1;i<=m;++i)
  {
    int a, b, v;
    cin >> a >> b >> v;
    E.emplace_back(a, a, b, v, INI);
    E.emplace_back(b, a, b, v, END);
  }
  for(int i=1;i<=n;++i) E.emplace_back(i, -1, -1, -1, QRY);
  sort(E.begin(), E.end());
  

  ll ans = -inf;
  for(auto& e: E)
  {
    if(e.t == INI)
    {
      upd(e.a, e.b, -e.v);
    }else if(e.t == QRY)
    {
      ll C = -qry(e.x, e.x);
      ll dp = max(C, C + (e.x>1?qry(1, e.x-1):0));
      upd(e.x, e.x, dp);
      ans = max(ans, dp);
    }else // e.t == END
    {
      upd(e.a, e.b, e.v);
    }
    //~ dump();
  }
  
  cout << max(0ll, ans) << endl;
  
  return 0;
}
