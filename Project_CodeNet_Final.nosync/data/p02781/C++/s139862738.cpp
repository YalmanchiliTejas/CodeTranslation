#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

std::string N;
int K;
int len;
ll dp[120][2][120];

ll rec(int i, int s1, int s2){
    if(i == len){
        return s2 == K;
    }

    if(dp[i][s1][s2] != -1){
        return dp[i][s1][s2];
    }

    int d = N[i] - '0';
    ll res = rec(i + 1, s1 || (d > 0), s2);
    
    int mx = s1 ? 9 : d;
    for(int j=1;j<=mx;++j){
        res += rec(i + 1, s1 || (d > j), s2 + 1);
    }

    return dp[i][s1][s2] = res;
}

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> K;
  len = N.size();

  memset(dp, -1, sizeof(dp));

  ll res = rec(0, 0, 0);
  std::cout << res << std::endl;
}
