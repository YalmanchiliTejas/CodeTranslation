//Serene
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
#define ll long long
#define db double
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
const int maxn=2e5+7;
int n;

char cc;ll ff;
template<typename T>void read(T& aa) {
	aa=0;ff=1; cc=getchar();
	while(cc!='-'&&(cc<'0'||cc>'9')) cc=getchar();
	if(cc=='-') ff=-1,cc=getchar();
	while(cc>='0'&&cc<='9') aa=aa*10+cc-'0',cc=getchar();
	aa*=ff;
}

int fir[maxn],nxt[2*maxn],to[2*maxn],ind[maxn],e=0;
void add(int x,int y) {
	to[++e]=y;nxt[e]=fir[x];fir[x]=e;++ind[x];
	to[++e]=x;nxt[e]=fir[y];fir[y]=e;++ind[y];
}

int sum[maxn],zz[maxn];
set<int> G;
set<int>::iterator it;
bool init[maxn];
bool solve() {
	if(n==1) return 1;
	int s=1,t=0,x,y,z;
	For(i,1,n) if(ind[i]==1) zz[++t]=i,init[i]=1;
	while(s<=t) {
		G.clear();
		while(s<=t) {
			x=zz[s++];
			for(y=fir[x];y;y=nxt[y]) {
				if(init[z=to[y]]) continue;
				--ind[z]; if(!ind[z]) return 1; 
				if(G.find(z)!=G.end()) return 1;
				G.insert(z);
			}
		}
		for(it=G.begin();it!=G.end();++it) init[*it]=1;
		for(it=G.begin();it!=G.end();++it) {
			x=*it;
			for(y=fir[x];y;y=nxt[y]) {
				if(init[z=to[y]]) continue;
				--ind[z]; if(!ind[z]) return 1;
				if(ind[z]==1) zz[++t]=z;
			}
		}
		For(i,s,t) init[zz[i]]=1;
	}	
	return 0;
}

int main() {
	read(n); int x,y;
	For(i,1,n-1) {
		read(x); read(y);
		add(x,y);
	}
	if(solve()) printf("First\n");
	else printf("Second\n");
	return 0;
}
