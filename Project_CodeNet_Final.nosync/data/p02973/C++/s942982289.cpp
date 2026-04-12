#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int N, A[100100];
std::multiset<int> s;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> A[i];
    }

    for(int i=0;i<N;++i){
        auto it = s.lower_bound(A[i]);

        if(it == s.begin()){
            s.emplace(A[i]);
        }else{
            std::advance(it, -1);
            s.erase(it);
            s.emplace(A[i]);
        }
    }

    int res = s.size();
    std::cout << res << std::endl;
}
