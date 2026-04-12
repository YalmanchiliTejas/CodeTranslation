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
    int N, max = 0, r = 0;
    vector<int> H;
    
    cin >> N;
    H.resize(N);
    for (auto& i : H) {
        cin >> i;
        
        if (i >= max) {
            r++;
            max = i;
        }
    }
    
    

    cout << r << endl;
    
    return 0;
}

