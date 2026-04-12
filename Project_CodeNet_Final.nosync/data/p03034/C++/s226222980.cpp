#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int N;
int S[100100];
std::vector<ll> T[100100], U[100100];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> S[i];
    }

    for(int i=1;i<N;++i){
        int n = (N - 1) / i;

        T[i].resize(n + 1);
        T[i][0] = 0;

        for(int j=1;j<=n;++j){
            T[i][j] = T[i][j-1] + S[(N-1)-i*j];
        }
    }

    for(int i=1;i<N;++i){
        int n = (N - 1) / i;

        U[i].resize(n + 1);
        U[i][0] = 0;

        for(int j=1;j<=n;++j){
            U[i][j] = U[i][j-1] + S[i*j];
        }
    }

    ll res = 0;

    for(int D=1;D<N;++D){
        for(int A=N-1-D;A>0;A-=D){
            int B = A - D;
            if(B <= 0 || A <= B){continue;}
            if(B % D == 0 && (N - 1 - A) - D >= B){continue;} // Move to the same position twice

            // std::cout << A << ", " << B << std::endl;
            
            res = std::max(res, U[D][(N-1-A)/D] + T[D][(N-1-A)/D]);
        }
    }

    std::cout << res << std::endl;
}
