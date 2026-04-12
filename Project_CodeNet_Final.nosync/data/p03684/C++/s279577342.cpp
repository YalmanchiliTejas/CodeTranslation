#include <stdio.h>
#include <algorithm>
using namespace std;

struct pt{
	int i,x,y;
}P[100010];

bool cmpx(const pt& a, const pt& b){return a.x < b.x;}
bool cmpy(const pt& a, const pt& b){return a.y < b.y;}

struct edge{
	int x,y,c;
	bool operator <(const edge &t)const{return c < t.c;}
}E[200020];

int U[100010];
int find(int x)
{
	if (U[x] != x) U[x] = find(U[x]);
	return U[x];
}

int main()
{
	int N;
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d %d",&P[i].x,&P[i].y), P[i].i = i;

	int c = 0;
	sort(P,P+N,cmpx);
	for (int i=1;i<N;i++) E[c++] = {P[i-1].i,P[i].i, min(abs(P[i].x-P[i-1].x),abs(P[i].y-P[i-1].y))};
	sort(P,P+N,cmpy);
	for (int i=1;i<N;i++) E[c++] = {P[i-1].i,P[i].i, min(abs(P[i].x-P[i-1].x),abs(P[i].y-P[i-1].y))};
	sort(E,E+c);

	for (int i=0;i<N;i++) U[i] = i;
	long long ans = 0;
	for (int i=0;i<c;i++){
		int x = find(E[i].x), y = find(E[i].y);
		if (x != y){
			U[x] = y;
			ans += E[i].c;
		}
	}
	printf ("%lld\n",ans);

	return 0;
}