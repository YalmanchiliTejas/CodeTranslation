#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
// #include <unordered_map>
#include <set>
#include <utility>
#include <bitset>
#include <limits>
#include <climits>
using namespace std;

#ifdef DEBUG
#define NDEBUG
#include "cout11.h"
#endif
#undef NDEBUG
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))

#define INTSPACE 11
char _buf[INTSPACE*1000000 + 3];  // ここ要確認

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}
int loadvec(vector<int>& v, int N=-1) {
    if (N == -1) {
        N = loadint();
        if (N==0) return 0;
    }
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin)==NULL) return 0;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    // assert(i <= N);
    return i;
}

void solve(int N, vector<int>& a) {
    deque<int> dq;
    if (N%2 == 0) {
        rep(i, N){
            if (i%2 == 0)
                dq.push_back(a[i]);
            else
                dq.push_front(a[i]);
        }
    } else {
        rep(i, N){
            if (i%2 == 0)
                dq.push_front(a[i]);
            else
                dq.push_back(a[i]);
        }
    }
    rep(i, N) {
        int x = dq.front(); dq.pop_front();
        printf("%d", x);
        if (i != N-1) putchar(' ');
    }
    printf("\n");
}

int main() {
    vector<int> a;
    int N = loadvec(a);
    solve(N, a);
}
