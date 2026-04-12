#include <bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, X, M, S{0};
    cin >> N >> X >> M;
    vector<pair<unsigned long, unsigned long>> memo(M);
    for(unsigned long i{0}; i < N; ++i){
        if(memo[X].first){
            const auto t{i - memo[X].first}, c{(N - i - 1) / t};
            i += t * c;
            S += (S - memo[X].second) * c;
        }else memo[X] = {i, S};
        S += X;
        (X *= X) %= M;
    }
    cout << S << endl;
}
