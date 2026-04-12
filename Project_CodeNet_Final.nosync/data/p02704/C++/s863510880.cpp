#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef unsigned long long ull;
int n,s[1010],t[1010],d[1010][1010];
ull mi[70],u[1010],v[1010],U[1010],V[1010],ans[1010][1010];
int ch[10],cl[10],vh[1010],vl[1010],th[1010],tl[1010];
int ph[10],pl[10];
void all(int x) {
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=x;
}
bool solve() {
	if (n==1) {
		if (u[1]!=v[1]) return 0;
		d[1][1]=u[1]; return 1;
	}
	memset(ch,0,sizeof(ch)); memset(cl,0,sizeof(cl));
	memset(vh,0,sizeof(vh)); memset(vl,0,sizeof(vl));
	//for (int i=1;i<=n;i++) printf("%d %d\n",u[i],v[i]);
	for (int i=1;i<=n;i++) {
		if (!s[i]&&u[i]) th[i]=1; if (!t[i]&&v[i]) tl[i]=1;
		if (!s[i]&&!u[i]) th[i]=2; if (!t[i]&&!v[i]) tl[i]=2;
		if (s[i]&&u[i]) th[i]=3; if (t[i]&&v[i]) tl[i]=3;
		if (s[i]&&!u[i]) th[i]=4; if (t[i]&&!v[i]) tl[i]=4;
		ch[th[i]]++; cl[tl[i]]++; ph[th[i]]=i; pl[tl[i]]=i;
		//printf("%d\n",tl[i]);
	}
	//printf("%d %d %d %d\n",ch[1],ch[4],cl[1],cl[4]);
	if (ch[1]+ch[4]>0&&cl[1]+cl[4]>0) {
		if (ch[1]&&cl[1]&&!ch[4]&&!cl[4]) {
			all(0);
			for (int i=1;i<=n;i++) {
				if (th[i]==1) for (int j=1;j<=n;j++) d[i][j]=1;
				if (tl[i]==1) for (int j=1;j<=n;j++) d[j][i]=1;
			}
			return 1;
		}
		if (!ch[1]&&!cl[1]&&ch[4]&&cl[4]) {
			all(1);
			for (int i=1;i<=n;i++) {
				if (th[i]==4) for (int j=1;j<=n;j++) d[i][j]=0;
				if (tl[i]==4) for (int j=1;j<=n;j++) d[j][i]=0;
			}
			return 1;
		}
		return 0;
	}
	bool f1=0,f2=0;
	if (cl[1]+cl[4]>0) {
		f1=1;
		for (int i=1;i<=4;i++) swap(ch[i],cl[i]),swap(ph[i],pl[i]);
		for (int i=1;i<=n;i++) swap(th[i],tl[i]);
	}
	if (ch[1]+ch[4]>0) {
		if (ch[1]&&ch[4]) {
			all(0);
			for (int i=1;i<=n;i++) {
				if (th[i]==1) for (int j=1;j<=n;j++) d[i][j]=1;
				//if (th[i]==4) for (int j=1;j<=n;j++) d[i][j]=0;
				if (th[i]==3) d[i][1]=1;
			}
			if (f1) {
				for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++) swap(d[i][j],d[j][i]);
			}
			return 1;
		}
		
		if (ch[4]) {
			f2=1;
			swap(ch[1],ch[4]); swap(ch[2],ch[3]); swap(cl[1],cl[4]); swap(cl[2],cl[3]);
			swap(ph[1],ph[4]); swap(ph[2],ph[3]); swap(pl[1],pl[4]); swap(pl[2],pl[3]);
			for (int i=1;i<=n;i++) th[i]=5-th[i],tl[i]=5-tl[i];
		}
		all(0);
		for (int i=1;i<=n;i++) if (th[i]==1) {
			for (int j=1;j<=n;j++) d[i][j]=1;
		}
		//for (int i=1;i<=n;i++) printf("%d ",th[i]); printf("\n");
		//for (int i=1;i<=n;i++) printf("%d ",tl[i]); printf("\n");
		if (!cl[2]);
		else if (ch[2]);
		else if (ch[3]>=2) {
			int x=0;
			for (int i=1;i<=n;i++) if (th[i]==3) {
				x++;
				vh[i]=1;
				d[i][x]=1;
				if (x==2) break;
			}
		} else if (ch[3]&&cl[2]<n) {
			//printf("? %d %d\n",ph[3],pl[3]);
			d[ph[3]][pl[3]]=1; vh[ph[3]]=1;
		} else return 0;
		for (int i=1;i<=n;i++) if (!vh[i]) {
			if (th[i]==2);
			if (th[i]==3) d[i][1]=1;
		}
		if (f2) {
			for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]^=1;
		}
		if (f1) {
			for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++) swap(d[i][j],d[j][i]);
		}
		return 1;
	}
	all(0);
	int x,y;
	for (int i=1;i<=n;i++) {
		x=i; if (i==1) y=2; else y=1;
		d[x][y]=u[i];
		if (i==1) x=1; else x=2; y=i;
		d[x][y]=v[i];
	}
	return 1;
	
}
int F(ull x,int i) {
	if (x&mi[i]) return 1;
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1;
	for (int i=1;i<=63;i++) mi[i]=mi[i-1]*2;
	read(n);
	for (int i=1;i<=n;i++) read(s[i]);
	for (int i=1;i<=n;i++) read(t[i]);
	for (int i=1;i<=n;i++) read(U[i]);
	for (int i=1;i<=n;i++) read(V[i]);
	for (int i=0;i<=63;i++) {
		for (int j=1;j<=n;j++) {
			if (U[j]&mi[i]) u[j]=1; else u[j]=0;
			if (V[j]&mi[i]) v[j]=1; else v[j]=0;
		}
		if (!solve()) { printf("-1\n"); return 0; }
		for (int j=1;j<=n;j++)
		for (int k=1;k<=n;k++)
			if (d[j][k]) ans[j][k]+=mi[i];
	}
	//printf("Yes\n"); return 0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%llu ",ans[i][j]);
		printf("\n");
	}
	return 0;
	// test---
	ull x;
	for (int i=1;i<=n;i++) {
		x=ans[i][1];
		for (int j=1;j<=n;j++) {
			if (s[i]) x|=ans[i][j];
			else x&=ans[i][j];
		}
		if (x!=U[i]) {
			printf("WA %d %llu %llu\n",i,x,u[i]);
		}
	}
	for (int i=1;i<=n;i++) {
		x=ans[1][i];
		for (int j=1;j<=n;j++) {
			if (t[i]) x|=ans[j][i];
			else x&=ans[j][i];
		}
		if (x!=V[i]) printf("WA\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/