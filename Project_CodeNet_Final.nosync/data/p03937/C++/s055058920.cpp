

#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
#include <iostream>  
#include <string>  
#include <cmath>  
#include <vector>  
#include <set>  
#include <map>  
#include <bitset>  
#include <stack>  
using namespace std;  
  
#define REP(i,n) for ( int i=1; i<=int(n); i++ )    
#define MP make_pair  
#define PB push_back  
#define SZ(x) (int((x).size()))  
#define ALL(x) (x).begin(), (x).end()  
#define X first  
#define Y second  
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }  
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }  
  
typedef long long LL;  
typedef long double LD;  
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int N = 10;
int c[N * 2];
pii p[N * 2];
char str[N * 2];
int main() {
	int n, m;
	cin >> n >> m;
	bool flag = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%s", str);
		for(int j = 0; str[j]; j ++) {
			if(str[j] == '#') {
				c[i + j] ++;
				if(c[i + j] > 1) flag = 1;
				p[i + j] = pii(i, j);
			}
		}
	}
	if(flag) puts("Impossible");
	else {
		for(int i = 2; i <= n + m - 1; i ++) {
			int val = abs(p[i].X - p[i - 1].X) + abs(p[i].Y - p[i - 1].Y);
			if(val != 1) flag = 1;
		}
		if(flag) puts("Impossible");
		else puts("Possible");
	}
}

