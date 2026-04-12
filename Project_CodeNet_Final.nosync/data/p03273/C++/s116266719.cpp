#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int H, W;
std::string A[110];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> H >> W;

    for(int i=0;i<H;++i){
        std::cin >> A[i];
    }

    std::vector<int> rows, columns;
    for(int i=0;i<H;++i){
        if(std::any_of(A[i].begin(), A[i].end(), [](char c){return c == '#';})){
            rows.emplace_back(i);
        }
    }

    for(int j=0;j<W;++j){
        bool flag = false;

        for(int i=0;i<H;++i){
            if(A[i][j] == '#'){
                flag = true;
                break;
            }
        }

        if(flag){
            columns.emplace_back(j);
        }
    }

    for(int i : rows){
        for(int j : columns){
            std::cout << A[i][j];
        }
        std::cout << std::endl;
    }
}
