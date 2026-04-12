#pragma comment(linker, "/STACK:1024000000,1024000000")
//#include<bits/stdc++.h>
#include <algorithm>  
#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <string>
#include <cstdio>  
#include <climits>
#include <cmath> 
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#define inf 0x3f3f3f3f
#define ll long long
#define fora(i,a,n) for(int i=a;i<=n;i++)
#define fors(i,n,a) for(int i=n;i>=a;i--)
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define sci2(x,y) scanf("%d%d",&x,&y)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
const int maxn = 100024;
const int mod = 1e9 + 7;
const double eps = 1e-8;
using namespace std;
typedef pair<int, int> pr;


int n, m;
char s[122][111];
int visr[111];
int visc[111];
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	cin >> n >> m;
	fora(i, 0, n - 1) {
		scanf("%s", s[i]);
	}
	fora(i, 0, n - 1) {
		int num = 0;
		fora(j, 0, m - 1) {
			if (s[i][j] == '#') num++;
		}
		if(num==0)	visr[i] = 1;
	}
	
	fora(j, 0, m - 1) {
		int num = 0;
		fora(i, 0, n - 1) {
			if (s[i][j] == '#') num++;
		}
		if (num == 0) visc[j] = 1;
	}

	fora(i, 0, n - 1) {
		bool flag = false;
		if (visr[i]) flag = true;
		fora(j, 0, m - 1) {
			if (visr[i] || visc[j]) {
				continue;
			}
			printf("%c", s[i][j]);
		}
		if (flag== false) printf("\n");
	}
	return 0;
}