#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int A, B, C, X, Y;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> A >> B >> C >> X >> Y;

    int minCost = std::numeric_limits<int>::max();

    for(int i=0;i<=std::max(X, Y);++i){
        int cost = C * 2 * i + A * std::max(X - i, 0) + B * std::max(Y - i, 0);
        minCost = std::min(minCost, cost);
    }

    std::cout << minCost << std::endl;
}
