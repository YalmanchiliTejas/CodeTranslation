#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int N, M;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  if(N == M){
      std::cout << "Yes" << std::endl;
  }else{
      std::cout << "No" << std::endl;
  }
}
