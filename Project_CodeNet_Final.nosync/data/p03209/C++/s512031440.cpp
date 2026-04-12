#include<bits/stdc++.h>

// #define __STDC_FORMAT_MACROS
using namespace std;
// #include <inttype.h>

vector<long long> L;
vector<long long> P;

long long func(int N, long long X){
    // レベルNバーガーの下からX層を食べた時のパティの枚数を返す関数
    if(N == 0){
        return 1;
    }
    if(X == 1){
        return 0;
    }

    if(X == 1 + L[N - 1]){
        return P[N - 1];
    }else if(X == 2 + L[N - 1]){
        return P[N - 1] + 1;
    }else if(X < 1 + L[N - 1]){
        return func(N - 1, X - 1);
    }else if(X < L[N]){
        return(func(N - 1, X - 2 - L[N - 1]) + P[N - 1] + 1);
    }else if(X == L[N]){
        return P[N];
    }

    return -500000000000000;
}

int main(){
    int N;
    long long X = 0;
    scanf("%d %lld", &N, &X);

    // レベルiバーガーの層数とパティの枚数
    L.push_back(1);
    P.push_back(1);
    for(int i = 1; i <= N; i++){
        L.push_back(2 * L[i - 1] + 3);
        P.push_back(2 * P[i - 1] + 1);
    }

    // for(int i = 0; i <= N; i++){
    //     long long x = L[i];
    //     printf("%lld\n", x);
    // }
    // for(int i = 0; i <= N; i++){
    //     long long y = P[i];
    //     printf("%lld\n", y);
    // }
    printf("%lld\n", func(N, X));
    return 0;
}