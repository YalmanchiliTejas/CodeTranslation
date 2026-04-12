#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,in[N],rem[N];
vector <int> e[N];
int dfs(int x,int pre){
	int s=0;
	for (auto y : e[x])
		if (y!=pre){
			if (dfs(y,x))
				return 1;
			s+=rem[y];
		}
	if (s>1)
		return 1;
	rem[x]=!s;
	return 0;
}
int main(){
	n=read();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
		in[a]++,in[b]++;
	}
	if (n==2)
		return puts("Second"),0;
	int rt=0;
	for (int i=1;i<=n;i++)
		if (in[i]>1)
			rt=i;
	puts(dfs(rt,0)?"First":"Second");
	return 0;
}