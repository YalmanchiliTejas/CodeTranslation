#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=105;

int n,times[maxn];

queue<int> q;

struct trie {
	int son[maxn][26];
	int fail[maxn];
	int l;
	int root;
	int num[maxn];
	int last[maxn];
	inline int index(char c) {
		return c-'A';
	}
	void insert(char *str) {
		int len=strlen(str),cur=0;
		for (register int i=0;i<len;++i) {
			int id=index(str[i]);
			if (!son[cur][id]) {
				son[cur][id]=++l;
			}
			cur=son[cur][id];
		}
		++num[cur];
		return;
	}
	void build(void) {
		for (register int i=0;i<26;++i) {
			if (son[0][i]) {
				fail[son[0][i]]=0;
				q.push(son[0][i]);
			}
		}
		while (!q.empty()) {
			int cur=q.front();
			q.pop();
			for (register int i=0;i<26;++i) {
				if (son[cur][i]) {
					fail[son[cur][i]]=son[fail[cur]][i];
					q.push(son[cur][i]);
				}
				else {
					son[cur][i]=son[fail[cur]][i];
				}
			}
		}
		return;
	}
	int query(char *str) {
		int len=strlen(str),cur=0,ans=0;
		for (register int i=0;i<len;++i) {
			cur=son[cur][index(str[i])];
			for (register int t=cur;t&&~num[t];t=fail[t]) {
				ans+=num[t];
				num[t]=-1;
			}
		}
		return ans;
	}
}ac;

char str[maxn];

int main() {
	str[0]='A';
	str[1]='C';
	ac.insert(str);
	ac.build();
	scanf("%s",str);
	puts(ac.query(str)?"Yes":"No");
	return 0;
}