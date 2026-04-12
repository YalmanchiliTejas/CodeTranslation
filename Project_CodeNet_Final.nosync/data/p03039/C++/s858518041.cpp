#include<cstdio>
#include<algorithm>

const int mod = 1e9 + 7;

long long inv(long long x){
  long long m = mod, u = 1, v = 0;
  while(m){
    long long t = x / m;
    x -= t * m; std::swap(x, m);
    u -= t * v; std::swap(u, v);
  }
  u %= mod;
  if(u < 0) u += mod;
  return u;
}

int main(){
  int N, M;
  scanf("%d%d", &N, &M);
  int K;
  scanf("%d", &K);
  
  long long fact[N * M + 1];
  fact[0] = 1;
  for(int i = 1; i <= N * M; i++){
    fact[i] = fact[i - 1] * i % mod;
  }
  
  long long all_costs = 0;
  
  for(long long dx = 1; dx < N; dx++){
    long long cost = dx * M * M * (N - dx) % mod * (fact[N * M - 2] * inv(fact[K - 2] * fact[N * M - K] % mod) % mod) % mod;
    all_costs += cost;
    all_costs %= mod;
  }
  
  for(long long dy = 1; dy < M; dy++){
    long long cost = dy * N * N * (M - dy) % mod * (fact[N * M - 2] * inv(fact[K - 2] * fact[N * M - K] % mod) % mod) % mod;
    all_costs += cost;
    all_costs %= mod;
  }
  
  printf("%lld\n", all_costs);
  
  return 0;
}