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

#define fin(i,n) for (int i = 0; i < n; i++)
#define fin2(i,a,b) for (int i = a; i < b; i++)

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define mod 1000000009

#define si(n) scanf("%d", &n)
#define sii(n,m) scanf("%d %d", &n, &m)
#define siii(n,m,k) scanf("%d %d %d", &n, &m, &k)
#define sl(n) scanf("%lld", &n)
#define sll(n,m) scanf("%lld %lld", &n, &m)
#define slll(n,m,k) scanf("%lld %lld %lld", &n, &m, &k)
#define ss(s) scanf("%s", s)
#define sai(t,n) fin(i,n) { scanf("%d", &t[i]); }
#define sal(t,n) fin(i,n) { scanf("%lld", &t[i]); }

#define pi(n) printf("%d\n", n)
#define pc(n) printf("%c\n", n)
#define ps(s) printf("%s\n", s);
#define pii(n,m) printf("%d %d\n", n, m)
#define pl(n) printf("%lld\n", n)
#define pll(n,m) printf("%lld %lld\n", n, m)
#define pai(t,n) fin(i,n) { printf("%d ", t[i]); } printf("\n"); 
#define pal(t,n) fin(i,n) { printf("%lld ", t[i]); } printf("\n"); 

#define L long long int
#define D double
#define PII pair<int, int>
#define VPII vector<PII>
#define VL vector<L>
#define VI vector<int>
#define VVI vector<VI>

using namespace std;


int main() {
    int arbre[10][10] = {0};
    int n, m, u, v;
    sii(n, m);
    fin(i, m) {
        sii(u, v);
        u--; v--;
        arbre[u][v] = 1;
        arbre[v][u] = 1;
    }
    int tab[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int res = 0, div = 1;
    fin(i, 9-n) { div *= (i+1); }
    do {
        int ok = 1;
        fin(i, n-1) {
            if (arbre[tab[i]][tab[i+1]] == 0) { ok = 0; break; }
        }
        if (ok == 1) { res++; }
    } while ( next_permutation(tab+1,tab+n) );
    pi(res);
} 