/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		1000007
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
string str[10];
bool flag = true;

void dfs(int x, int y){
	if(str[x][y] != '#'){
		flag = false;
		return;
	}
	if(x == n-1 && y == m-1){
		return;
	}
	int r1 = 0, r2 = 0;
	for(int i=y+1;i<m;i++) r1 += (str[x][i] == '#');
	for(int i=x+1;i<n;i++) r2 += (str[i][y] == '#');
	if(r1 && r2){
		flag = false;
		return;
	}
	if(r1) dfs(x, y+1);
	else dfs(x+1, y);
}

int main(){
	cin >> n >> m;
	rep(i, n) cin >> str[i];
	dfs(0, 0);
	if(flag) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
