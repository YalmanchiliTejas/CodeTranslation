#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

constexpr ll MOD = 1000000000 + 7;

std::string K;
int D;
ll dp[10010][120][2];

ll rec(int i, int rem, int flag){
    if(i == K.size()){
        return rem == 0 ? 1 : 0;
    }

    if(dp[i][rem][flag] != -1){
        return dp[i][rem][flag];
    }

    ll res = 0;
    int mx = flag ? 9 : K[i] - '0';
    for(int j=0;j<=mx;++j){
        res = (res + rec(i + 1, (rem + j) % D, flag || (j < mx))) % MOD;
    }

    return dp[i][rem][flag] = res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> K >> D;
    
    memset(dp, -1, sizeof(dp));

    ll res = (rec(0, 0, 0) + MOD - 1) % MOD;
    std::cout << res << std::endl;
}
