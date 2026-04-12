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

int n;
vector<pii> in;
vi out;

int GetIdx(int pos, int bad){
  if(bad > pos) return pos;
  else return pos - 1;
}

int main(){
  scanf("%d", &n);
  in.resize(n);
  out.resize(n);

  for(int i = 0;i < n;++i) in[i].se = i;
  for(auto& e : in) scanf("%d", &e.fi);

  sort(all(in));

  int mid = (n - 1) / 2;
  for(int i = 0;i < n;++i){
    for(int j = max(0, mid - 10);j < min(n, mid + 10);++j)
      if(j != i && GetIdx(j, i) == mid)
       out[in[i].se] = in[j].fi;
  }

  for(int i = 0;i < n;++i)
    printf("%d\n", out[i]);

  return 0;
}
