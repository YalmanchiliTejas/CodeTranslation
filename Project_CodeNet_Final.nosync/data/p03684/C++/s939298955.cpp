#include <bits/stdc++.h>
struct Istream {
	Istream() {
#ifdef DEBUG
		freopen("input","r",stdin);
#endif
	}
	template <class T> 
	Istream &operator >>(T &x) {
		static char ch;static bool neg;
		for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
		for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
		x=neg?-x:x;
		return *this;
	}
}is;
struct Ostream {
	template <class T>
	Ostream &operator <<(T x) {
		x<0 && (putchar('-'),x=-x);
		static char stack[233];static int top;
		for(top=0;x;stack[++top]=x%10+'0',x/=10);
		for(top==0 && (stack[top=1]='0');top;putchar(stack[top--]));
		return *this;
	}
	Ostream &operator <<(char ch) {
		putchar(ch);
		return *this;
	}
}os;
const int MAXN=1e5+11;
struct Edge {
	int u,v,c;
	Edge(int u,int v,int c):u(u),v(v),c(c) {}
	friend bool operator <(Edge const &a,Edge const &b) {
		return a.c<b.c;
	}
};
int dsu[MAXN];
int Root(int x) {
	return dsu[x]==0?x:dsu[x]=Root(dsu[x]);
}
int main() {
	int n;is>>n;
	static std::pair<int,int> p[MAXN],xi[MAXN],yi[MAXN];
	for(int i=1;i<=n;++i) {
		is>>p[i].first>>p[i].second;
		xi[i]=std::pair<int,int>(p[i].first,i);
		yi[i]=std::pair<int,int>(p[i].second,i);
	}
	std::sort(xi+1,xi+1+n);
	std::sort(yi+1,yi+1+n);
	std::vector<Edge> edges;
	for(int i=1;i<=n-1;++i) {
		edges.push_back(Edge(xi[i].second,xi[i+1].second,xi[i+1].first-xi[i].first));
		edges.push_back(Edge(yi[i].second,yi[i+1].second,yi[i+1].first-yi[i].first));
	}
	std::sort(edges.begin(),edges.end());
	long long Ans=0;
	int cnt=0;
	for(Edge &e : edges) {
		if(Root(e.u)!=Root(e.v)) {
			Ans+=e.c;
			dsu[Root(e.u)]=Root(e.v);
			if(++cnt==n-1) {
				break;
			}
		}
	}
	os<<Ans<<'\n';
	return 0;
}
