#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i=((int)x);i<=((int)y);i++)
#define Dep(i,y,x) for(int i=((int)y);i>=((int)x);i--)
#define Rep(i,x) for (int y,i=head[x];i;i=E[i].nxt)
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;

int rd() {
	char c=getchar(); int t=0,f=1;
	while (!isdigit(c)) f=(c=='-')?-1:1,c=getchar();
	while (isdigit(c)) t=t*10+c-48,c=getchar(); return t*f;
}
void wt(int x) {
	if (x<0) putchar('-'),wt(-x);
	else { if (x>9) wt(x/10); putchar(x%10+48); }
}

const int N=1e6+5;
const int mod=1e9+7;

int n,m,fa[N];

struct Info {
	int x,y,id;
}E[N],P[N];

bool cmpx(Info A,Info B) { return A.x==B.x?A.y<B.y:A.x<B.x; }
bool cmpy(Info A,Info B) { return A.y==B.y?A.x<B.x:A.y<B.y; }
bool cmpid(Info A,Info B) { return A.id<B.id; }

int getf(int x) {
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}

ll kruskal() {
	ll ans=0;
	sort(E+1,E+m+1,cmpid);
	For (i,1,n) fa[i]=i;
	For (i,1,m) {
		int x=getf(E[i].x),y=getf(E[i].y);
		if (x!=y) {
			fa[x]=y;
			ans+=E[i].id;
		}
	}
	return ans;
}

int dis(Info  A,Info B) {
	return min(abs(A.x-B.x),abs(A.y-B.y));
}

int main() {
	n=rd();
	For (i,1,n) P[i]=(Info){rd(),rd(),i};
	sort(P+1,P+n+1,cmpx);
	For (i,2,n) E[++m]=(Info){P[i-1].id,P[i].id,dis(P[i-1],P[i])};
	sort(P+1,P+n+1,cmpy);
	For (i,2,n) E[++m]=(Info){P[i-1].id,P[i].id,dis(P[i-1],P[i])};
	
	printf("%lld\n",kruskal());
}



