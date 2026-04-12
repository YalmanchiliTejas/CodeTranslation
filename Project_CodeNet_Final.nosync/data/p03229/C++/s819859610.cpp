#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)

void solve(long long N, std::vector<long long> A){
    if(N == 2){
        cout << abs(A[0]-A[1]) << endl;
        return;
    }
    sort(A.begin(), A.end());
    if(N & 1){
        ll res1=0, res2=0;
        //* typeA
        rep(i, N/2){
            res1 -= 2* A[i];
        }
        for(ll i= N/2; i< N; i++){
            res1 += 2* A[i];
        }
        res1 -= (A[N/2]+A[N/2+1]);

        //* typeB
        rep(i, N/2+1){
            res2 -= 2*A[i];
        }
        for(ll i=N/2+1; i< N; i++){
            res2 += 2* A[i];
        }
        res2 += A[N/2]+A[N/2-1];

        cout << max(res1, res2) << endl;
        return;
    }
    else{ //* N is even: only one type
        ll res = 0;
        rep(i, N/2)
            res -= 2* A[i];
        for(ll i= N/2; i< N; i++){
            res += 2*A[i];
        }
        res += A[N/2-1] -  A[N/2];
        cout << res << endl;
        return;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
