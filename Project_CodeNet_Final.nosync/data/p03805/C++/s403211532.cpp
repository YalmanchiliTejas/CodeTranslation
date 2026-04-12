/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1
#define getBits(x)		__builtin_popcount(x)
#define getBitIdx(x)	__builtin_ffs(x)

// #define DEBUG

typedef long long LL;
const int maxn = 8;
bool g[maxn][maxn];
int a[maxn];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// #ifdef DEBUG
		// freopen("data.in", "r", stdin);
		// freopen("data.out", "w", stdout);
	// #endif
	
	int n, m;
	int u, v;
	
	scanf("%d %d", &n, &m);
	rep(i, 0, m) {
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u][v] = g[v][u] = true;
	}
	
	rep(i, 0, n)
		a[i] = i;
	
	int ans = 0;
	
	do {
		bool flag = true;
		u = 0;
		for (int i=1; i<n; ++i) {
			v = a[i];
			if (!g[u][v]) {
				flag = false;
				break;
			}
			u = v;
		}
		ans += flag;
		// #ifdef DEBUG
		// for (int i=0; i<n; ++i)
			// printf("%d ", a[i]+1);
		// putchar('\n');
		// #endif
	} while (next_permutation(a+1, a+n));
	
	printf("%d\n", ans);
	
	// #ifdef DEBUG
		// printf("time = %ldms.\n", clock());
	// #endif
	
	return 0;
}
