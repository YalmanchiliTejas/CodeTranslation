#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int main(){
  int n;

  scanf("%d", &n);

  vector<int> origin(n);
  vector<int> v(n);

  REP (i, n) {
    int a;
    scanf("%d", &a);
    v[i] = a;
    origin[i] = a;
  }

  sort(v.begin(), v.end());

  int median = v[v.size() / 2];
  int small = v[v.size() / 2 - 1];

  REP (i, n) {
    if (origin[i] < median) printf("%d\n", median);
    else printf("%d\n", small);
  }
}
