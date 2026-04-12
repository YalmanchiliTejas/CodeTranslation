#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)
#define RFOR(i,e,s) for(int (i)=(e)-1;(i)>=(int)(s);(i)--)
#define RREP(i,e) RFOR(i,e,0)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;
typedef priority_queue<int> PQI;
typedef priority_queue<PII> PQII;

const double EPS = 1e-10;
const int N = 200000;
const int M = 200000;
int n, m, a, d, k;
int x[M], y[M], z[M], s[N], tmp[N];

int main() {
  scanf("%d ", &n);
  scanf("%d%d ", &a, &d);
  scanf("%d ", &m);
  REP(i,m) {
    scanf("%d%d%d ", x+i, y+i, z+i);
    y[i]--; z[i]--;
  }
  scanf("%d ", &k); k--;

  memset(s, 0, sizeof(s));
  s[0] = a;
  FOR(i,1,n) s[i] = s[i-1] + d;
  
  int rev_k = k;
  REP(i,m) {
    if (!x[m-1-i] && y[m-1-i]<=rev_k && rev_k<=z[m-1-i])
      rev_k = z[m-1-i]-(rev_k-y[m-1-i]);
  }

  REP(i,m) {
    if (y[i]<=rev_k && rev_k<=z[i]) {
      if (!x[i]) {
        swap(s[rev_k], s[z[i]-(rev_k-y[i])]); 
        rev_k = z[i]-(rev_k-y[i]); 
      } else
        s[rev_k] = (x[i]==1) ? s[rev_k]+1 : s[rev_k]/2;
    }
  }

  printf("%d\n", s[k]);

  return 0;
}