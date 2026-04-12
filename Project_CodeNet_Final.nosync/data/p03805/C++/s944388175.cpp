#include<stdio.h>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
typedef long long ll;
typedef pair<int, int> P;
const int INF=1e7;

bool graph[8];
bool pass[8][8];
int N,M;
int ans;
int dfs(int num,int cnt) {
	if (cnt == N-1)return 1;
		FOR(k, 0, 8) {
			if (pass[num][k] == true && graph[k] == false) {
				graph[k] = true; 
				
				ans += dfs(k, cnt+1);
				graph[k] = false;
			}
		}
		return 0;
}

int main(void)
{
	cin >> N >> M;
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		graph[0] = true;
		pass[a - 1][b - 1] = pass[b - 1][a - 1] = true;
	}
	dfs(0,0);
	ct(ans);
	return 0;
}