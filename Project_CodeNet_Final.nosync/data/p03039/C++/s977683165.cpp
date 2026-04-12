#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;
#define P 1000000007
#define N_MAX 2000000
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
    return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}

void init(){
    fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}

int main(int argc, char const *argv[]) {
  ll N, M, K, Sij, ans=0, aBA, bD, cC, d;
  std::cin >>  N >> M >> K;
  init();
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      aBA = ((i*j%1000000007)*(i+j+2))%1000000007;
      bD = ((M-j) * ((((i*(i+M-j-1))%1000000007)+i)%1000000007))%1000000007;
      cC = ((N-i) * ((((j*(N-i-1+j))%1000000007)+j)%1000000007))%1000000007;
      d = ((((N-i)*(M-j))%1000000007)*(N-i-1+M-j-1))%1000000007;
      Sij = (aBA + bD + cC + d)%1000000007;
      Sij = (Sij *inv[4])%1000000007;
      ans = (ans + (Sij * comb(N*M-2, K-2))%1000000007)%1000000007;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
