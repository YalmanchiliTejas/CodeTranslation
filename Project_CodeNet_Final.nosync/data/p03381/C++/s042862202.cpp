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

int N;
P X[200100];
int res[200100];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for(int i=0;i<N;++i){
        std::cin >> fst(X[i]);
        snd(X[i]) = i;
    }

    sort(X, X+N);
    
    int r = N / 2;
    for(int i=0;i<N;++i){
        if(i < r){
            res[snd(X[i])] = fst(X[r]);
        }else{
            res[snd(X[i])] = fst(X[r-1]);
        }
    }

    for(int i=0;i<N;++i){
        std::cout << res[i] << std::endl;
    }
}
