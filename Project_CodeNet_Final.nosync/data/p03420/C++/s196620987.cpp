#include <cstdio>
using namespace std;

int p[100002];

int main(){
  int N, K; scanf("%d%d", &N, &K);

  long long ans = 0;

  for(int s = 0, r = N - 1; r >= K; r--){
    s += p[N - r] + (N - r) / (r + 1) + 1; ans += s;
    for(int i = 0; i <= N; i += r + 1) p[i]++;
  }

  if(K == 0) ans -= N;

  printf("%lld\n", ans);
  return 0;
}