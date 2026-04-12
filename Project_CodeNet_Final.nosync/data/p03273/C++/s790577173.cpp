/**/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
 
typedef long long LL;
using namespace std;
 
int n, m;
char s[105][105];
int l[105], r[105];
 
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= n; i++){
		int t = 0;
		for (int j = 1; j <= m; j++){
			if(s[i][j] == '.'){
				t++;
			}
		}
		if(t == m) l[i] = 1;
	}
	for (int i = 1; i <= m; i++){
		int t = 0;
		for (int j = 1; j <= n; j++){
			if(s[j][i] == '.'){
				t++;
			}
		}
		if(t == n) r[i] = 1;
	}
	for (int i = 1; i <= n; i++){
		int flag = 0;
		for (int j = 1; j <= m; j++){
			if(l[i] || r[j]) continue;
			flag = 1;
			printf("%c", s[i][j]);
		}
		if(flag) printf("\n");
	}
 
	return 0;
}
