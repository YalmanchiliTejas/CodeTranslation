#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)

using ll = long long;
using P = std::tuple<ll,ll>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

ll N, A[50];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    ll S = 0ll;
    for(int i=0;i<N;++i){
        std::cin >> A[i];
        S += A[i];
    }

    ll res = 1001001001001001001ll;
    for(ll i=0;i<=min((N-1)*N, S);++i){        
        ll c = S - i;      
        P range;
        for(int j=0;j<N;++j){
            ll a = ((A[j] + c) - (N - 1) + N) / (N + 1),
                b = (A[j] + c) / (N + 1);

            a = max(a, 0ll);
            b = min(b, c);
            
            if(j == 0){
                range = std::make_tuple(a, b);
            }else{
                fst(range) += a;
                snd(range) += b;
            }
        }

        if(fst(range) <= c && c <= snd(range)){
            res = min(res, c);
        }
    }

    std::cout << res << std::endl;
}
