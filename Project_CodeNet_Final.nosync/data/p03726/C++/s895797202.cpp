#include <bits/stdc++.h>

using namespace std;

const int N = 101000;

int a[N], b[N];
int deg[N], fat[N];
int paint[N];

vector <int> adj[N];

void dfs(int u, int l = -1) {
	for (int x: adj[u]) {
		if(l == x)continue;
		fat[x] = u;
		dfs(x, u);
	}
}

int main() {
	int n;
	scanf("%d", &n);


	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		deg[a[i]]++; deg[b[i]]++;
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	dfs(1);
	fat[1] = 0;
	paint[0] = 1;
	queue <int> q;

	for (int i = 2; i <= n; ++i) {
		if(deg[i] <= 1) {
			q.push(i);
		}
	}
	if(n == 1) {
		q.push(1);
	}
	int ok = 1;
	while(!q.empty()) {
		int at = q.front();
		//printf("%d\n", at);
		q.pop();
		if(paint[at] == 0) {
			paint[at] = 1;
			if(paint[fat[at]] == 0) {
				paint[fat[at]] = 1;
				if(fat[fat[at]] != 0) {
					deg[fat[fat[at]]]--;
					if(deg[fat[fat[at]]] <= 1 && paint[fat[fat[at]]] != 1) {
						q.push(fat[fat[at]]);
					}
				}
			} else {
				//printf("enter\n");
				ok = 0;
				break;
			}
		} else {
			//printf("enter\n");
			ok = 0;
			break;
		}
	}

	/*

		o
	   / \
	  o   o
	  	   \
	  	    o


	*/
	if (ok) puts("Second");
	else puts("First");
	
}