#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(long long N, std::vector<long long> H){
    ll cnt = 1;
    for(ll i=1; i< N; i++){
        bool isGood = true;
        for(ll j=0; j< i; j++){
            if(H[j]>H[i]) isGood = false;
        }
        if(isGood) cnt++;
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
