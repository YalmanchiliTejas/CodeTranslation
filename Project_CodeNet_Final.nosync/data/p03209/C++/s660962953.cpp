#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll p(ll N){
    if (N == 0){
        return 1;
    }
    ll pN = p(N - 1) * 2 + 1;
    return pN;
}

ll b(ll N){
    if (N == 0){
        return 1;
    }
    ll pN = b(N - 1) * 2 + 3;
    return pN;
}

ll levelN(ll N, ll K){
    if (N == 0){
        return 1;
    }
    
    if (N != 0 && K == 1){
        return 0;
    }
    
    if (K <= b(N - 1)){
        return levelN(N - 1, K - 1);
    }
    
    if (K == b(N - 1) + 1){
        return p(N - 1);
    }
    
    if (K == b(N - 1) + 2){
        return 1 + p(N - 1);
    }
    
    if (K <= 2 * b(N - 1) + 1){
        return 1 + p(N - 1) + levelN(N - 1, K - 2 - b(N - 1));
    }
    
    if (K == 2 * b(N - 1) + 2){
        return 1 + 2 * p(N - 1);
    }
    
    return 1 + 2 * p(N - 1);
}

int main(){
    ll N,X;
    cin >> N >> X;
    cout << levelN(N,X) << endl;
}