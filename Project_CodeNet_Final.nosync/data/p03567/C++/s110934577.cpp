/* You lost the game. */
 
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <vector>
//#include <pthread.h>
 
#define fin(i,n) for (int i = (L) 0; i < n; i++)
#define fin2(i,a,b) for (int i = a; i < b; i++)
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define mod 1000000007
#define PI 3.1415926535897932384626
#define EXP1 2.718281828459045
 
#define si(n) scanf("%d", &n)
#define sii(n,m) scanf("%d %d", &n, &m)
#define siii(n,m,k) scanf("%d %d %d", &n, &m, &k)
#define sl(n) scanf("%lld", &n)
#define sll(n,m) scanf("%lld %lld", &n, &m)
#define slll(n,m,k) scanf("%lld %lld %lld", &n, &m, &k)
#define sd(n) scanf("%lf", &n)
#define sdd(n,m) scanf("%lf %lf", &n, &m)
#define sddd(n,m,k) scanf("%lf %lf %lf", &n, &m, &k)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)
#define sai(t,n) fin(i,n) { scanf("%d", &i); }
#define sal(t,n) fin(i,n) { scanf("%lld", &i); }
#define sad(t,n) fin(i,n) { scanf("%lf", &i); }
 
#define pc(n) printf("%c\n", n)
#define ps(s) printf("%s\n", s)
#define pi(n) printf("%d\n", n)
#define pii(n,m) printf("%d %d\n", n, m)
#define pl(n) printf("%lld\n", n)
#define pll(n,m) printf("%lld %lld\n", n, m)
#define plll(n,m,k) printf("%lld %lld %lld\n", n, m, k)
#define pd(n) printf("%lf\n", n)
#define pdd(n,m) printf("%lf %lf\n", n, m)
#define pai(t,n) fin(i,n) { printf("%d ", i); } printf("\n")
#define pal(t,n) fin(i,n) { printf("%lld ", i); } printf("\n")
#define pad(t,n) fin(i,n) { printf("%lf ", i); } printf("\n")

#define OK ps("OK")
#define OK1 ps("OK1")
#define OK2 ps("OK2")
 
#define L long long int
#define D double
//#define C char
#define PII pair<int, int>
#define VPII vector<PII>
#define VL vector<L>
#define VI vector<int>
#define VVI vector<VI>
#define VD vector<D>
#define VVD vector<VD>
#define VVPII vector<VPII>
#define VC vector<C>
 
using namespace std;

int main() {
    int n;
    char s[100000];
    ss(s);
    n = strlen(s);
    fin(i, n-1) {
        if (s[i] == 'A' && s[i+1] == 'C') { ps("Yes"); return 0; }
    }
    ps("No");
    return 0;
}