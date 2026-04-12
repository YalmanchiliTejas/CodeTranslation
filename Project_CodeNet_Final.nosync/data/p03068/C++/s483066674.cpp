//
//  atcoder.cpp
//
//
///
#include <bits/stdc++.h>
#define REP(i, N) for(int i=0; i<N; i++)
using namespace std;

//#include "atcoder.hpp"

long long gcd(long long a, long long b) {
    if (a>b) swap(a,b);
    
    auto r = b % a;
    
    return (r ? gcd(r, a) : a);
}

int main() {
    int N,K;string S;
    
    cin >> N >> S >> K;
    
    auto tg = S[K-1];
    
    for (auto& i : S)
     if (i != tg)
    i = '*';

    cout << S << endl;
    
    return 0;
}
