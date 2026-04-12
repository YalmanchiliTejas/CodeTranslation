#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <memory.h>

using namespace std;

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#include <fstream>
//#include "prettyprint.hpp"
#endif // DEBUG_MODE

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<PII> VII;

#define A1D(T)              vector<T>
#define A2D(T)              vector<vector<T> >
#define sz(x)               ((int)(x).size())
#define maxof(x)            numeric_limits<x>::max()
#define minof(x)            numeric_limits<x>::min()
#define lowbit(x)           ((x)&-(x))
#define log2(x)             (log((double)x)/log(2.0))
#define _FORu(T,i,l,h,k)    for(T i=(l);i<=(h);i+=(k))
#define _FORd(T,i,h,l,k)    for(T i=(h);i>=(l);i-=(k))
#define FOR(i,n)            _FORu(int,i,0,n,1)
#define FORu1(i,l,h)        _FORu(int,i,l,h,1)
#define FORuk(i,l,h,k)      _FORu(int,i,l,h,k)
#define FORd1(i,h,l)        _FORd(int,i,h,l,1)
#define FORdk(i,l,h,k)      _FORd(int,i,h,l,k)
#define FOREACH(e,s)        for(__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#define IO_OPT              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef DEBUG_MODE
#define debug(...)          fprintf(stderr, __VA_ARGS__)
#define DEBUG(x)            cerr << '>' << #x << ':' << x << endl << flush;
#else
#define debug(...)
#define DEBUG(x)
#endif // DEBUG_MODE

const double PI      = acos(-1.0);
const double E       = exp(1.0);
const double EPS     = 1e-8;
const int HALF_INF   = 0x3f3f3f3f;

class Solver
{
public:
    void Solve()
    {
        int n;
        scanf("%d", &n);
        printf("%d", n * 800 - (n / 15) * 200);
    }
};

int main()
{
#ifdef DEBUG_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif // DEBUG_MODE

    Solver * solver = new Solver();
    solver->Solve();

    return 0;
}
