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

int N, A, B, C, X;
int Y[110];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    while(true){
        std::cin >> N >> A >> B >> C >> X;
        if(!N){break;}

        for(int i=0;i<N;++i){
            std::cin >> Y[i];
        }

        int t = 0, idx = 0;
        while(t <= 10000){
            if(Y[idx] == X){
                ++idx;
            }

            if(idx == N){
                break;
            }

            ++t;
            X = (A * X + B) % C;
        }

        int res = t <= 10000 ? t : -1;
        std::cout << res << std::endl;
    }
}

