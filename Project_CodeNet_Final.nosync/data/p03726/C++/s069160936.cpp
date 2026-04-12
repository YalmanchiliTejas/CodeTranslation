#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define ran 111111

int n;
vector<int> e[ran];
char c[ran];
int sz[ran];
bool del[ran], is_leaf[ran];
int q[ran], l, r;

int get_par(int cur) {
	for(int i=0;i<e[cur].size();i++) {
		int nxt = e[cur][i];
		if(!del[nxt]) return nxt;
	}
	return -1;
}
int get_leaf(int cur) {
	int res = 0;
	for(int i=0;i<e[cur].size();i++) {
		int nxt = e[cur][i];
		if (!del[nxt] && is_leaf[nxt]) res++;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(del, false, sizeof del);
	memset(is_leaf, false, sizeof is_leaf);
	l=r=0;
	for(int i=1;i<=n;i++) {
		sz[i] = e[i].size();
		if(sz[i]==1) {
			is_leaf[i] = true;
			q[r++] = i;
		}
	}
	while(l<r) {
		int cur = q[l++];
		if(sz[cur]==0) {
			bool chk = true;
			for(int i=0;i<e[cur].size() && chk;i++) {
				int nxt = e[cur][i];
				if(c[nxt]=='B') chk = false;
			}
			if(chk) {
				puts("First");
				return 0;
			}
			continue;
		}
		int par = get_par(cur);
		if (get_leaf(par) > 1) {
			puts("First");
			return 0;
		}
		del[cur] = true;
		del[par] = true;
		c[cur] = 'B';
		c[par] = 'W';
		for(int i=0;i<e[par].size();i++) {
			int nxt = e[par][i];
			sz[nxt] --;
			if(sz[nxt]==1) q[r++] = nxt;
		}
	}
	puts("Second");
	
	return 0;
}