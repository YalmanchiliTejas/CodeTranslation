#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define FORD(i, a, b) for (int i=a; i>(int)(b); i--)
#define PPC(x) __builtin_popcount(x)
#define MSB(x) (31 - __builtin_clz(x))
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ithBit(m, i) ((m) >> (i) & 1)
#define ft first
#define sd second
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;

const int maxN = 1 << 18;

void solve()
{
	char t[4];
	scanf ("%s", t);
	
	printf("%s\n", (t[0] == t[1] and t[1] == t[2]) ? "No" :"Yes");
} 

 
int main()
{
    int t;
    t=1;//scanf ("%d", &t);
    while (t--)
    	solve();
    return 0;    
}
