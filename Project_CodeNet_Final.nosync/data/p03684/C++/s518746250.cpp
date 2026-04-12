#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long lld;

struct edg {
	int s, e; lld v;
	bool operator< (const edg& c) const {
		return v<c.v;
	}
} edgs[303030];

int N, xs[101010], ys[101010], ecn;
int xix[101010], yix[101010];
int par[101010]; lld sum;

bool cmp1(const int &x, const int &y){ return xs[x] < xs[y]; }
bool cmp2(const int &x, const int &y){ return ys[x] < ys[y]; }

int root(int ix){
	if(par[ix]<0) return ix;
	return par[ix]=root(par[ix]);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &xs[i], &ys[i]), xix[i]=yix[i]=i;
	sort(xix, xix+N, cmp1);
	sort(yix, yix+N, cmp2);
	for(int i=1; i<N; i++){
		edgs[ecn].s = xix[i-1], edgs[ecn].e = xix[i];
		edgs[ecn++].v = xs[xix[i]]-xs[xix[i-1]];
	}
	for(int i=1; i<N; i++){
		edgs[ecn].s = yix[i-1], edgs[ecn].e = yix[i];
		edgs[ecn++].v = ys[yix[i]]-ys[yix[i-1]];
	}
	sort(edgs, edgs+ecn);

	for(int i=0; i<N; i++)par[i]=-1;
	for(int i=0; i<ecn; i++){
		int s=edgs[i].s, e=edgs[i].e;
		s=root(s), e=root(e);
		if(s==e)continue;
		sum += edgs[i].v;
		par[s]=e;
	}
	printf("%lld", sum);
	return 0;
}
