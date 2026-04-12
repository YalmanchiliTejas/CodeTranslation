#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cassert>
#include <cstring>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

int main(void) {
    vector<int> f, b;
    int i, n;
    scanf("%d",&n);
    REP (i,n) {
        int a;
        scanf("%d",&a);
        if (i % 2 == n % 2) f.push_back(a);
        else b.push_back(a);
    }
    reverse(b.begin(),b.end());
    for (auto x: b) printf("%d ",x);
    for (auto x: f) printf("%d ",x);
    puts("");
    return 0;
}