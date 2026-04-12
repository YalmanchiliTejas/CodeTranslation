#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1e5;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INFL = 1e15;

int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  if(k == 0){
    printf("%lld\n", 1LL * n * n);
    return 0;
  }
  LL tot = 0;
  for(int i = k + 1; i <= n; ++i){
    int sisa = n - (i - 1);
    tot += i - k;
    tot += 1LL * (sisa / i) * (i - k);
    int mod = sisa % i;
    tot += max(0, mod - k);

   // fprintf(stderr, "%d: %lld\n", i, tot);
  }
  printf("%lld\n", tot);
  return 0;
}