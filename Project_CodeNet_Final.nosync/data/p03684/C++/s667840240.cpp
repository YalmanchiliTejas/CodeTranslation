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

int par[MAXN];

int GetPar(int a){
  return par[a] == a ? a : par[a] = GetPar(par[a]);
}

void Merge(int a, int b){
  par[GetPar(a)] = GetPar(b);
}

int n;
int x[MAXN], y[MAXN];

bool CmpX(const int& f, const int& s){
  return x[f] < x[s];
}

bool CmpY(const int& f, const int& s){
  return y[f] < y[s];
}

int Cost(int a, int b){
  return min(abs(x[a] - x[b]),
             abs(y[a] - y[b]));
}

vector<pair<int, pii>> edj;

int main(){
  for(int i = 0;i < MAXN;++i)
    par[i] = i;

  scanf("%d", &n);
  for(int i = 0;i < n;++i)
    scanf("%d%d", &x[i], &y[i]);

  vi nal(n);
  for(int i = 0;i < n;++i) nal[i] = i;

  sort(all(nal), CmpX);
  for(int i = 1;i < n;++i)
    edj.pb(mp(Cost(nal[i - 1], nal[i]),
              mp(nal[i - 1], nal[i])));

  sort(all(nal), CmpY);
  for(int i = 1;i < n;++i)
    edj.pb(mp(Cost(nal[i - 1], nal[i]),
              mp(nal[i - 1], nal[i])));

  sort(all(edj));
  ll ans = 0;
  for(const auto& e : edj)
    if(GetPar(e.se.fi) != GetPar(e.se.se)){
      ans += e.fi;
      Merge(e.se.fi, e.se.se);
    }

  cout << ans << '\n';

  return 0;
}
