#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn=2e5+10;

int n;
LL Ans=2e18;
multiset<int> A,B;

struct Point{
	int x,y;
	bool operator < (const Point &p) const {return x<p.x;}
}P[maxn];

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		if (P[i].x>P[i].y) swap(P[i].x,P[i].y);
	}
	sort(P+1,P+n+1);
	for (i=1;i<=n;i++)
		A.insert(P[i].x),B.insert(P[i].y);
	for (i=0;i<n;i++)
	{
		if (i)
		{
			A.erase(A.find(P[i].x));
			B.erase(B.find(P[i].y));
			swap(P[i].x,P[i].y);
			A.insert(P[i].x);
			B.insert(P[i].y);
		}
		int X=*(--A.end())-*A.begin();
		int Y=*(--B.end())-*B.begin();
		Ans=min(Ans,(LL)X*Y);
	}
	printf("%lld\n",Ans);
}
