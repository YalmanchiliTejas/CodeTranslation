#include <cstdio>
using namespace std;
typedef long long ll;
int N; ll X, ans;
ll rec(int n, ll x) {
  if(n == 0) return 1;
  ll lng = (1LL<<(n+1))-3;
  ll num = (1LL<<(n))-1;
  if(x == 1) return 0;
  else if(x <= lng+1) return rec(n-1, x-1);
  else if(x <= lng+2) return num+1;
  else if(x <= 2*lng+2) return num+1+rec(n-1, x-lng-2);
  return 2*num+1;
}
int main() {
  scanf("%d %ld", &N, &X);
  printf("%ld\n", rec(N, X));
}