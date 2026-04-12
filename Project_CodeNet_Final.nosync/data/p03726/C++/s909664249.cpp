#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005;
int vis[N],n;
vector<int> v[N];
void dfs(int p,int fa){
	int sum=0;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs(v[p][i],p);
		sum+=vis[v[p][i]];
	}
	if(sum==0)vis[p]=1; else if(sum>1){
		puts("First"); exit(0);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t);
		v[t].push_back(s);
	}
	dfs(1,0);
	if(vis[1])puts("First"); else puts("Second");
}
