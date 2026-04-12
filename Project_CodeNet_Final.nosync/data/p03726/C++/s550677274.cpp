#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 100010;
const string FIRST = "First";
const string SECOND = "Second";

void Say(const string& w){
  cout << w << '\n';
  exit(0);
}

int n;
vi fo[MAXN];
int deg[MAXN];

bool dead[MAXN];
set<int> cq, nq;

void Kill(int vr){
  if(dead[vr]) return;
  dead[vr] = true;
  for(int o : fo[vr]){
    if(dead[o]) continue;
    --deg[o];
    if(deg[o] <= 1) nq.insert(o);
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 1;i < n;++i){
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    fo[a].pb(b), fo[b].pb(a);
  }

  for(int i = 0;i < n;++i)
    deg[i] = sz(fo[i]);

  for(int i = 0;i < n;++i)
    if(deg[i] <= 1) cq.insert(i);

  while(!cq.empty()){
    vi rem;
    for(int vr : cq)
      if(dead[vr]) rem.pb(vr);
    for(int vr : rem)
      cq.erase(vr);

    if(cq.empty()) break;

    nq.clear();

    set<int> conn;
    for(int vr : cq){
      int cnt = 0;
      for(int o : fo[vr])
        if(!dead[o]){
          ++cnt;
          if(conn.count(o)) Say(FIRST);
          conn.insert(o);
        }
      if(cnt == 0) Say(FIRST); // !
    }
    for(int vr : cq) conn.insert(vr);
    for(int vr : conn) Kill(vr);

    cq.swap(nq);
  }

  Say(SECOND);

  return 0;
}
