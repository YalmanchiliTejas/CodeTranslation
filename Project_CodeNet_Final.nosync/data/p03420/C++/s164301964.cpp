#include <cstdio>
using namespace std;

int main(){
  int N, K; scanf("%d%d", &N, &K);

  long long ans = 0;

  for(int b = K + 1; b <= N; b++){
    ans += N / b * (b - K);
    int t = N % b; if(t >= K) ans += t - K + 1;
  }

  if(K == 0) ans -= N;

  printf("%lld\n", ans);
  return 0;
}