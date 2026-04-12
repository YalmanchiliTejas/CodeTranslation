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

constexpr ll INF = 1001001001001001001;
int N;
ll A[3100];
ll dp[3100][3100];

ll rec(int l, int r){
    if(l > r){
        return 0;
    }

    if(dp[l][r] != -INF){
        return dp[l][r];
    }

    ll res = std::max(A[l] - rec(l + 1, r),
                      A[r] - rec(l, r - 1));
    return dp[l][r] = res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> A[i];
    }

    std::fill(&dp[0][0], &dp[0][0]+3100*3100, -INF);

    ll res = rec(0, N - 1);
    std::cout << res << std::endl;
}
