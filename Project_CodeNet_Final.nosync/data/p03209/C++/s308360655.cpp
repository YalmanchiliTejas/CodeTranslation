#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

LL patee[51];
LL thickness[51];

LL rec(int N, LL X){
    // printf("N = %d, X = %lld, patee = %lld, thickness = %lld\n", N, X, patee[N], thickness[N]);
    if(X==0)
        return 0;
    if(thickness[N] <= X)
        return patee[N];
    else{
        LL a = rec(N-1, X-1);
        if(1+thickness[N-1]+1<=X)
            a++;
        if(1+thickness[N-1]+1<X)
            a += rec(N-1, X-1-thickness[N-1]-1);
        return a;
    }
}

int main(void){
    REP(i,51){
        if(i==0){
            patee[0] = 1;
            thickness[0] = 1;
        }
        else{
            patee[i] = patee[i-1]*2 + 1;
            thickness[i] = 3 + thickness[i-1] * 2;
        }
    }
    int N;
    LL X;
    GI(N);GLL(X);
    printf("%lld\n", rec(N,X));
    return 0;
}