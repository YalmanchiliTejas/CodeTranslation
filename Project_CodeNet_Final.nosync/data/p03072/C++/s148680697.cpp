#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int H[30];
    int c = 0;

    for(int i=0;i<N;++i){
        std::cin >> H[i];

        if(*std::max_element(H, H + i + 1) == H[i]){
            c += 1;
        }
    }

    std::cout << c << std::endl;
}
