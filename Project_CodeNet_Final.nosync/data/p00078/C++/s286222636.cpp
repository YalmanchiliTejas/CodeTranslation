
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

#include <algorithm>
#include <complex>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <bitset>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
#endif

#define ITER(c)             __typeof__((c).begin())
#define FOREACH(it, c)      for (ITER(c) it=(c).begin(); it != (c).end(); ++it)
#define RITER(c)            __typeof__((c).rbegin())
#define RFOREACH(it, c)     for (RITER(c) it=(c).rbegin(); it != (c).rend(); ++it)
#define REP(i, n)           REPEAT(i, 0, n)
#define RREP(i, n)          RREPEAT(i, 0, n);
#define REPEAT(i, k, n)     for(int i = (k); i < (k+n); ++i)
#define RREPEAT(i, k, n)    for(int i = (k)+(n)-1; i >= (k); ++i)
#define ALL(c)              (c).begin(), (c).end()
#define LLPOW(p1,p2)        ((ll)pow((double)(p1), (int)p2))
#define ESIZEOF(A)          (sizeof(A)/sizeof((A)[0]))
#define MIN(p1,p2)          (((p1)<(p2))?(p1):(p2))
#define MAX(p1,p2)          (((p1)>(p2))?(p1):(p2))
#define CIN_NO_SYNC         do { cin.tie(0); ios_base::sync_with_stdio(false); } while(0)
#define GETSTR(p)           fgets((p), sizeof(p), stdin)
#define CHOMP(p)            do{ char *_q = (p) + strlen(p)-1; if(*_q == '\n' || *_q == '\r') *_q = 0; } while(0)
#define mp                  make_pair

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
typedef double D;
typedef complex<D> P;
#define EPS (1e-9)

#ifdef _DEBUG
#define pf printf
#define pr(n) do { cout << #n " = " << (n) << endl; } while(0)
#else
#define pf(...) /* */
#define pr(...) /* */
#endif

void solve(int n){
    int t[100][100];
    int x = n/2-1, y = n/2;
    memset(t, 0, sizeof(t));
    REP(i,n*n){
        x++; y++;
        x = (x + n) % n; y = (y + n) % n;
        while(t[y][x] != 0){
            x--; y++;
            x = (x + n) % n; y = (y + n) % n;
        }
        t[y][x] = i + 1;
    }
    REP(y,n){
        REP(x,n) printf("%4d", t[y][x]);
        cout << endl;
    }
}

int main(){
    int n;
    while(cin >> n, n) solve(n);
    return 0;
}