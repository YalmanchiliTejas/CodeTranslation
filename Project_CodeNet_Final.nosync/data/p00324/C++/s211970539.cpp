#include <stdio.h>
#include <set>
#include <utility>
using namespace std;

typedef long long ll;

int main(void) {
  ll i, j, k, n, max = 0;
  scanf("%lld", &n);
  ll d[n], sum[n];
  set< pair<int, int> > s;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &d[i]);
    if(i) sum[i] = sum[i - 1] + d[i];
    else sum[i] = d[i];
  }
  for(i = 0; i < n; ++i) {
    set<pair<int, int> >::iterator it;
    pair<int, int> p = make_pair(sum[i], 0), pt = make_pair(sum[i], i);
    it = s.lower_bound(p);
    if(sum[i] == 0){
      if(max < i + 1) max = i + 1;
      continue;
    }
    if(it == s.end() || (*it).first != sum[i]) 
     s.insert(pt);
    else 
      if(max < i - (*it).second) max = i - (*it).second;
  }
  printf("%lld\n", max);
  return 0;
}
