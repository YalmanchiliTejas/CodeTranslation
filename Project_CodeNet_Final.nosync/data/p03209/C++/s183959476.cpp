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
ll INF = 1LL << 50;
ll cnt = 0;
vll vB(51), vP(51);

void solve(long long N, long long X){
    if(X <= 1) return;
    ll B = vB[N-1], P = vP[N-1], L = B+P;
    X--;
    if(X < L)
        solve(N-1, X);
    else{
        X -= L;
        cnt += P;
        if(X >= 1) {
            cnt += 1;
            X --;
        }
        else return;

        if(X < L)
            solve(N-1, X);
        else{
            cnt += P;
            return;
        }
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    vB[0]=0; vP[0]=1;
    rep(i, 50){
        vB[i+1] = vB[i]*2+2;
        vP[i+1] = vP[i]*2+1;
    }
    solve(N, X);
    cout << cnt << endl;
    return 0;
}
