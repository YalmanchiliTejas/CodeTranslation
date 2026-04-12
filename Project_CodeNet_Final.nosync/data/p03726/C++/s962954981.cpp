#include<cstdio>
#include<cctype>
#include<vector>
#include<cstdlib>
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
const int N=100001;
std::vector<int> e[N];
inline void add_edge(const int &u,const int &v) {
	e[u].push_back(v);
	e[v].push_back(u);
}
inline bool dfs(const int &x,const int &par) {
	int ret=0;
	for(unsigned i=0;i<e[x].size();i++) {
		const int &y=e[x][i];
		if(y==par) continue;
		ret+=dfs(y,x);
		if(ret==2) {
			puts("First");
			exit(0);
		}
	}
	return !ret;
}
int main() {
	const int n=getint();
	for(register int i=1;i<n;i++) {
		add_edge(getint(),getint());
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}