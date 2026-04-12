#include <bits/stdc++.h>

using namespace std;

#define K 200001

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define pb push_back
#define mp make_pair
	
int n;
vector<int> nxt[K];

int dfs[K], de[K], red[K];

priority_queue<pair<int, int> > Q;

int main(){
	scanf("%d", &n);
	FOE(i, 1, n - 1){
		int u, v; scanf("%d%d", &u, &v);
		nxt[u].pb(v);
		nxt[v].pb(u);
		de[u]++; de[v]++;
	}
	
	FOE(i, 1, n) if (de[i] == 1){
		Q.push(mp(0, i));
	}
	
	FOE(i, 1, n){
		pair<int, int> T = Q.top(); Q.pop();
		int u = T.second;
	//	printf("u = %d red[%d] = %d\n", u, u, red[u]);
		if (red[u] == 0){
			// leaf
			for (int j = 0; j < nxt[u].size(); j++) if (!dfs[nxt[u][j]]){
			//	printf("handle %d\n", nxt[u][j]);
				de[nxt[u][j]]--;
				red[nxt[u][j]]++;
				if (de[nxt[u][j]] == 1){
					Q.push(mp(-red[nxt[u][j]], nxt[u][j]));
				}
			}
		} else if (red[u] == 1){
			
			for (int j = 0; j < nxt[u].size(); j++) if (!dfs[nxt[u][j]]){
			//	printf("handle %d\n", nxt[u][j]);
				de[nxt[u][j]]--;
				if (de[nxt[u][j]] == 1){
					Q.push(mp(-red[nxt[u][j]], nxt[u][j]));
				}
			}
		} else if (red[u] >= 2){
			puts("First");
			return 0;
		}
	}
	puts("Second");
}